#include "../include/studio.h"

Studio::Studio(const std::string &configFilePath) {
    return;
}

void Studio::start() {

}

int Studio::getNumOfTrainers() const {
    return -1;
}

//returns a pointer to the trainer in the vector "trainers".
//assumption: trainers id starts from zero.
Trainer *Studio::getTrainer(int tid) {
    return trainers[tid];
}

const std::vector<BaseAction *> &Studio::getActionsLog() const {
    const std::vector<BaseAction *> *empty = new std::vector<BaseAction *>();
    return *empty;
}

std::vector <Workout> &Studio::getWorkoutOptions() {
    std::vector <Workout> *empty = new std::vector<Workout>();
    return *empty;
}