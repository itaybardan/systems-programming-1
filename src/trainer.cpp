#include "../include/trainer.h"
#include <iostream>
#include <algorithm>

Trainer::Trainer(int t_capacity) : capacity(t_capacity), open(false), totalSalary(0), currentSessionSalary(0) {
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

void Trainer::removeCustomer(int customerId) {
    this->customersList.erase(std::remove_if(this->customersList.begin(), this->customersList.end(),
                                             [&customerId](const Customer *c) -> bool {
                                                 return c->getId() == customerId;
                                             }),
                              this->customersList.end());
    this->orderList.erase(std::remove_if(this->orderList.begin(), this->orderList.end(),
                                         [&customerId, this](const OrderPair op) -> bool {
                                             if (op.first == customerId) {
                                                 this->currentSessionSalary -= op.second.getPrice();
                                             }
                                             return op.first == customerId;
                                         }),
                          this->orderList.end());
}

Customer *Trainer::getCustomer(int customerId) {
    for (Customer *customer: this->getCustomers()) {
        if (customer->getId() == customerId) {
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
                this->currentSessionSalary += workout.getPrice();
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
    this->totalSalary += this->currentSessionSalary;
    // remove all of this customers
    for (Customer *c: this->customersList) {
        for (OrderPair op: this->orderList) {
            if (c->getId() == op.first) {
                this->currentSessionSalary -= op.second.getPrice();
            }
        }
        delete c;
    }
    this->orderList.clear();
    this->customersList.clear();
    std::cout << "Salary " << std::to_string(this->totalSalary) << "NIS" << std::endl;

}

int Trainer::getSalary() {
    return this->totalSalary + this->currentSessionSalary;
}

int Trainer::getcurrentSessionSalary() {
    return this->currentSessionSalary;
}

bool Trainer::isOpen() {
    return this->open;
}

void Trainer::orderWithoutPrint(const int customer_id, const std::vector<int> workout_ids,
                                const std::vector<Workout> &workout_options) {
    for (int workoutId: workout_ids) {
        for (Workout workout: workout_options) {
            if (workout.getId() == workoutId) {
                this->currentSessionSalary += workout.getPrice();
                this->orderList.push_back(OrderPair(customer_id, workout));
                break;
            }
        }
    }
}


Trainer *Trainer::clone() const {
    Trainer *t = new Trainer(this->capacity);
    t->currentSessionSalary = this->currentSessionSalary;
    t->totalSalary = this->totalSalary;
    t->orderList = this->orderList;
    for (Customer *c: customersList) {
        t->customersList.push_back(c->clone());
    }
    t->id = this->id;
    t->open = this->open;
    return t;
}

//Destructor
Trainer::~Trainer() {
    for (Customer *c: this->customersList)
        delete c;
}

//Copy Constructor
Trainer::Trainer(const Trainer &other) : id(other.id), capacity(other.capacity), open(other.open),
                                         totalSalary(other.totalSalary),
                                         currentSessionSalary(other.currentSessionSalary) {
    for (Customer *c: other.customersList) {
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
    this->currentSessionSalary = other.currentSessionSalary;
    this->totalSalary = other.totalSalary;
}

//Copy Assignment Operator
Trainer &Trainer::operator=(const Trainer &other) {
    if (this == &other) {
        return *this;
    } else {
        for (int i = 0; i < static_cast<int>(customersList.size()); i++) {
            delete this->customersList[i];
        }
        this->customersList = other.customersList;
        this->orderList = other.orderList;
        this->id = other.id;
        this->capacity = other.capacity;
        this->open = other.open;
        this->currentSessionSalary = other.currentSessionSalary;
        this->totalSalary = other.totalSalary;
    }
    return *this;
}

//Move assignment operator
Trainer &Trainer::operator=(const Trainer &&other) {
    if (this != &other) {
        for (int i = 0; i < static_cast<int>(customersList.size()); i++) {
            delete this->customersList[i];
        }
        this->id = other.id;
        this->capacity = other.capacity;
        this->open = other.open;
        this->customersList = other.customersList;
        this->orderList = other.orderList;
        this->currentSessionSalary = other.currentSessionSalary;
        this->totalSalary = other.totalSalary;
    }
    return *this;
}