#ifndef CONFIG_H_
#define CONFIG_H_

class Zone;

class Config {
    public:
        double contaminationDistance = 1;
        unsigned int nbAgents = 10000;
        unsigned int nbInitInfectee = 1;
        double meanVelocity = 1.0;
        double sdVelocity = 0.3;
        double propImmobile = 0.6;
        unsigned int dureeMaxSimulation = 10000;
        
        Zone* currentZone;
        float probaContamination = 0.003;
        /*Résolution du mappage de la zone. Doit être supérieur à sqrt(contaminationDistance)
        L'initialiser à 0 donne le choix de la taille à l'ordinateur. Les performances
        seront meilleures, mais la taille changée manuellement peut correspondre à certains modèles*/
        double tailleTroncons = 0.0;
};

#endif