#ifndef CONFIG_H_
#define CONFIG_H_

class Zone;

class Config {
    public:
        double contaminationDistance = 1;
        unsigned int nbAgents = 10;
        unsigned int nbInitInfectee = 1;
        double meanVelocity = 1.0;
        double sdVelocity = 0.3;
        double propImmobile = 0.6;
        unsigned int dureeMaxSimulation = 10000;
        Zone* currentZone;
};

#endif