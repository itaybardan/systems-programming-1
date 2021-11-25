#include "../../include/action.h"
#include "../../include/studio.h"

Close::Close(int id) : trainerId(id) {

}

void Close::act(Studio &studio) {
    Trainer *temp_trainer = studio.getTrainer(trainerId);

    //results in error if:
    //      1. the trainer does not exist.
    //      2. this trainer's workout session is not open.
    if (trainerId > studio.getNumOfTrainers() - 1 || !temp_trainer->isOpen()) {
        error("Trainer does not exist or is not open");
        return;
    }

    //prints: "Trainer 2 closed. Salary 740NIS"
    //print(trainerId,temp_trainer);  A CHANCE TO MAKE PRINT FUNCTION GOT AN ERROR IN THE HEADER FILE.

    //closes this trainer workout session.
    temp_trainer->closeTrainer();

    //removing all of his customers.


    //at the end of this act:
    //      1. customers list of this trainer is empty.
    //      2. open = false.
    //      3. his orders list remaining still so the salary of this trainer is being accumulated.

    //call complete of base action.
    complete();
}

std::string Close::toString() const {
    if (this->getStatus() == ActionStatus::COMPLETED) {
        return "close " + std::to_string(this->trainerId) + " Completed";
    } else {
        return "close " + std::to_string(this->trainerId) + " Error: " + this->getErrorMsg();
    }
}

Close *Close::parseCommand(std::vector<std::string> &command) {
    return new Close(std::stoi(command.at(1)));
}

BaseAction *Close::clone() const {
    auto c = new Close(this->trainerId);
    c->setErrMsg(this->getErrorMsg());
    c->setStatus(this->getStatus());
    return c;
}