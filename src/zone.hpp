#ifndef ZONE_H_
#define ZONE_H_

#include "agent.hpp"
#include "config.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>

class Chunk {
    //Un chunk est une zone carrée contenant les agents d'une partie de la zone
    private:
        std::vector<Agent*> _agents;
        int x;
        int y;
    public:
        Chunk(int x_, int y_) {x = x_; y = y_;};
        ~Chunk() {};

        std::vector<Agent*> agentsChunk() {return _agents;};
        void ajouterAgent(Agent* ag) {_agents.push_back(ag);};
        void viderChunk() {_agents.clear();};
        unsigned long nombreAgents() {return _agents.size();};

        int getX() {return x;};
        int getY() {return y;};
};

class Zone {
    private:
        unsigned int width;
        unsigned int height; 
        unsigned int nbInfected;
        unsigned int nbStep;
        double tailleChunk;

        bool zoneInit;//Indique si la zone a été initialisées

        Config _config;
        //Vecteur des agents de la zone
        std::vector<std::unique_ptr<Agent>> agents;
        //Chunks de la zone
        std::vector<std::vector<Chunk>> chunks;

        friend class Agent;
    public:
        Zone(unsigned int w, unsigned int h);

        void init();
        void step(bool show);
        void run(unsigned int stepNumber, bool show, bool logToFile);
        void clean();

        //Crée la mappage de la zone en tronçons
        void creerChunks();
        void assignerAgentsChunks();
        //Donne le chunk d'un agent
        Chunk* chunkAgent(Agent* ag);
        //Donne les chunks sensibles d'un agent : le sien et les voisins
        std::vector<Chunk*> chunksSensibles(Agent* ag);

        //Getters et setters
        Config* getConfig() {return &_config;};
        double getWidth() {return width;};
        void setWidth(double newWidth) {width = newWidth;};
        double getHeight() {return height;};
        void setHeight(double newHeight) {height = newHeight;};
};

#endif