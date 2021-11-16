#include "../include/studio.h"

//need to implement builder
Trainer::Trainer(int t_capacity) : capacity(t_capacity), open(false) {

}

int Trainer::getCapacity() const {
    return capacity;
}

void Trainer::addCustomer(Customer *customer) {
    customersList.push_back(customer);
}

void Trainer::removeCustomer(int id) {

}

//returns a customer pointer
//not sure if i need to return by pointer or not
Customer *Trainer::getCustomer(int id) {
    int customersListSize = customersList.size();
    for (int i = 0; i < customersListSize; i++) {
        if (id == customersList[i]->getId())
            return customersList[i];
    }
    return nullptr;
}

std::vector<Customer *> &Trainer::getCustomers() {
    return customersList;
}

// returns the order list of a given trainer
std::vector<OrderPair> &Trainer::getOrders() {
    return orderList;
}

void Trainer::order(const int customer_id, const std::vector<int> workout_ids,
                    const std::vector<Workout> &workout_options) {
    for (int i = 0; i < static_cast<int>(workout_ids.size()); i++) {
        //for now its the workout by ID or by workout type (im not sure), will change if needed.
        orderList.push_back(OrderPair(customer_id,workout_options[workout_ids[i]]));
        //print the order list
        //consider make a function Print in class Order
        std::cout << (getCustomer(customer_id)->getName()) << "Is Doing " << workout_options[i].getName() << std::endl;
    }
    //need to delete OrderPairs
}

//opens a workout session of a given trainer
void Trainer::openTrainer() {
    open = true;
}

//closes a workout session of a given trainer
void Trainer::closeTrainer() {
    open = false;
}

int Trainer::getSalary() {
    return -1;
}

bool Trainer::isOpen() {
    return open;
}