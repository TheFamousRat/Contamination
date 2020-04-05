#ifndef AGENTS_H_
#define AGENTS_H_

#include <cmath>
#include <memory>
#include <random>
#include <ctime>

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
        //Générateurs de probabilité d'infection
        static std::default_random_engine generator;
        static std::uniform_real_distribution<double> probaContamination;
    public:
        Agent(Zone* zone_, double x_, double y_, double vx_, double vy_);
		
        double distance(const Agent& ag);
        void afficher();
        void move();
        unsigned int infect_neighbourhood();
        bool isInfected();
        void infecter(bool infec);
        double getX() {return x;};
        double getY() {return y;};
};

void oneDMove(double& pos, double& vel, double maxLength);

#endif