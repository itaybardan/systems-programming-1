#include "../../include/action.h"
#include "../../include/studio.h"

PrintActionsLog::PrintActionsLog() {

}

void PrintActionsLog::act(Studio &studio) {
    for (BaseAction *baseAction: studio.getActionsLog()) {
        std::cout << baseAction->toString() << std::endl;
    }
    this->complete();
}

std::string PrintActionsLog::toString() const {
    return "log";
}

PrintActionsLog *PrintActionsLog::parseCommand(std::vector<std::string> &command) {
    return new PrintActionsLog;
}

BaseAction *PrintActionsLog::clone() const {
    auto m = new PrintActionsLog;
    m->setErrMsg(this->getErrorMsg());
    m->setStatus(this->getStatus());
    return m;
}