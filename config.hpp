#ifndef CONFIG_H_
#define CONFIG_H_

class Zone;

class Config {
    public:
        double contaminationDistance = 1;
        unsigned int nbAgents = 1000;
        unsigned int nbInitInfectee = 1;
        double meanVelocity = 1.0;
        double sdVelocity = 0.3;
        double propImmobile = 0.6;
        unsigned int dureeMaxSimulation = 10000;
        
        Zone* currentZone;
        float probaContamination = 0.3333;
        double tailleTroncons = 2.0;//Résolution du mappage de la zone. Doit être supérieur à sqrt(contaminationDistance)
};

#endif