#include "../../include/action.h"
#include "../../include/studio.h"

MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId) {

}

void MoveCustomer::act(Studio &studio) {
    Trainer *sourceTrainer = studio.getTrainer(this->srcTrainer);
    Trainer *destTrainer = studio.getTrainer(this->dstTrainer);
    Customer *customer = sourceTrainer->getCustomer(this->id);
    if (customer == nullptr || sourceTrainer == nullptr || destTrainer == nullptr || !sourceTrainer->isOpen() ||
        !destTrainer->isOpen() || destTrainer->getCapacity() == static_cast<int>(destTrainer->getCustomers().size())) {
        this->error("Cannot move customer");
        return;
    }
    sourceTrainer->removeCustomer(this->id);
    if (sourceTrainer->getCustomers().size() == 0) {
        sourceTrainer->closeTrainer();
    }
    std::vector<int> workoutIds = customer->order(studio.getWorkoutOptions());
    destTrainer->addCustomer(customer);
    destTrainer->order(customer->getId(), workoutIds, studio.getWorkoutOptions());
    this->complete();
}

std::string MoveCustomer::toString() const {
    return std::string();
}

MoveCustomer *MoveCustomer::parseCommand(std::vector<std::string> &command) {
    return new MoveCustomer(std::stoi(command.at(1)), std::stoi(command.at(2)), std::stoi(command.at(3)));
}
