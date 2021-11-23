#include "../include/customer.h"

Customer::Customer(std::string c_name, int c_id) : name(c_name), id(c_id) {}

std::vector<int> Customer::order(const std::vector<Workout> &workout_options) {
    return std::vector<int>();
}

std::string Customer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";
}

std::string Customer::getName() const {
    return this->name;
}

int Customer::getId() const {
    return this->id;
}
