#include "../../include/action.h"
#include "../../include/studio.h"
#include "../../include/customer.h"

PrintTrainerStatus::PrintTrainerStatus(int id) : trainerId(id) {

}

void PrintTrainerStatus::act(Studio &studio) {
    std::string s;
    Trainer *t = studio.getTrainer(this->trainerId);
    s.append("Trainer " + std::to_string(this->trainerId) + " status:" + std::to_string(t->isOpen()) + "\n");
    if (!t->isOpen()) {
        std::cout << s;
        return;
    }
    s.append("Customers:\n");
    for (Customer *customer: t->getCustomers()) {
        s.append(customer->toString() + "\n");
    }


    s.append("Orders:");
    for (OrderPair orderPair: t->getOrders()) {
        s.append(orderPair.second.getName() + std::to_string(orderPair.second.getPrice()) + std::to_string(orderPair.first) + "\n");
    }

    s.append("Current Trainer’s Salary: " + std::to_string(t->getSalary()) + "\n");
    std::cout << s;
}

std::string PrintTrainerStatus::toString() const {
    return std::string();
}

PrintTrainerStatus *PrintTrainerStatus::parseCommand(std::vector<std::string> &command) {
    return new PrintTrainerStatus(std::stoi(command.at(1)));
}
