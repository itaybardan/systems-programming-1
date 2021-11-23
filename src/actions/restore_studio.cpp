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
    backup = nullptr;
    this->complete();
}

std::string RestoreStudio::toString() const {
    return "restore";
}

RestoreStudio *RestoreStudio::parseCommand(std::vector<std::string> &command) {
    return new RestoreStudio;
}

BaseAction *RestoreStudio::clone() const {
    auto m = new RestoreStudio;
    m->setErrMsg(this->getErrorMsg());
    m->setStatus(this->getStatus());
    return m;
}