#include "../include/trainer.h"

Trainer::Trainer(int t_capacity) : capacity(t_capacity) {

}

int Trainer::getCapacity() const {
    return -1;
}

void Trainer::addCustomer(Customer *customer) {

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

}

void Trainer::closeTrainer() {

}

int Trainer::getSalary() {
    return -1;
}

bool Trainer::isOpen() {
    return false;
}