#include "../../include/action.h"
#include "../../include/studio.h"

std::map<std::string, int> Order::orderParamNameToIndex = {{"trainerId", 1}};

Order::Order(int id) : trainerId(id) {}

void Order::act(Studio &studio) {
    Trainer *t = studio.getTrainer(this->trainerId);
    if (t == nullptr || !t->isOpen()) {
        this->error("Trainer does not exist or is not open");
        return;
    }
    for (Customer *customer: t->getCustomers()) {
        std::vector<int> workoutIds = customer->order(studio.getWorkoutOptions());
        t->order(customer->getId(), workoutIds, studio.getWorkoutOptions());
    }
    this->complete();
}

std::string Order::toString() const {
    if (this->getStatus() == ActionStatus::COMPLETED) {
        return "order " + std::to_string(this->trainerId) + " Completed";
    } else {
        return "order " + std::to_string(this->trainerId) + " Error: " + this->getErrorMsg();
    }
}

Order *Order::parseCommand(std::vector<std::string> &command) {
    return new Order(std::stoi(command.at(1)));
}