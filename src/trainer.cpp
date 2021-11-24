#include "../include/studio.h"
#include <iostream>
#include <algorithm>

Trainer::Trainer(int t_capacity) : capacity(t_capacity) {

}

int Trainer::getCapacity() const {
    return this->capacity;
}

void Trainer::setId(int newId) {
    this->id = newId;
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

    std::cout << "Trainer " + std::to_string(this->id) + " closed. ";
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

void Trainer::orderWithoutPrint(const int customer_id, const std::vector<int> workout_ids,
                                const std::vector<Workout> &workout_options) {
    for (int workoutId: workout_ids) {
        for (Workout workout: workout_options) {
            if (workout.getId() == workoutId) {
                this->orderList.push_back(OrderPair(customer_id, workout));
                break;
            }
        }
    }
}

//Destructor
Trainer::~Trainer() {
    for (Customer *c: this->customersList)
        delete c;
}

//Copy Constructor
Trainer::Trainer(const Trainer &other) : id(other.id), capacity(other.capacity), open(other.open) {
    for (Customer *c : other.customersList) {
        this->customersList.push_back(c->clone());
    }
   this->orderList = other.orderList;
}

//Move Constructor
Trainer::Trainer(Trainer &&other) {
    this->id = other.id;
    this->open = other.open;
    this->capacity = other.capacity;
    this->orderList = other.orderList;
    this->customersList = std::move(other.customersList);
}

//Copy Assignment Operator
Trainer& Trainer::operator=(const Trainer &other) {
    if (this == &other)
        return *this;
    for (int i = 0; i < static_cast<int>(customersList.size()); i++) {
        delete this->customersList[i];
    }
    this->customersList = other.customersList;
    this->orderList = other.orderList;
    this->id = other.id;
    this->capacity = other.capacity;
    this->open = other.open;
}






