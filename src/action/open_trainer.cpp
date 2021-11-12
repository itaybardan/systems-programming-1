#include "../../include/action.h"

OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList) : trainerId(id), customers(customersList) {

}

void OpenTrainer::act(Studio &studio) {

}

std::string OpenTrainer::toString() const {
    return std::string();
}