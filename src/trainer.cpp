#include "../include/studio.h"

Trainer::Trainer(int t_capacity) : capacity(t_capacity), open(false) {

}

//returns a given trainer's capacity of available spots
int Trainer::getCapacity() const {
    return capacity;
}

//adss a customer to a given trainer customer's list
void Trainer::addCustomer(Customer *customer) {
    customersList.push_back(customer);
}

//removing a specific customer by ID from a given trainer customer's list
void Trainer::removeCustomer(int id) {
//finding the customer in the vector
std::vector<Customer*> temp_customers_list = this->customersList;
std::vector<Customer*>::iterator where_is_customer;
    for (int i = 0 ; i < static_cast<int>(temp_customers_list.size()) ; i++) {
        if(temp_customers_list[i]->getId() == id){
            where_is_customer = temp_customers_list.begin() + i;
        }
    }
    //erasing the specific customer
    temp_customers_list.erase(where_is_customer);
}

//returns a customer pointer
//not sure if i need to return by pointer or not
Customer *Trainer::getCustomer(int id) {
    for (int i = 0; i < static_cast<int>(customersList.size()); i++) {
        if (id == customersList[i]->getId())
            return customersList[i];
    }
    return nullptr;
}

//return the customer list of a given trainer
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
        orderList.push_back(OrderPair(customer_id, workout_options[workout_ids[i]]));
        //print the order list
        //consider make a function Print in class Order
        std::cout << (getCustomer(customer_id)->getName()) << "Is Doing " << workout_options[i].getName() << std::endl;
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

//returning the sum of prices of workouts being order of a given trainer
int Trainer::getSalary() {
    int salary = 0;
    for(int i = 0 ; i < static_cast<int>(this->orderList.size()) ; i++){
        //iterating over order list of this trainer and sum his workout prices
        salary += orderList[i].second.getPrice();
    }
    return salary;
}

bool Trainer::isOpen() {
    return open;
}