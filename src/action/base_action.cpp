#include "../../include/studio.h"
#include <iostream>
//using namespace std;

//Base Action

//empty constructor, initiate status with ERROR
BaseAction::BaseAction():errorMsg("BaseAction Error"),status(ERROR){

}

// getStatus returns the status of the action/
ActionStatus BaseAction::getStatus() const {
    return status;
}

// change the status to COMPLETED when an action has been completed.
void BaseAction::complete() {
    status = COMPLETED;
}

// change the status to ERROR when an action results in an error.
// and prints and errorMsg given by the user.
void BaseAction::error(std::string errorMsg) {
    status = ERROR;
    std::cout << "Error: " << errorMsg << std::endl;
}

//this function returns the error massage.
std::string BaseAction::getErrorMsg() const {
    return errorMsg;
}
