#include "../../include/customer.h"

FullBodyCustomer::FullBodyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
    auto *empty = new std::vector<int>();
    return *empty;
}

std::string FullBodyCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";

}
