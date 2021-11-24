#include "../../include/customer.h"
#include "iostream"
#include <algorithm>

SweatyCustomer::SweatyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    for (Workout workout: workout_options) {
        if (workout.getType() == WorkoutType::CARDIO) {
            orders.push_back(workout.getId());
        }
    }
    std::sort(orders.begin(), orders.end());
    return orders;
}

std::string SweatyCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";

}

Customer *SweatyCustomer::clone() {
    return new SweatyCustomer(this->getName(),this->getId());
}