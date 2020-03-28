
#include "agent.hpp"
#include "zone.hpp"

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

void Agent::infect_neighbourhood()
{

}

bool Agent::isInfected()
{
    return infected;
}

void Agent::infecter(bool infec)
{
    infected = infec;
}