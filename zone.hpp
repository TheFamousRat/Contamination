#ifndef ZONE_H_
#define ZONE_H_

#include "agent.hpp"
#include "config.hpp"
#include <iostream>
#include <vector>
#include <random>

class Zone {
    private:
        unsigned int width;
        unsigned int height; 
        unsigned int nbInfected;
        unsigned int nbStep;

        bool zoneInit;//Indique si la zone a été initialisées

        Config _config;
        //Vecteur des agents de la zone
        std::vector<std::unique_ptr<Agent>> agents;
    public:
        Zone(unsigned int w, unsigned int h);

        void init();
        void step(bool show);
        void run(bool show);
        void clean();

        //Getters et setters
        Config* getConfig() {return &_config;};
        double getWidth() {return width;};
        void setWidth(double newWidth) {width = newWidth;};
        double getHeight() {return height;};
        void setHeight(double newHeight) {height = newHeight;};
};

#endif