#include "../../include/action.h"
#include "../../include/studio.h"

PrintWorkoutOptions::PrintWorkoutOptions() {

}

void PrintWorkoutOptions::act(Studio &studio) {
    for (Workout workout: studio.getWorkoutOptions()) {
        std::cout << workout.getName() << ", ";
        std::cout << workout.getType() << ", ";
        std::cout << workout.getPrice() << std::endl;
    }
    this->complete();
}

std::string PrintWorkoutOptions::toString() const {
    return "workout_options";
}

PrintWorkoutOptions *PrintWorkoutOptions::parseCommand(std::vector<std::string> &command) {
    return new PrintWorkoutOptions;
}