#include "../include/trainer.h"
#include <iostream>

Trainer::Trainer(int t_capacity) : capacity(t_capacity) {

}

int Trainer::getCapacity() const {
    return this->capacity;
}

void Trainer::addCustomer(Customer *customer) {
    this->customersList.push_back(customer);
}

void Trainer::removeCustomer(int id) {

}

Customer *Trainer::getCustomer(int id) {
    for (Customer *customer : this->getCustomers()) {
        if (customer->getId() == id) {
            return *customer;
        }
    }
    return nullptr;
}

std::vector<Customer *> &Trainer::getCustomers() {
    return this->customersList;
}

std::vector<OrderPair> &Trainer::getOrders() {
    return this->orderList;
}

void Trainer::order(const int customer_id, const std::vector<int> workout_ids,
                    const std::vector<Workout> &workout_options) {

}

void Trainer::openTrainer() {
    this->open = true;
}

void Trainer::closeTrainer() {
    std::cout << "Trainer 2 closed. " ;
    std::cout << "Salary "<< this->getSalary() << "NIS" << std::endl;
}

int Trainer::getSalary() {
    return -1;
}

bool Trainer::isOpen() {
    return this->open;
}