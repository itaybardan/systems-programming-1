#include "../include/trainer.h"

Trainer::Trainer(int t_capacity) {

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