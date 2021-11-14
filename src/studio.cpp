#include <iostream>
#include <fstream>
#include <cstring>
#include <iterator>
#include <sstream>
#include <string>
#include "../include/studio.h"
#include <tuple>
#include <algorithm>

Studio::Studio(const std::string &configFilePath) : open(false), trainers(*(new std::vector<Trainer *>())),
                                                    workout_options() {
    std::tuple<std::vector<Trainer *>, std::vector<Workout>> configOutput = parseConfigFile(configFilePath);
    this->trainers = std::get<0>(configOutput);
    this->workout_options = std::get<1>(configOutput);
}

void Studio::start() {
    this->open = true;
}

std::tuple<std::vector<Trainer *>, std::vector<Workout>> parseConfigFile(const std::string &configFilePath) {
    std::string configLine;
    std::ifstream configFile(configFilePath);
    int numberOfTrainers = 0;
    auto *trainers = new std::vector<Trainer *>();
    auto workouts = new std::vector<Workout>();

    while (std::getline(configFile, configLine)) {
        if (configLine == "# Number of trainers") {
            while (std::getline(configFile, configLine) && configLine != "\n") {
                configLine.erase(std::remove_if(configLine.begin(), configLine.end(), std::isspace), configLine.end());
                numberOfTrainers = std::stoi(configLine);
            }
        } else if (configLine == "# Traines") {
            while (std::getline(configFile, configLine) && configLine != "\n") {
                std::vector<int> capacitiesOfTrainers;
                std::stringstream stringStream(configLine);
                while (stringStream.good()) {
                    std::string substr;
                    std::getline(stringStream, substr, ',');
                    capacitiesOfTrainers.push_back(std::stoi(substr));
                }

                if (numberOfTrainers != capacitiesOfTrainers.size()) {
                    std::cout << "Problem in the input configurations file. number of trainers does"
                                 " not match number of capacities" << std::endl;
                } else {
                    for (int capacity: capacitiesOfTrainers) {
                        (*trainers).push_back(new Trainer(capacity));
                    }
                }
            }
        } else if (configLine == "# Work Options") {
            while (std::getline(configFile, configLine) && configLine != "\n") {

            }
            std::cout << configLine << std::endl;
        }

    }
    configFile.close();
    return std::make_tuple(*trainers, *workouts);

}

int Studio::getNumOfTrainers() const {
    return static_cast<int>(this->trainers.size());
}

Trainer *Studio::getTrainer(int tid) {
    return this->trainers.at(tid);
}

const std::vector<BaseAction *> &Studio::getActionsLog() const {
    const std::vector<BaseAction *> *empty = new std::vector<BaseAction *>();
    return *empty;
}

std::vector<Workout> &Studio::getWorkoutOptions() {
    std::vector<Workout> *empty = new std::vector<Workout>();
    return *empty;
}