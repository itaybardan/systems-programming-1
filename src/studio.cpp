#include "../include/studio.h"

Studio::Studio(const std::string &configFilePath) {
    return;
}

void Studio::start() {

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

std::vector <Workout> &Studio::getWorkoutOptions() {
    std::vector <Workout> *empty = new std::vector<Workout>();
    return *empty;
}