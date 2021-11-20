
#include <climits>
#include "../../include/customer.h"

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id), chp(name), id(id) {

}

//not done
std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    int min_id;
    int min_price = INT_MAX;
    int last_index = static_cast<int>(workout_options.size()) - 1;
    bool flag = true;
    int order_index;
    int price = INT_MAX;
    for (int i = last_index; i >= 0; i--) {
        price = workout_options[i].getPrice();
        // for the last index in the vector (the cheapest workout)
        if (flag) {
            min_id = workout_options[i].getId();
            min_price = workout_options[i].getPrice();
            order_index = i;
            flag = false;
        } // we saved the last workout's (the cheapest) price and we compare with the next one to find the min ID
        else if (min_id < workout_options[i].getId() && price == min_price) {
            min_price = price;
            min_id = workout_options[i].getId();
            order_index = i;
        }
    }

    //return a vector with the cheapest workout.
    orders.push_back(workout_options[order_index].getId());
    return orders;
}

std::string CheapCustomer::toString() const {
    return "I am a cheap customer";
}