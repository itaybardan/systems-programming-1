#include "../../include/customer.h"

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    return std::vector<int>();
}

std::string CheapCustomer::toString() const {
    return {};
}
