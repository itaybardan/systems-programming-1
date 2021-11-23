#include "../../include/action.h"
#include "../../include/studio.h"

extern Studio *backup;

RestoreStudio::RestoreStudio() {
    return;
}

void RestoreStudio::act(Studio &studio) {
    if (backup == nullptr) {
        this->error("No backup available");
        return;
    }
    studio = *backup;
    this->complete();
}

std::string RestoreStudio::toString() const {
    return "restore";
}

RestoreStudio *RestoreStudio::parseCommand(std::vector<std::string> &command) {
    return new RestoreStudio;
}
