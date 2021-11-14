#include "../../include/action.h"
#include "../../include/trainer.h"
#include "../../include/studio.h"

//OpenTrainer constructor
OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList) : trainerId(id), customers(customersList){

}

void OpenTrainer::act(Studio &studio) {
    Trainer* tempTrainer = studio.getTrainer(trainerId);
    //the if consists of three "ors":
    //check if the trainer's workout session is already open or there exists such trainer
    //or if there is spots in Trainer's capacity.
    if (tempTrainer == nullptr || tempTrainer->isOpen() == true || customers.size() > tempTrainer->getCapacity())
        error("Workout session does not exist or is already open.");
    else{
        //open a workout session.
        tempTrainer->openTrainer();
        //update the customers vector
        for (int (i) = 0 ; (i) < customers.size() ; (i)++) {

        }
        // call the function complete in BaseAction.
        complete();
    }
}

std::string OpenTrainer::toString() const {
    return "Trainer " + toString(trainerId) + " is open and added " + toString(customers.size()) +" customers";

}