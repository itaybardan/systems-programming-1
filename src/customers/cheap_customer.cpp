#include "../../include/customer.h"

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    return std::vector<int>(workout_options.at(0).getId());
}

std::string CheapCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";

}
