#ifndef WORKOUT_H_
#define WORKOUT_H_

#include <string>
#include <map>

enum WorkoutType {
    ANAEROBIC, MIXED, CARDIO
};


class Workout {
public:
    static std::map <std::string, WorkoutType> WorkoutTypeResolver;

    Workout(int w_id, std::string w_name, int w_price, WorkoutType w_type);

    int getId() const;

    std::string getName() const;

    int getPrice() const;

    WorkoutType getType() const;

    Workout &operator=(const Workout &other);

    bool operator<(const Workout &other) const;

private:
    const int id;
    const std::string name;
    const int price;
    const WorkoutType type;
};

#endif