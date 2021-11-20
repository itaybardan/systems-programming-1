#include "../include/trainer.h"
#include <iostream>
#include "../include/customer.h"
#include <algorithm>

Trainer::Trainer(int t_capacity) : capacity(t_capacity) {

}

int Trainer::getCapacity() const {
    return this->capacity;
}

void Trainer::addCustomer(Customer *customer) {
    this->customersList.push_back(customer);
}

void Trainer::removeCustomer(int id) {
    this->customersList.erase(std::remove_if(this->customersList.begin(), this->customersList.end(),
                                             [&id](const Customer *c) -> bool { return c->getId() == id; }),
                              this->customersList.end());
    this->orderList.erase(std::remove_if(this->orderList.begin(), this->orderList.end(),
                                         [&id](const OrderPair op) -> bool { return op.first == id; }),
                          this->orderList.end());
}

Customer *Trainer::getCustomer(int id) {
    for (Customer *customer: this->getCustomers()) {
        if (customer->getId() == id) {
            return customer;
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
    // TODO: find what we suppose to do in here.. i used 2 for loops which is naive but it seems strange
    for (int workoutId: workout_ids) {
        Customer *customer = this->getCustomer(customer_id);
        for (Workout workout: workout_options) {
            if (workout.getId() == workoutId) {
                std::cout << customer->getName() + " Is Doing " + workout.getName() << std::endl;
                this->orderList.push_back(OrderPair(customer_id, workout));
                break;
            }
        }
    }
}

void Trainer::openTrainer() {
    this->open = true;
}

void Trainer::closeTrainer() {
    this->open = false;

    std::cout << "Trainer 2 closed. ";
    std::cout << "Salary " << this->getSalary() << "NIS" << std::endl;
}

// TODO: we need to understand if the salary is accumulated over multiple sessions or not
int Trainer::getSalary() {
    int salary = 0;
    for (OrderPair orderPair: this->getOrders()) {
        salary += orderPair.second.getPrice();
    }
    return salary;
}

bool Trainer::isOpen() {
    return this->open;
}