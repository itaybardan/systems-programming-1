#include "../../include/action.h"
#include "../../include/studio.h"

extern Studio *backup;

BackupStudio::BackupStudio() {

}

void BackupStudio::act(Studio &studio) {
    delete backup;
    backup = new Studio(studio);
    this->complete();
}

std::string BackupStudio::toString() const {
    return "backup";
}

BackupStudio *BackupStudio::parseCommand(std::vector<std::string> &command) {
    return new BackupStudio;
}

BaseAction* BackupStudio::clone() const {
    auto b =  new BackupStudio;
    b->setErrMsg(this->getErrorMsg());
    b->setStatus(this->getStatus());
    return b;
}