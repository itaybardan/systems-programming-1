#include "../../include/customer.h"

Customer::Customer(std::string c_name, int c_id) : name(c_name), id(c_id) {}

std::vector<int> Customer::order(const std::vector <Workout> &workout_options) {
    return std::vector<int>();
}

std::string Customer::toString() const {
    return std::string();
}

std::string Customer::getName() const {
    return std::string();
}

int Customer::getId() const {
    return -1;
}