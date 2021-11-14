#include "../include/trainer.h"

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

Customer *Trainer::getCustomer(int id) {
    return nullptr;
}

std::vector<Customer *> &Trainer::getCustomers() {
    auto *empty = new std::vector<Customer *>();
    return *empty;
}

std::vector <OrderPair> &Trainer::getOrders() {
    auto *empty = new std::vector<OrderPair>();
    return *empty;
}

void Trainer::order(const int customer_id, const std::vector<int> workout_ids,
                    const std::vector <Workout> &workout_options) {

}

void Trainer::openTrainer() {
    open = true;
}

void Trainer::closeTrainer() {

}

int Trainer::getSalary() {
    return -1;
}

bool Trainer::isOpen() {
    return open;
}