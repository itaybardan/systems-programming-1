#include "../../include/customer.h"

SweatyCustomer::SweatyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {
    auto *empty = new std::vector<int>();
    return *empty;
}

std::string SweatyCustomer::toString() const {
    return std::string();
}
