#include "../include/workout.h"


Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type) : id(w_id), name(w_name),
                                                                                  price(w_price), type(w_type) {
}

int Workout::getId() const {
    return id;
}

//returns the name of a workout
std::string Workout::getName() const {
    return this->name;
}

int Workout::getPrice() const {
    return price;
}

WorkoutType Workout::getType() const {
    return type;
}

Workout &Workout::operator=(const Workout &other) {
    return *this;
}