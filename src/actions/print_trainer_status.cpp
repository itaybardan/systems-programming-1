#include "../../include/action.h"
#include "../../include/studio.h"
#include "../../include/customer.h"

PrintTrainerStatus::PrintTrainerStatus(int id) : trainerId(id) {

}

void PrintTrainerStatus::act(Studio &studio) {
    std::string s;
    Trainer *t = studio.getTrainer(this->trainerId);
    s.append("Trainer " + std::to_string(this->trainerId) + " status: ");
    if (!t->isOpen()) {
        std::cout << s + "closed\n";
        return;
    } else {
        s.append("open\n");
    }
    s.append("Customers:\n");
    for (Customer *customer: t->getCustomers()) {
        s.append(customer->toString());
    }


    s.append("Orders:\n");
    for (OrderPair orderPair: t->getOrders()) {
        s.append(orderPair.second.getName() + " " + std::to_string(orderPair.second.getPrice()) + "NIS " +
                 std::to_string(orderPair.first) + "\n");
    }

    s.append("Current Trainer’s Salary: " + std::to_string(t->getSalary()) + "NIS\n");
    std::cout << s;
    this->complete();
}

std::string PrintTrainerStatus::toString() const {
    return std::string();
}

PrintTrainerStatus *PrintTrainerStatus::parseCommand(std::vector<std::string> &command) {
    return new PrintTrainerStatus(std::stoi(command.at(1)));
}
