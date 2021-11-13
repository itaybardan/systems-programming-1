#include "../include/trainer.h"


Trainer::Trainer(int t_capacity) : open(false), capacity(t_capacity) {

}

//returns a specific trainer capacity.
int Trainer::getCapacity() const {
    return capacity;
}

//adds a given customer to the customers List of a given trainer.
void Trainer::addCustomer(Customer *customer) {
    customersList.push_back(customer);
}

void Trainer::removeCustomer(int id) {

}

Customer *Trainer::getCustomer(int id) {
    return nullptr;
}

std::vector<Customer *> &Trainer::getCustomers() {
    std::vector<Customer *> *empty;
    return *empty;
}

std::vector <OrderPair> &Trainer::getOrders() {
    std::vector<OrderPair> *empty;
    return *empty;
}

void Trainer::order(const int customer_id, const std::vector<int> workout_ids,
                    const std::vector <Workout> &workout_options) {

}

//open a workout session of a given trainer.
//sets open val to true.
void Trainer::openTrainer() {
    open = true;
}

void Trainer::closeTrainer() {

}

int Trainer::getSalary() {
    return -1;
}

//returns the 'flag''s - open status
bool Trainer::isOpen() {
    return open;
}