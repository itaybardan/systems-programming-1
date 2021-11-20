#include "../../include/action.h"
#include "../../include/trainer.h"
#include "../../include/studio.h"

std::map<std::string, int> OpenTrainer::openTrainerParamNameToIndex = {{"trainerId",     1},
                                                                       {"customersList", 2}};


OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList) : trainerId(id), customers(customersList) {

}

void OpenTrainer::act(Studio &studio) {
    Trainer *t = studio.getTrainer(this->trainerId);

    if (t == nullptr || t->isOpen()) {
        this->error("Workout session does not exist or is already open.");
        return;
    }
    t->openTrainer();
    int placesLeft = t->getCapacity() - static_cast<int>(t->getCustomers().size());
    for (Customer *customer: this->customers) {
        if (placesLeft <= 0) {
            break;
        }
        t->addCustomer(customer);
        placesLeft--;
    }

    this->complete();
}

std::string OpenTrainer::toString() const {
    return {};
}

OpenTrainer *OpenTrainer::parseCommand(std::vector<std::string> &command) {
    int trainerIdParam = std::stoi(command.at(OpenTrainer::openTrainerParamNameToIndex.find("trainerId")->second));
    std::vector<std::string> *customersInfo = splitByDelimiter(
            command.at(OpenTrainer::openTrainerParamNameToIndex.find("customersList")->second), " ");
    auto *customersVector = new std::vector<Customer *>;
    int customerIdCounter = 0;
    for (std::string customerInfo: *customersInfo) {
        std::vector<std::string> *customerInfoVector = splitByDelimiter(customerInfo, ",");
        if (customerInfoVector->at(1) == "swt") {
            auto *customer = new SweatyCustomer(customerInfoVector->at(0), customerIdCounter);
            customersVector->push_back(customer);
        } else if (customerInfoVector->at(1) == "chp") {
            auto *customer = new CheapCustomer(customerInfoVector->at(0), customerIdCounter);
            customersVector->push_back(customer);
        } else if (customerInfoVector->at(1) == "mcl") {
            auto *customer = new HeavyMuscleCustomer(customerInfoVector->at(0), customerIdCounter);
            customersVector->push_back(customer);
        } else if (customerInfoVector->at(1) == "fbd") {
            auto *customer = new FullBodyCustomer(customerInfoVector->at(0), customerIdCounter);
            customersVector->push_back(customer);
        } else {
            std::cout << "Unknown customer type: " << customerInfoVector->at(1) << std::endl;
        }

        customerIdCounter++;
        delete customerInfoVector;
    }
    delete customersInfo;
    auto *openTrainer = new OpenTrainer(trainerIdParam, *customersVector);
    delete customersVector;
    return openTrainer;
}