#include "../../include/action.h"

RestoreStudio::RestoreStudio() {
    return;
}

void RestoreStudio::act(Studio &studio) {

}

std::string RestoreStudio::toString() const {
    return std::string();
}

RestoreStudio *RestoreStudio::parseCommand(std::vector<std::string> &command) {
    return new RestoreStudio;
}
