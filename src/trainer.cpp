#include "../include/studio.h"

Trainer::Trainer(int t_capacity) : open(false), capacity(t_capacity) {

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
    for (int i = 0; i < customersList.size(); i++) {
        if(id == customersList[i]->getId())
            return customersList[i];
    }
}

std::vector<Customer *> &Trainer::getCustomers() {
    auto *empty = new std::vector<Customer *>();
    return *empty;
}

// returns the order list of a given trainer
std::vector <OrderPair> &Trainer::getOrders() {
    return orderList;
}

void Trainer::order(const int customer_id, const std::vector<int> workout_ids,
                    const std::vector <Workout> &workout_options) {
    for (int i = 0; i < workout_ids ; i++) {
        //for now its the workout by ID or by workout type (im not sure), will change if needed.
        orderList.push_back(std::pair<customer_id,workout_ids[i]);
        std::cout << (getCustomer(customer_id)->getName()) << "Is Doing " << workout_options[i].getType()::endl;
    }
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