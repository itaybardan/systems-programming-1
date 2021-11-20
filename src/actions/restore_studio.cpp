#include "../../include/action.h"
#include "../../include/studio.h"

extern Studio *backup;

RestoreStudio::RestoreStudio() {
    return;
}

void RestoreStudio::act(Studio &studio) {
    studio = *backup;
}

std::string RestoreStudio::toString() const {
    return std::string();
}

RestoreStudio *RestoreStudio::parseCommand(std::vector<std::string> &command) {
    return new RestoreStudio;
}
