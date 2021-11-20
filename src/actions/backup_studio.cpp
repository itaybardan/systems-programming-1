#include "../../include/action.h"
#include "../../include/studio.h"

extern Studio *backup;

BackupStudio::BackupStudio() {

}

void BackupStudio::act(Studio &studio) {

}

std::string BackupStudio::toString() const {
    return std::string();
}

BackupStudio *BackupStudio::parseCommand(std::vector<std::string> &command) {
    return new BackupStudio;
}