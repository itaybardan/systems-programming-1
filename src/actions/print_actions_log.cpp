#include "../../include/action.h"
#include "../../include/studio.h"

PrintActionsLog::PrintActionsLog() {

}

void PrintActionsLog::act(Studio &studio) {
    for (BaseAction *baseAction : studio.getActionsLog()){
        std::cout << baseAction->toString() << std::endl;
    }
}

std::string PrintActionsLog::toString() const {
    return std::string();
}

PrintActionsLog *PrintActionsLog::parseCommand(std::vector<std::string> &command) {
    return new PrintActionsLog;
}
