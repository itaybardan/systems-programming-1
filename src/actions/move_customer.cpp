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
    destTrainer->orderWithoutPrint(customer->getId(), workoutIds, studio.getWorkoutOptions());
    this->complete();
}

std::string MoveCustomer::toString() const {
    if (this->getStatus() == ActionStatus::COMPLETED) {
        return "move " + std::to_string(this->srcTrainer) + " " + std::to_string(this->dstTrainer) + " " +
               std::to_string(this->id) + " Completed";
    } else {
        return "move " + std::to_string(this->srcTrainer) + " " + std::to_string(this->dstTrainer) + " " +
               std::to_string(this->id) + " Error: " + this->getErrorMsg();
    }
}

MoveCustomer *MoveCustomer::parseCommand(std::vector<std::string> &command) {
    return new MoveCustomer(std::stoi(command.at(1)), std::stoi(command.at(2)), std::stoi(command.at(3)));
}


BaseAction *MoveCustomer::clone() const {
    auto m = new MoveCustomer(this->srcTrainer, this->dstTrainer, this->id);
    m->setErrMsg(this->getErrorMsg());
    m->setStatus(this->getStatus());
    return m;
}