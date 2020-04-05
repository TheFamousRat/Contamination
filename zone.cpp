
#include "zone.hpp"

Zone::Zone(unsigned int w, unsigned int h)
{
    width = w;
    height = h;
}

void Zone::init()
{
    nbStep = 0;
    nbInfected = std::min(_config.nbInitInfectee, _config.nbAgents);
    unsigned int nbSains;//Variable utilisée pour créer la population malade
    
    if (nbInfected < 0)
    {
        std::cerr << "Erreur : Nombre d'infectés négatif. Execution poursuivie avec 0 infectés\n";
        nbInfected = 0;
    }
    if (nbInfected == _config.nbAgents)
        std::cout << "Attention : La zone est initialisée avec une population entièrement infectée\n";

    nbSains = _config.nbAgents - nbInfected;
    
    //On initialise les lois de génération aléatoires
    std::default_random_engine generator(time(NULL));
    std::uniform_real_distribution<double> xPos(0.0,width);
    std::uniform_real_distribution<double> yPos(0.0,height); 
    std::uniform_real_distribution<double> angle(0.0, M_PI * 2.0);
    std::normal_distribution<double> vel(_config.meanVelocity, _config.sdVelocity); 
    //On crée les agents, placés aléatoirement avec des vitesses également aléatoires
    for (int i(0) ; i < _config.nbAgents ; i++)
    {
        double velAngle = angle(generator);
        double velNorm = vel(generator);
        agents.push_back(
            std::make_unique<Agent>(
                this,
                xPos(generator),
                yPos(generator),
                cos(velAngle) * velNorm,
                sin(velAngle) * velNorm
            ));    
    }

    //On contamine le bon nombre de patients
    for (int i(0) ; i < nbInfected ; i++) agents[i]->infecter(true);
    std::random_shuffle(agents.begin(), agents.end());

    zoneInit = true;
    creerChunks();
}

void Zone::creerChunks()
{
    if (_config.tailleTroncons <= _config.contaminationDistance / M_SQRT2)
        std::cerr << "Erreur : Résolution trop fine prise pour les tronçons." << 
                    "Correction à une résolution suffisante (" 
                    << _config.contaminationDistance / M_SQRT2 << ")\n"; 
    
    tailleChunk = std::max(_config.contaminationDistance / M_SQRT2, _config.tailleTroncons);

    for (int i(0) ; i < std::ceil(width / tailleChunk) ; i++)
    {
        chunks.push_back(std::vector<Chunk>());
        for (int j(0) ; j < std::ceil(height / tailleChunk) ; j++)
        {
            chunks[i].push_back(Chunk(i,j));
        }
    }
    std::cout << chunks.size() * chunks[0].size() << " tronçons crées\n";

    assignerAgentsChunks();
}

void Zone::assignerAgentsChunks()
{
    /*Assigne les agents à leur chunk*/
    //On vide d'abord les chunks de leurs anciens agents
    for (int i(0) ; i < chunks.size() ; i++)
    {
        for (int j(0) ; j < chunks[i].size() ; j++)
        {
            chunks[i][j].viderChunk();
        }
    }

    //Puis on les réassigne
    for (auto it = agents.begin() ; it != agents.end() ; it++)
    {
        Agent* ag = it->get();
        chunkAgent(ag)->ajouterAgent(ag);
    }
}

void Zone::step(bool show)
{
    unsigned int nbInfectesAvant = nbInfected;
    //On bouge d'abord tous les agents
    for (auto it = agents.begin() ; it != agents.end() ; it++)
    {
        (*it)->move();
    }
    //On remappe correctement les agents
    assignerAgentsChunks();
    //Une fois tous les agents bougés on lance le processus d'infection
    for (auto it = agents.begin() ; it != agents.end() ; it++)
    {
        nbInfected += (*it)->infect_neighbourhood();
    }
    
    if (show)
    {
        std::cout << "============================\n";
        std::cout << "Nouveaux infectés : " << nbInfected - nbInfectesAvant << '\n';
        std::cout << "Nombre total d'infectés : " << nbInfected << '\n';

        for (auto it = agents.begin() ; it != agents.end() ; it++)
        {
            (*it)->afficher();
			std::cout << ',';
		}
		std::cout << '\n';
    }
}

void Zone::run(bool show)
{
    if (!zoneInit) init();

    for (nbStep = 0; nbStep < _config.dureeMaxSimulation ; nbStep++)
    {
        step(show);
    }
}

void Zone::clean()
{
    nbInfected = 0;
    nbStep = 0;

    while (agents.size() > 0) agents.pop_back();

    zoneInit = false;
}

Chunk* Zone::chunkAgent(Agent* ag)
{
    int xChunk = static_cast<int>(std::floor(ag->getX()/tailleChunk));
    int yChunk = static_cast<int>(std::floor(ag->getY()/tailleChunk));
    return &chunks[xChunk][yChunk];
}

std::vector<Chunk*> Zone::chunksSensibles(Agent* ag)
{
    int xChunk = static_cast<int>(std::floor(ag->getX()/tailleChunk));
    int yChunk = static_cast<int>(std::floor(ag->getY()/tailleChunk));
    std::vector<Chunk*> ret;

    for (int i = std::max(0,xChunk-1) ; i <= std::min(int(chunks.size()-1), xChunk+1) ; i++)
    {
        for (int j = std::max(0,yChunk-1) ; j <= std::min(int(chunks[0].size()-1), yChunk+1) ; j++)
        {
            ret.push_back(&chunks[i][j]);
        }
    }

    return ret;
}