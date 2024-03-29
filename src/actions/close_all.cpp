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
    std::cout << "Studio is now closed!" << std::endl;
    this->complete();
}

std::string CloseAll::toString() const {
    return "closeall";
}

CloseAll *CloseAll::parseCommand(std::vector<std::string> &command) {
    return new CloseAll;
}

BaseAction *CloseAll::clone() const {
    auto ca = new CloseAll;
    ca->setStatus(this->getStatus());
    ca->setErrMsg(this->getErrorMsg());
    return ca;
}