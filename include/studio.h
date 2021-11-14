#ifndef STUDIO_H_
#define STUDIO_H_

#include <vector>
#include <string>
#include "workout.h"
#include "trainer.h"
#include "action.h"


class Studio {
public:
    static std::map<std::string, int> OpenTrainerParamNameToIndex;

    Studio();

    Studio(const std::string &configFilePath);

    void start();

    int getNumOfTrainers() const;

    Trainer *getTrainer(int tid);

    const std::vector<BaseAction *> &getActionsLog() const; // Return a reference to the history of actions
    std::vector<Workout> &getWorkoutOptions();

private:
    bool open;
    std::vector<Trainer *> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction *> actionsLog;
};


std::tuple<std::vector<Trainer *>, std::vector<Workout>> parseConfigFile(const std::string &configFilePath);

std::vector<std::string> *splitByDelimiter(std::string &s, std::string delimiter);

std::map<std::string, int> Studio::OpenTrainerParamNameToIndex = {{"trainerId",     1},
                                                          {"customersList", 2}};

#endif