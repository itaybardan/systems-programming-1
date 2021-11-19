#include "../../include/studio.h"

MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId) {

}

void MoveCustomer::act(Studio &studio) {
    Trainer *origin_trainer = studio.getTrainer(srcTrainer);
    Trainer *dst_trainer = studio.getTrainer(dstTrainer);
//    Customer *temp_customer = origin_trainer->getCustomer(id);
    //checks if the origin or the dest trainer's workout session is closed
    //checks if there are such trainers, if don't their id's are greater than the number of trainers.
    //checks if there is such customer in origin trainer workout session.
    //checks if dest trainer capacity is smaller than number of customers + 1 (the customer that moving to his workout session)
    //all this conditions results in error.
    if (!origin_trainer->isOpen() || !dst_trainer->isOpen() || dstTrainer > studio.getNumOfTrainers() ||
        srcTrainer > studio.getNumOfTrainers()
        || origin_trainer->getCustomer(id) == nullptr ||
        dst_trainer->getCapacity() < static_cast<int>(dst_trainer->getCustomers().size()) + 1) {
        error("Cannot move customer");
    }
    else{

            }
        }

    }

//closes the origin trainer workout session if there are no customers left in his workout session
    if (origin_trainer->getCustomers().empty())
        origin_trainer->closeTrainer();

}

std::string MoveCustomer::toString() const {
    return "";
}