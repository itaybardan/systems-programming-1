#include "../../include/action.h"
#include "../../include/studio.h"

CloseAll::CloseAll() {

}

void CloseAll::act(Studio &studio) {
    for (Trainer *t: studio.getTrainers()) {
        if (t->isOpen()) {
            t->closeTrainer();
        }
    }
}

std::string CloseAll::toString() const {
    return std::string();
}

CloseAll *CloseAll::parseCommand(std::vector<std::string> &command) {
    return new CloseAll;
}
