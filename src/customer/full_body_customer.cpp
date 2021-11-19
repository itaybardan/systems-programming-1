#include "../../include/customer.h"
#include <climits>

FullBodyCustomer::FullBodyCustomer(std::string name, int id) : Customer(name, id), fbd(name), id(id) {

}

std::vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    int min_id = INT_MAX;
    int price;
    int min_price = INT_MAX;
    int max_price = INT_MIN;
    bool flag = true;
    int order_index;
    int last_index = static_cast<int>(workout_options.size()) - 1;
    for (int i = last_index; i >= 0; i--) {
        if (workout_options[i].getType() == CARDIO) {
            price = workout_options[i].getPrice();
            // for the first index if its CARDIO
            if (flag) {
                min_id = workout_options[i].getId();
                min_price = workout_options[i].getPrice();
                order_index = i;
                flag = false;
            } else if (min_id < workout_options[i].getId() && price == min_price) {
                min_price = price;
                min_id = workout_options[i].getId();
                order_index = i;
            }
        }
    }
    // pushing the cheapest CARDIO workout.
    orders.push_back(workout_options[order_index].getId());

    //pushing the most expensive MIXED workout.
    min_id = INT_MAX;
    flag = true;
    for (int i = 0; i < static_cast<int>(workout_options.size()); i++) {
        if (workout_options[i].getType() == MIXED) {
            price = workout_options[i].getPrice();
            // for the first index if its MIXED
            if (flag) {
                min_id = workout_options[i].getId();
                max_price = workout_options[i].getPrice();
                order_index = i;
                flag = false;
            } else if (min_id < workout_options[i].getId() && price == max_price) {
                max_price = price;
                min_id = workout_options[i].getId();
                order_index = i;
            }
        }
    }

    //pushing the cheapest ANAEROBIC workout.
    min_id = INT_MAX;
    min_price = INT_MAX;
    flag = true;
    for (int i = last_index; i >= 0; i--) {
        if (workout_options[i].getType() == ANAEROBIC) {
            price = workout_options[i].getPrice();
            // for the first index if its ANAEROBIC
            if (flag) {
                min_id = workout_options[i].getId();
                min_price = workout_options[i].getPrice();
                order_index = i;
                flag = false;
            } else if (min_id < workout_options[i].getId() && price == min_price) {
                min_price = price;
                min_id = workout_options[i].getId();
                order_index = i;
            }
        }
    }
    // pushing the cheapest CARDIO workout.
    orders.push_back(workout_options[order_index].getId());


}

std::string FullBodyCustomer::toString() const {
    return "I am a full body customer";
}