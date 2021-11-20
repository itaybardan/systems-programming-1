#ifndef STUDIO_H_
#define STUDIO_H_

#include <vector>
#include <string>
#include "workout.h"
#include "trainer.h"
#include "action.h"


class Studio {
public:

    Studio();

    explicit Studio(const std::string &configFilePath);

    Studio(Studio &other);

    Studio(Studio &&other);

    void start();

    int getNumOfTrainers() const;

    std::vector<Trainer *> getTrainers();

    Trainer *getTrainer(int tid);

    int getTraineesAvailableId();

    void increaseAvailableId();

    virtual ~Studio();

    virtual Studio &operator=(const Studio &other);

    virtual Studio &operator=(const Studio &&other);

    const std::vector<BaseAction *> &getActionsLog() const; // Return a reference to the history of actions
    std::vector<Workout> &getWorkoutOptions();

private:
    bool open;
    std::vector<Trainer *> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction *> actionsLog;
    int traineesAvailableId = 0;
};


std::tuple<std::vector<Trainer *> *, std::vector<Workout> *> parseConfigFile(const std::string &configFilePath);

std::vector<std::string> *splitByDelimiter(std::string &s, std::string delimiter);


#endif