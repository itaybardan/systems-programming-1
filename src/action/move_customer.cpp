#include "../../include/studio.h"

MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId) {

}

void MoveCustomer::act(Studio &studio) {
Trainer *origin_trainer = studio.getTrainer(srcTrainer);
Trainer *dst_trainer = studio.getTrainer(dstTrainer);
Customer *temp_customer = origin_trainer->getCustomer(id);

//closes the origin trainer workout session if there are no customers left in his workout session
if(origin_trainer->getCustomers().empty())
    origin_trainer->closeTrainer();
}

std::string MoveCustomer::toString() const {
    return "";
}