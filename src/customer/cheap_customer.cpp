
#include <climits>
#include "../../include/customer.h"

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id),chp(name), id(id) {

}
//not done
std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    int min_id;
    int min_price = INT_MAX;
    for(int i = 0 ; i < static_cast<int>(workout_options.size()) ; i++){
        // always take the smallest ID of the cheapest workout.
        if(min_price > workout_options[i].getPrice())
        {
            min_price = workout_options[i].getPrice();
            min_id = i;
        }
    }
    //return a vector with the cheapest workout.
    orders.push_back(workout_options[min_id].getId());
    return orders;
}

std::string CheapCustomer::toString() const {
    return "I am a cheap customer";
}