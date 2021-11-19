#include "../../include/studio.h"

MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId) {

}

void MoveCustomer::act(Studio &studio) {
    Trainer *origin_trainer = studio.getTrainer(srcTrainer);
    Trainer *dst_trainer = studio.getTrainer(dstTrainer);
    int this_customer_id = id;
    //checks if the origin or the dest trainer's workout session is closed
    //checks if there are such trainers, if don't their id's are greater than the number of trainers.
    //checks if there is such customer in origin trainer workout session.
    //checks if dest trainer capacity is smaller than number of customers + 1 (the customer that moving to his workout session)
    //all this conditions results in error.
    if (!origin_trainer->isOpen() || !dst_trainer->isOpen() || dstTrainer > studio.getNumOfTrainers() ||
        srcTrainer > studio.getNumOfTrainers()
        || origin_trainer->getCustomer(this_customer_id) == nullptr ||
        dst_trainer->getCapacity() < static_cast<int>(dst_trainer->getCustomers().size()) + 1) {
        error("Cannot move customer");
    } else {
        //making a new order for the origin trainer to update his salary, after removing this customer of his customer's list.
        origin_trainer->removeCustomer(this_customer_id);
        Order new_order_for_origin(srcTrainer);
        new_order_for_origin.act(studio);

        //update dest trainer's customers list.
        dst_trainer->addCustomer(dst_trainer->getCustomer(this_customer_id));

        //making a new order for the dest trainer to update his salary, after adding this customer of his customer's list.
        Order new_order_for_dst(dstTrainer);
        new_order_for_dst.act(studio);
    }

    //if there are no customers left in origin trainer workout session, close it.
    if (origin_trainer->getCustomers().empty()){
        origin_trainer->closeTrainer();
    }
}


std::string MoveCustomer::toString() const {
    return "Moved " +std::to_string(id) + " customer from trainer no': " + std::to_string(srcTrainer) +" to trainer no': " +std::to_string(dstTrainer)+".";
}