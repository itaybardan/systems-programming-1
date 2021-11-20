#include "../../include/studio.h"

//an empty constructor
CloseAll::CloseAll() {

}

void CloseAll::act(Studio &studio) {
    int is_close = 0;
    for (int i = 0; i < studio.getNumOfTrainers(); i++) {
        if (!studio.getTrainer(i)->isOpen()) {
            is_close++;
        }
    }
    //if all workout sessions are closed in the studio, the action will just close the studio and exit.
    if (is_close == studio.getNumOfTrainers()) {
        studio.setClose();
        complete();
        return;
    }//else we close each trainer workout session
    else {
        for (int i = 0; i < studio.getNumOfTrainers(); i++) {
            if (studio.getTrainer(i)->isOpen()) {
                //im not sure if i can do this, maybe i need to create new in the heap then delete.
                Close close(i);
                close.act(studio);
            }
        }

        //closes the studio.
        studio.setClose();
        complete();
        return;
    }
}

std::string CloseAll::toString() const {
    return "Closes the studio and exits";
}