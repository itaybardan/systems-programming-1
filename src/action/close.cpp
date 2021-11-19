#include "../../include/studio.h"

Close::Close(int id) : trainerId(id) {

}

void Close::act(Studio &studio) {
    Trainer *temp_trainer = studio.getTrainer(trainerId);

    //results in error if:
    //      1. the trainer does not exists.
    //      2. this trainer's workout session is not open.
    if (trainerId > studio.getNumOfTrainers() || !temp_trainer->isOpen()) {
        error("Trainer does not exist or is not open");
    }

//prints: "Trainer 'id' close. Salary 'amount'NIS"
    std::cout << "Trainer " << std::to_string(trainerId) << " closed. Salary " << temp_trainer->getSalary() << "NIS";

//closes this trainer workout session.
    temp_trainer->closeTrainer();

    //removing all of his customers.
    int customer_id;
    for (int i = 0; i < static_cast<int>(temp_trainer->getCustomers().size()); i++) {
        customer_id = temp_trainer->getCustomers()[i]->getId();
        temp_trainer->removeCustomer(customer_id);
    }

    //at the end of this act:
    //      1. customers list of this trainer is empty.
    //      2. open = false.
    //      3. his orders list remaining still so the salary of this trainer is being accumulated.

    //call complete of base action.
    complete();
}

std::string Close::toString() const {
    return "Closing a given trainer workout session and prints his current salary";
}