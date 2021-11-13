#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/studio.h"

Studio::Studio(const std::string &configFilePath) {
    this->parseConfigFile(configFilePath);
}

void Studio::start() {
    this->open = true;
}

void Studio::parseConfigFile(const std::string &configFilePath) {
    std::string configText;
    std::ifstream configFile(configFilePath);
    while (getline(configFile, configText)) {
        if (configText == "# Number of trainers") {

        }
        else if (configText == "# Work Options") {

        }
        else if (configText == "# Trainees") {
            while (getline(configFile, configText)) {
                configText.
            }
        }
        std::cout << configText << std::endl;
    }
    configFile.close();
}

int Studio::getNumOfTrainers() const {
    return -1;
}

Trainer *Studio::getTrainer(int tid) {
    Trainer *t = new Trainer(tid);
    return t;
}

const std::vector<BaseAction *> &Studio::getActionsLog() const {
    const std::vector<BaseAction *> *empty = new std::vector<BaseAction *>();
    return *empty;
}

std::vector<Workout> &Studio::getWorkoutOptions() {
    std::vector<Workout> *empty = new std::vector<Workout>();
    return *empty;
}