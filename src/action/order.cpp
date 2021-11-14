#include "../../include/studio.h"

//order constructor
Order::Order(int id) : trainerId(id) {

}

void Order::act(Studio &studio) {
    // a variable pointer of Trainer class to get his id
    Trainer *tempTrainer = studio.getTrainer(trainerId);
    //check if there exists a trainer or if the workout session of a given trainer is open
    if (tempTrainer == nullptr || tempTrainer->isOpen() == false) {
        error("Trainer does not exist or is not open");
    } else {
        //taking orders from each customer
        for (int i = 0; i < tempTrainer->getCustomers().size(); i++) {
            tempTrainer->order(tempTrainer->getCustomers()[i]->getId(),
                               tempTrainer->getCustomers()[i]->order(studio.getWorkoutOptions()),
                               studio.getWorkoutOptions())

        }
    }



    //call complete function of BaseAction
    complete()
}

}

std::string Order::toString() const {
    return std::string();
}