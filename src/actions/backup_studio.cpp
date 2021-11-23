#include "../../include/action.h"
#include "../../include/studio.h"

extern Studio *backup;

BackupStudio::BackupStudio() {

}

void BackupStudio::act(Studio &studio) {
    // we need to implement rule of 5 in studio class in order for this line to work
    *backup = studio;
    this->complete();
}

std::string BackupStudio::toString() const {
    return "backup";
}

BackupStudio *BackupStudio::parseCommand(std::vector<std::string> &command) {
    return new BackupStudio;
}