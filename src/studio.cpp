#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include "../include/studio.h"
#include <tuple>
#include <algorithm>


std::map<std::string, int> Studio::OpenTrainerParamNameToIndex = {{"trainerId",     1},
                                                                  {"customersList", 2}};

Studio::Studio(const std::string &configFilePath) : open(false), trainers(*(new std::vector<Trainer *>())),
                                                    workout_options() {
    std::tuple<std::vector<Trainer *>, std::vector<Workout>> configOutput = parseConfigFile(configFilePath);
    this->trainers = std::get<0>(configOutput);
    this->workout_options = std::get<1>(configOutput);
}

void Studio::start() {
    this->open = true;
    std::cout << "Studio is now open" << std::endl;
    std::string inputLine;
    std::cin >> inputLine;
    while (inputLine != "closeall") {
        std::vector<std::string> *action = splitByDelimiter(inputLine, " ");
        std::string mainAction = action->at(0);
        if (mainAction == "open") {
            //int id = std::stoi(action->at(OpenTrainerParamNameToIndex.find("trainerId")->second));
            std::vector<std::string> *customersInfo = splitByDelimiter(
                    reinterpret_cast<std::string &>(Studio::OpenTrainerParamNameToIndex.find(
                            "customersList")->second), " ");
            std::vector<Customer *> customers;
            int customerIdCounter = 0;
            for (std::string customerInfo: *customersInfo) {
                std::vector<std::string> *customerInfoVector = splitByDelimiter(customerInfo, ",");
                if (customerInfoVector->at(1) == "swt") {
                    //customers.push_back(new SweatyCustomer(customerInfoVector->at(0), customerIdCounter));
                    customerIdCounter++;
                }
                delete customerInfoVector;
            }
            delete customersInfo;
        } else if (mainAction == "order") { ;

        } else if (mainAction == "close") { ;

        } else if (mainAction == "move") { ;

        } else if (mainAction == "status") { ;

        } else if (mainAction == "backup") { ;

        } else if (mainAction == "log") { ;

        }

        delete action;
    }

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
                std::vector<std::string> *splitResults = splitByDelimiter(configLine, ",");

                if (numberOfTrainers != static_cast<int>(splitResults->size())) {
                    std::cout << "Problem in the input configurations file. number of trainers does"
                                 " not match number of capacities" << std::endl;
                } else {
                    for (const std::string &capacity: (*splitResults)) {
                        trainers->push_back(new Trainer(std::stoi(capacity)));
                    }
                }
                delete splitResults;
            }
        } else if (configLine == "# Work Options") {
            std::vector<std::array<std::string, 3>> workoutsAttributes;
            while (std::getline(configFile, configLine) && !configLine.empty()) {
                std::array<std::string, 3> workoutAttributes;
                std::stringstream stringStream(configLine);
                std::vector<std::string> *splitResults = splitByDelimiter(configLine, ", ");
                for (int i = 0; i < static_cast<int>(workoutAttributes.size()); i++) {
                    workoutAttributes[i] = (*splitResults).at(i);
                }
                workoutsAttributes.push_back(workoutAttributes);
                delete splitResults;
            }
            int id = 0;
            for (std::array<std::string, 3> workoutAttributes: workoutsAttributes) {
                std::transform(workoutAttributes[1].begin(), workoutAttributes[1].end(), workoutAttributes[1].begin(),
                               [](unsigned char c) { return std::tolower(c); });
                workouts->push_back(*(new Workout(id, workoutAttributes[0], std::stoi(workoutAttributes[2]),
                                                  Workout::WorkoutTypeResolver.find(workoutAttributes[1])->second)));
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

std::vector<std::string> *splitByDelimiter(std::string &s, std::string delimiter) {
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