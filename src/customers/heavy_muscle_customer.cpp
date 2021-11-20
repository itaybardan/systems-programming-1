#include "../../include/customer.h"

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id) {

}


std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    auto *empty = new std::vector<int>();
    return *empty;
}

std::string HeavyMuscleCustomer::toString() const {
    return std::string();
}
