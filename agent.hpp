#ifndef AGENTS_H_
#define AGENTS_H_

#include <cmath>
#include <memory>

class Zone;

class Agent {
    private:
        //Coordonnées de l'agent
        double x;
        double y;
        //Elements du vecteur de vélocité
        double vx;
        double vy;
        //L'agent est-il infecté ?
        bool infected;
        //Zone actuelle
        Zone* zone;
    public:
        Agent(Zone* zone_, double x_, double y_, double vx_, double vy_);

        double distance(const Agent& ag);
        void afficher();
        void move();
        void infect_neighbourhood();
        bool isInfected();
        void infecter(bool infec);
};

void oneDMove(double& pos, double& vel, double maxLength);

#endif