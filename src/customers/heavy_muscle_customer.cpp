#include "../../include/customer.h"
#include "../../include/workout.h"

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id) {

}


std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    // iterate workout options in reverse order
    for (int i = workout_options.size() - 1; i >= 0; i--) {
        Workout workout = workout_options.at(i);
        if (workout.getType() == WorkoutType::ANAEROBIC) {
            orders.push_back(workout.getId());
        }
    }
    return orders;
}


std::string HeavyMuscleCustomer::toString() const {
    return std::to_string(this->getId()) + " " + this->getName() + "\n";
}
