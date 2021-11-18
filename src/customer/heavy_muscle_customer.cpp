
#include "../../include/customer.h"

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id), mcl(name), id(id) {

}

std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    std::vector<Workout> temp_workout_options = workout_options;
    for (int i = 0; i < static_cast<int>(workout_options.size()); i++) {
        if (workout_options[i].getType() == ANAEROBIC) {
            //the workouts are sorted by price from the most expensive to the cheapest
            //therefore its ok to push right away.
            orders.push_back(workout_options[i].getId());
        }
    }

return orders;
}


std::string HeavyMuscleCustomer::toString() const {
    return "Im a Heavy Muscle Customer";
}

