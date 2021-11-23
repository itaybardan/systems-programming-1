#include "../include/studio.h"
#include "../include/action.h"

#include <iostream>

BaseAction::BaseAction() : errorMsg(), status(ERROR) {

}

BaseAction::~BaseAction() {

}

ActionStatus BaseAction::getStatus() const {
    return this->status;
}

void BaseAction::complete() {
    this->status = ActionStatus::COMPLETED;
}

// change the status to ERROR when an action result in an error.
// and prints the errorMsg given by the user.
void BaseAction::error(std::string errorMessage) {
    this->status = ActionStatus::ERROR;
    this->errorMsg = errorMessage;
    std::cout << "Error: " << errorMsg << std::endl;
}

std::string BaseAction::getErrorMsg() const {
    return errorMsg;
}

void BaseAction::setStatus(ActionStatus as) {
    this->status = as;
}

void BaseAction::setErrMsg(std::string errMsg) {
    this->errorMsg = errMsg;
}




