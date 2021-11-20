#include "../../include/action.h"
#include "../../include/studio.h"

Close::Close(int id) : trainerId(id) {

}

void Close::act(Studio &studio) {
    Trainer *t = studio.getTrainer(this->trainerId);
    if (!t->isOpen() || t == nullptr) {
        this->error("Trainer does not exist or is not open");
        return;
    }
    t->closeTrainer();

}

std::string Close::toString() const {
    return std::string();
}

Close *Close::parseCommand(std::vector<std::string> &command) {
    return new Close(std::stoi(command.at(1)));
}
