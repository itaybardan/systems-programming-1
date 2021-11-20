#include "../include/workout.h"


std::map<std::string, WorkoutType> Workout::WorkoutTypeResolver = {{"anaerobic", WorkoutType::ANAEROBIC},
                                                                   {"mixed",     WorkoutType::MIXED},
                                                                   {"cardio",    WorkoutType::CARDIO}};

Workout::Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type) : id(w_id), name(w_name),
                                                                                  price(w_price), type(w_type) {
    return;
}

int Workout::getId() const {
    return this->id;
}

std::string Workout::getName() const {
    return this->name;
}

int Workout::getPrice() const {
    return this->price;
}

WorkoutType Workout::getType() const {
    return this->type;
}

Workout &Workout::operator=(const Workout &other) {
    // Guard self assignment
    if (this == &other)
        return *this;

    return *this;
}

bool Workout::operator<(const Workout &other) const {
    return this->price < other.price;
}