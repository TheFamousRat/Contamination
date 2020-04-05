
#include "agent.hpp"
#include "zone.hpp"

//On initialise les générateurs de probabilités d'infection
std::default_random_engine Agent::generator = std::default_random_engine(time(NULL));
std::uniform_real_distribution<double> Agent::probaContamination = std::uniform_real_distribution<double>(0.0,1.0);

Agent::Agent(Zone* zone_, double x_, double y_, double vx_, double vy_)
{
    zone = zone_;
    x = x_;
    y = y_;
    vx = vx_;
    vy = vy_;

    infected = false;
}

double Agent::distance(const Agent& ag)
{
    return sqrt(pow(ag.x - x, 2.0) + pow(ag.y - y, 2.0));
}

void Agent::afficher()
{
    //Affiche une étoile si le patient est infecté, puis sa position
    std::cout << (infected ? "*" : "") << '(' << x << ';' << y << ')';
}

void Agent::move()
{
    oneDMove(x, vx, zone->getWidth());
    oneDMove(y, vy, zone->getHeight());
}

void oneDMove(double& pos, double& vel, double maxLength)
{
    /*Bouge un point sur un vecteur d'une dimension. 
    Prend en compte les rebonds, et oppose la vitesse si nécessaire
    */
    pos = fmod(pos + vel, 2.0*maxLength);

    if (pos < 0.0)
    {
        pos = -pos;
        vel = -vel;
    }
    else if (pos > maxLength)
    {
        pos = 2.0*maxLength - pos;
        vel = -vel;
    }
}

unsigned int Agent::infect_neighbourhood()
{
    //Nombre de nouveaux infectés après l'execution de cette fonction
    unsigned int nvInfectes = 0;

    if (isInfected())
    {
        std::vector<Chunk*> chunkSensibles = zone->chunksSensibles(this);
        for (auto itChunks = chunkSensibles.begin() ; itChunks != chunkSensibles.end() ; itChunks++)
        {
            Chunk* chunk = *itChunks;
            //std::cout << chunk->getX() << ';' << chunk->getY() <<  ',' << chunk->nombreAgents() <<'\n';
            for (int i(0) ; i < chunk->agentsChunk().size() ; i++)
            {
                Agent* ag = chunk->agentsChunk()[i];
                //On n'itère que sur les agents sains
                if (!ag->isInfected())
                {
                    if (distance(*ag) <= zone->_config.contaminationDistance
                        && Agent::probaContamination(Agent::generator) <= zone->_config.probaContamination)
                    {
                        nvInfectes += 1;
                        ag->infecter(true);
                    }
                }
            }
        }
    }

    return nvInfectes;
}

bool Agent::isInfected()
{
    return infected;
}

void Agent::infecter(bool infec)
{
    infected = infec;
}