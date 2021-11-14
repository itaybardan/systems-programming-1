#ifndef WORKOUT_H_
#define WORKOUT_H_

#include <string>
#include <map>

enum WorkoutType {
    ANAEROBIC, MIXED, CARDIO
};

const std::map<std::string, WorkoutType> WorkoutTypeResolver = {{"anaerobic", WorkoutType::ANAEROBIC},
                                                                {"mixed",     WorkoutType::MIXED},
                                                                {"cardio",    WorkoutType::CARDIO}};


class Workout {
public:
    Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type);

    int getId() const;

    std::string getName() const;

    int getPrice() const;

    WorkoutType getType() const;

    Workout &operator=(const Workout &other);

private:
    const int id;
    const std::string name;
    const int price;
    const WorkoutType type;
};


#endif