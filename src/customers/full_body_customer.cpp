#include "../../include/customer.h"

FullBodyCustomer::FullBodyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    for (Workout workout : workout_options) {
        if (workout.getType() == WorkoutType::CARDIO) {
            orders.push_back(workout.getId());
            break;
        }
    }
    for (int i = workout_options.size() - 1; i >= 0; i--) {
        Workout workout = workout_options.at(i);
        if (workout.getType() == WorkoutType::MIXED) {
            orders.push_back(workout.getId());
            break;
        }
    }
    for (Workout workout : workout_options) {
        if (workout.getType() == WorkoutType::ANAEROBIC) {
            orders.push_back(workout.getId());
            break;
        }
    }
    return orders;
}

std::string FullBodyCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";

}
