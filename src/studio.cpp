#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "../include/studio.h"
#include <algorithm>


Studio::Studio(const std::string &configFilePath) : open(false) {
    std::tuple<std::vector<Trainer *> *, std::vector<Workout> *> configOutput = parseConfigFile(configFilePath);
    this->trainers = *std::get<0>(configOutput);
    this->workout_options = *std::get<1>(configOutput);
    std::copy(this->workout_options.begin(), this->workout_options.end(),
              std::back_inserter(this->workoutOptionsSortedByPrice));
    std::sort(this->workoutOptionsSortedByPrice.begin(), this->workoutOptionsSortedByPrice.end());
    std::sort(this->workout_options.begin(), this->workout_options.end());


}

void Studio::start() {
    this->open = true;
    std::cout << "Studio is now open" << std::endl;
    std::string inputLine;
    getline(std::cin, inputLine);
    while (inputLine != "closeall") {
        std::vector<std::string> *action = splitByDelimiter(inputLine, " ");
        std::string mainAction = action->at(0);
        BaseAction *baseAction;
        if (mainAction == "open") {
            baseAction = OpenTrainer::parseCommand(*action, this);
        } else if (mainAction == "order") {
            baseAction = Order::parseCommand(*action);
        } else if (mainAction == "close") { ;
            baseAction = Close::parseCommand(*action);
        } else if (mainAction == "move") { ;
            baseAction = MoveCustomer::parseCommand(*action);
        } else if (mainAction == "status") { ;
            baseAction = PrintTrainerStatus::parseCommand(*action);
        } else if (mainAction == "backup") { ;
            baseAction = BackupStudio::parseCommand(*action);
        } else if (mainAction == "log") { ;
            baseAction = PrintActionsLog::parseCommand(*action);
        } else {
            std::cout << "Unknown command name: " << mainAction << std::endl;
            getline(std::cin, inputLine);
            continue;
        }
        baseAction->act(*this);
        this->actionsLog.push_back(baseAction);
        getline(std::cin, inputLine);
    }
    CloseAll closeAll;
    closeAll.act(*this);

}

std::tuple<std::vector<Trainer *> *, std::vector<Workout> *> parseConfigFile(const std::string &configFilePath) {
    std::string configLine;
    std::ifstream configFile(configFilePath);
    int numberOfTrainers = 0;
    auto trainers = new std::vector<Trainer *>;
    auto workouts = new std::vector<Workout>;

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
    return std::make_tuple(trainers, workouts);

}

int Studio::getNumOfTrainers() const {
    return static_cast<int>(this->trainers.size());
}

Trainer *Studio::getTrainer(int tid) {
    try {
        return this->trainers.at(tid);
    } catch (const std::out_of_range &oor) {
        return nullptr;
    }
}

const std::vector<BaseAction *> &Studio::getActionsLog() const {
    return this->actionsLog;
}

std::vector<Workout> &Studio::getWorkoutOptions() {
    return this->workout_options;
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

Studio::Studio() {}


std::vector<Trainer *> Studio::getTrainers() {
    return this->trainers;
}

int Studio::getTraineesAvailableId() {
    return this->traineesAvailableId;
}

void Studio::increaseAvailableId() {
    this->traineesAvailableId++;
}