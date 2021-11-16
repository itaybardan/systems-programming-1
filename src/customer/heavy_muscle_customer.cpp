#include <algorithm>
#include <climits>
#include "../../include/customer.h"

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id), mcl(name), id(id) {

}
//NOT DONE
std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    std::vector<int> orders;
    //making a vector of ID's and Prices [i|p|i|p|i|p...]
    for (int i = 0; i < static_cast<int>(workout_options.size()); i++) {
        if (workout_options[i].getType() == ANAEROBIC) {
            orders.push_back(workout_options[i].getId());
            orders.push_back(workout_options[i].getPrice());
        }
    }
    //inserting only the prices
//    for (int i = 1; i < static_cast<int>(pre_orders.size()); i+=2) {







return orders;
}
