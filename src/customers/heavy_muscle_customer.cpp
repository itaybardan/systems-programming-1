#include "../../include/customer.h"
#include "../../include/workout.h"
#include "algorithm"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "../include/studio.h"
#include <algorithm>
#include <iterator>

typedef std::pair<int, int> WorkoutPair;

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id) {

}


std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<std::pair<int, int>> orderPairs;
    // iterate workout options in reverse order
    for (int i = workout_options.size() - 1; i >= 0; i--) {
        Workout workout = workout_options.at(i);
        if (workout.getType() == WorkoutType::ANAEROBIC) {
            orderPairs.push_back(std::make_pair(workout.getId(), workout.getPrice()));
        }
    }
    std::sort(orderPairs.begin(), orderPairs.end(), [](std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    });

    std::vector<int> orders;
    for (std::pair<int, int> orderPair : orderPairs) {
        orders.push_back(orderPair.first);
    }
    return orders;
}


std::string HeavyMuscleCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";
}

Customer *HeavyMuscleCustomer::clone() const {
    return new CheapCustomer(this->getName(), this->getId());
}