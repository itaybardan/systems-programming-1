#include "../../include/customer.h"

FullBodyCustomer::FullBodyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    int cheapestCardioWorkoutId = -1;
    int minPrice = INT8_MAX;
    for (Workout workout : workout_options) {
        if (workout.getType() == WorkoutType::CARDIO) {
            if (workout.getPrice() < minPrice) {
                cheapestCardioWorkoutId = workout.getId();
                minPrice = workout.getPrice();
            }
        }
    }
    orders.push_back(cheapestCardioWorkoutId);

    int maxPrice = INT8_MIN;
    int mostExpensiveMixedWorkout = -1;
    for (int i = workout_options.size() - 1; i >= 0; i--) {
        Workout workout = workout_options.at(i);
        if (workout.getType() == WorkoutType::MIXED) {
            if (workout.getPrice() > maxPrice) {
                mostExpensiveMixedWorkout = workout.getId();
                maxPrice = workout.getPrice();
            }
        }
    }
    orders.push_back(mostExpensiveMixedWorkout);

    minPrice = INT8_MAX;
    int cheapestAnaerobicId = -1;
    for (Workout workout : workout_options) {
        if (workout.getType() == WorkoutType::ANAEROBIC) {
            if (workout.getPrice() < minPrice) {
                cheapestAnaerobicId = workout.getId();
                minPrice = workout.getPrice();
            }
        }
    }
    orders.push_back(cheapestAnaerobicId);

    return orders;
}

std::string FullBodyCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";
}
