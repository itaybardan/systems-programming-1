#include "../../include/action.h"

BaseAction::BaseAction() {

}

ActionStatus BaseAction::getStatus() const {
    ActionStatus* as = new ActionStatus();
    return *as;
}

void BaseAction::act(Studio &studio){

}

std::string BaseAction::toString() const {
    return std::string();
}

void BaseAction::complete() {

}

void BaseAction::error(std::string errorMsg) {

}

std::string BaseAction::getErrorMsg() const {
    return std::string();
}