#include "../include/workout.h"


Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type) : id(w_id), name(w_name),
                                                                                  price(w_price), type(w_type) {
    return;
}

int Workout::getId() const {
    return -1;
}

std::string Workout::getName() const {
    return std::string();
}

int Workout::getPrice() const {
    return -1;
}

WorkoutType Workout::getType() const {
    WorkoutType *empty = new WorkoutType();
    return *empty;
}

Workout &Workout::operator=(const Workout &other) {
    return *this;
}