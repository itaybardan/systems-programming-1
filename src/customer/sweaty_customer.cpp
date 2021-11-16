#include "../../include/customer.h"

SweatyCustomer::SweatyCustomer(std::string name, int id) : Customer(name, id), swt(name) ,id(id){

}

std::vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    //this customer orders all of CARDIO workouts.
    for ( int i = 0 ; i < static_cast<int>(workout_options.size()) ; i++){
        if (workout_options[i].getType() == CARDIO){
            orders.push_back(workout_options[i].getId());
        }
    }
    return orders;
}

std::string SweatyCustomer::toString() const {
    return "I am a sweaty customer"
}
