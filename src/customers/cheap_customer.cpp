#include "../../include/customer.h"

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    int minPrice = INT8_MAX;
    int cheapestWorkoutId;
    for (Workout workout: workout_options) {
        if (workout.getPrice() < minPrice) {
            cheapestWorkoutId = workout.getId();
            minPrice = workout.getPrice();
        }
    }
    return {cheapestWorkoutId};

}

std::string CheapCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";

}
