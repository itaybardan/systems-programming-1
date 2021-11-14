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
    auto trainers = new std::vector<Trainer *>();
    auto workouts = new std::vector<Workout>();

    while (std::getline(configFile, configLine)) {
        if (configLine == "# Number of trainers") {
            while (std::getline(configFile, configLine) && !configLine.empty()) {
                numberOfTrainers = std::stoi(configLine);
            }
        } else if (configLine == "# Traines") {
            while (std::getline(configFile, configLine) && !configLine.empty()) {
                std::vector<int> capacitiesOfTrainers;
                std::stringstream stringStream(configLine);
                std::string delimiter = ",";
                std::vector<std::string> *splitResults = splitByDelimiter(configLine, delimiter);

                if (numberOfTrainers != static_cast<int>(splitResults->size())) {
                    std::cout << "Problem in the input configurations file. number of trainers does"
                                 " not match number of capacities" << std::endl;
                } else {
                    for (const std::string& capacity: (*splitResults)) {
                        trainers->push_back(new Trainer(std::stoi(capacity)));
                    }
                }
            }
        } else if (configLine == "# Work Options") {
            std::vector<std::array<std::string, 3>> workoutsAttributes;
            while (std::getline(configFile, configLine) && !configLine.empty()) {
                std::array<std::string, 3> workoutAttributes;
                std::stringstream stringStream(configLine);
                std::string delimiter = ", ";
                std::vector<std::string> *splitResults = splitByDelimiter(configLine, delimiter);
                for (int i = 0; i < static_cast<int>(workoutAttributes.size()); i++) {
                    workoutAttributes[i] = (*splitResults).at(i);
                }
                workoutsAttributes.push_back(workoutAttributes);
            }
            int id = 0;
            for (std::array<std::string, 3> workoutAttributes: workoutsAttributes) {
                std::transform(workoutAttributes[1].begin(), workoutAttributes[1].end(), workoutAttributes[1].begin(),
                               [](unsigned char c) { return std::tolower(c); });
                workouts->push_back(*(new Workout(id, workoutAttributes[0], std::stoi(workoutAttributes[2]),
                                                  WorkoutTypeResolver.find(workoutAttributes[1])->second)));
                id++;
            }
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

std::vector<std::string> *splitByDelimiter(std::string &s, std::string &delimiter) {
    size_t pos = 0;
    std::string substr;
    auto *result = new std::vector<std::string>();
    while ((pos = s.find(delimiter)) != std::string::npos) {
        substr = s.substr(0, pos);
        result->push_back(substr);
        s.erase(0, pos + delimiter.length());
    }
    result->push_back(s);
    return result;
}