#include "../../include/action.h"

MoveCustomer::MoveCustomer(int src, int dst, int customerId) : srcTrainer(src), dstTrainer(dst), id(customerId) {

}

void MoveCustomer::act(Studio &studio) {

}

std::string MoveCustomer::toString() const {
    return std::string();
}