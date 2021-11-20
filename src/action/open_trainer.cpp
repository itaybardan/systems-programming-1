#include "../../include/action.h"
#include "../../include/trainer.h"
#include "../../include/studio.h"

std::map<std::string, int> OpenTrainer::openTrainerParamNameToIndex = {{"trainerId",     1},
                                                                       {"customersList", 2}};


OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList) : trainerId(id), customers(customersList) {

}

void OpenTrainer::act(Studio &studio) {

}

std::string OpenTrainer::toString() const {
    return {};
}

OpenTrainer *OpenTrainer::parseCommand(std::vector<std::string> &command) {
    int trainerId = std::stoi(command.at(OpenTrainer::openTrainerParamNameToIndex.find("trainerId")->second));
    std::vector<std::string> *customersInfo = splitByDelimiter(
            command.at(OpenTrainer::openTrainerParamNameToIndex.find("customersList")->second), " ");
    auto *customers = new std::vector<Customer *>;
    int customerIdCounter = 0;
    for (std::string customerInfo: *customersInfo) {
        std::vector<std::string> *customerInfoVector = splitByDelimiter(customerInfo, ",");
        if (customerInfoVector->at(1) == "swt") {
            auto *customer = new SweatyCustomer(customerInfoVector->at(0), customerIdCounter);
            customers->push_back(customer);
            customerIdCounter++;
        }
        delete customerInfoVector;
    }
    delete customersInfo;
    auto *openTrainer = new OpenTrainer(trainerId, *customers);
    delete customers;
    return openTrainer;
}