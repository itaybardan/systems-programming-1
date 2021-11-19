#include "../../include/customer.h"

Customer::Customer(std::string c_name, int c_id) : name(c_name), id(c_id) {

}

//returns the name of a given customer
std::string Customer::getName() const {
    return name;
}

//returns the ID of a given customer
int Customer::getId() const {
    return id;
}


