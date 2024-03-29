#include "../../include/action.h"
#include "../../include/trainer.h"
#include<algorithm>
#include <utility>
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
        if (placesLeft > 0) {
            t->addCustomer(customer->clone());
        }
        else {
            studio.decreaseAvailableId();
        }
        placesLeft--;
    }

    this->complete();
}

std::string OpenTrainer::toString() const {
    if (this->getStatus() == ActionStatus::COMPLETED) {
        return "open " + std::to_string(this->trainerId) + " " + this->arguments + " Completed";
    } else {
        return "open " + std::to_string(this->trainerId) + " " + this->arguments + " Error: " + this->getErrorMsg();
    }
}

/**
 * @param command a vector split by spaces representing the input line from the user
 * @return OpenTrainer object
 */
OpenTrainer *OpenTrainer::parseCommand(std::vector<std::string> &command, Studio *studio) {
    int trainerIdParam = std::stoi(command.at(OpenTrainer::openTrainerParamNameToIndex.find("trainerId")->second));
    Trainer *t = studio->getTrainer(trainerIdParam);

    auto *customersInfo = new std::vector<std::string>(
            command.begin() + OpenTrainer::openTrainerParamNameToIndex.find("customersList")->second,
            command.end());
    std::string argumentsLog;
    std::for_each(customersInfo->begin(), customersInfo->end(),
                  [&](const std::string &piece) { argumentsLog += piece + " "; });
    argumentsLog.pop_back();
    if (t == nullptr) {
        auto *op = new OpenTrainer(trainerIdParam, *(new std::vector<Customer *>));
        op->setArguments(argumentsLog);
        return op;
    }
    int placesLeft = t->getCapacity() - static_cast<int>(t->getCustomers().size());


    auto *customersVector = new std::vector<Customer *>;
    for (std::string customerInfo: *customersInfo) {
        if (placesLeft <= 0 || t->isOpen()) {
            break;
        }
        std::vector<std::string> *customerInfoVector = splitByDelimiter(customerInfo, ",");
        if (customerInfoVector->at(1) == "swt") {
            auto *customer = new SweatyCustomer(customerInfoVector->at(0), studio->getTraineesAvailableId());
            studio->increaseAvailableId();
            customersVector->push_back(customer);
        } else if (customerInfoVector->at(1) == "chp") {
            auto *customer = new CheapCustomer(customerInfoVector->at(0), studio->getTraineesAvailableId());
            studio->increaseAvailableId();
            customersVector->push_back(customer);
        } else if (customerInfoVector->at(1) == "mcl") {
            auto *customer = new HeavyMuscleCustomer(customerInfoVector->at(0), studio->getTraineesAvailableId());
            studio->increaseAvailableId();
            customersVector->push_back(customer);
        } else if (customerInfoVector->at(1) == "fbd") {
            auto *customer = new FullBodyCustomer(customerInfoVector->at(0), studio->getTraineesAvailableId());
            studio->increaseAvailableId();
            customersVector->push_back(customer);
        } else {
            std::cout << "Unknown customer type: " << customerInfoVector->at(1) << std::endl;
        }
        placesLeft--;
        delete customerInfoVector;
    }
    auto *openTrainer = new OpenTrainer(trainerIdParam, *customersVector);
    openTrainer->setArguments(argumentsLog);
    delete customersInfo;
    delete customersVector;
    return openTrainer;
}

BaseAction *OpenTrainer::clone() const {
    std::vector<Customer *> customersList;
    // We use clone on OpenTrainer only for actionLog, in that matter we don't need to store the customers.
    // just maintain the toString method
    for (Customer *c: this->customers) {
        customersList.push_back(c->clone());
    }

    auto *op = new OpenTrainer(this->trainerId, customersList);
    op->setArguments(this->arguments);
    op->setStatus(this->getStatus());
    op->setErrMsg(this->getErrorMsg());
    return op;
}

void OpenTrainer::setArguments(std::string argumentsParam) {
    this->arguments = std::move(argumentsParam);
}


OpenTrainer::OpenTrainer(const OpenTrainer &other) : BaseAction(other), trainerId(other.trainerId) {
    for (Customer *c: other.customers) {
        this->customers.push_back(c->clone());
    }
}

OpenTrainer::OpenTrainer(OpenTrainer &&other) noexcept: BaseAction(other), trainerId(other.trainerId),
                                                        customers(std::move(other.customers)) {

}

OpenTrainer::~OpenTrainer() {
    for (Customer *c: this->customers) {
        delete c;
    }
}

void OpenTrainer::clear() {
    for (Customer *c: this->customers) {
        delete c;
    }
}

OpenTrainer &OpenTrainer::operator=(const OpenTrainer &other) {
    if (this == &other) {
        return *this;
    }
    this->clear();
    // because of const constraint, create a copy of open trainer
    *this = OpenTrainer(other);
    return *this;
}

OpenTrainer &OpenTrainer::operator=(OpenTrainer &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    this->clear();
    // because of const constraint, create a copy of open trainer
    *this = OpenTrainer(other);
    return *this;
}