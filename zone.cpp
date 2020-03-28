
#include "zone.hpp"

Zone::Zone(unsigned int w, unsigned int h)
{
    width = w;
    height = h;
}

void Zone::init()
{
    nbStep = 0;
    nbInfected = _config.nbInitInfectee;
    unsigned int nbSains;//Variable utilisée pour créer la population malade
    
    if (nbInfected >= _config.nbAgents)
    {
        std::cout << "Attention : La zone est initialisée avec une population entièrement infectée\n";
        nbSains = 0;
    }
    else
    {
        nbSains = _config.nbAgents - nbInfected;
    }
    
    //On initialise les lois de génération aléatoires
    std::default_random_engine generator(time(NULL));
    std::uniform_real_distribution<double> pos(0.0,1.0); 
    std::normal_distribution<double> vel(_config.meanVelocity, _config.sdVelocity); 
    //On crée les agents, placés aléatoirement avec des vitesses également aléatoires
    for (int i(0) ; i < _config.nbAgents ; i++)
    {
        agents.push_back(
            std::make_unique<Agent>(
                this,
                width * pos(generator),
                height * pos(generator),
                vel(generator),
                vel(generator)
            ));    
    }

    //On contamine le bon nombre de patients
    for (int i(0) ; i < nbInfected ; i++) agents[i]->infecter(true);

    zoneInit = true;
}

void Zone::step(bool show)
{
    //On bouge d'abord tous les agents
    for (auto it = agents.begin() ; it != agents.end() ; it++)
    {
        (*it)->move();
    }
    for (auto it = agents.begin() ; it != agents.end() ; it++)
    {
        (*it)->infect_neighbourhood();
    }
    if (show)
    {
        for (auto it = agents.begin() ; it != agents.end() ; it++)
        {
            (*it)->afficher();
        }
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