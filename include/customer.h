#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>
#include "workout.h"

class Customer {
public:
    Customer(std::string c_name, int c_id);

    virtual ~Customer();

    virtual std::vector<int> order(const std::vector<Workout> &workout_options) = 0;

    virtual std::string toString() const = 0;

    std::string getName() const;

    int getId() const;

    virtual Customer *clone() const = 0;

private:
    const std::string name;
    const int id;
};


class SweatyCustomer : public Customer {
public:
    SweatyCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Workout> &workout_options) override;

    std::string toString() const override;

    Customer *clone() const override;

private:
};


class CheapCustomer : public Customer {
public:
    CheapCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Workout> &workout_options) override;

    std::string toString() const override;

    Customer *clone() const override;

private:
};


class HeavyMuscleCustomer : public Customer {
public:
    HeavyMuscleCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Workout> &workout_options) override;

    std::string toString() const override;

    Customer *clone() const override;

private:
};


class FullBodyCustomer : public Customer {
public:
    FullBodyCustomer(std::string name, int id);

    std::vector<int> order(const std::vector<Workout> &workout_options) override;

    std::string toString() const override;

    Customer *clone() const override;

private:
};


#endif