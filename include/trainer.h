#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include "customer.h"
#include "workout.h"

typedef std::pair<int, Workout> OrderPair;

class Trainer {
public:
    Trainer(int t_capacity);

    int getCapacity() const;

    void addCustomer(Customer *customer);

    void removeCustomer(int id);

    Customer *getCustomer(int id);

    std::vector<Customer *> &getCustomers();

    std::vector<OrderPair> &getOrders();

    void order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout> &workout_options);

    void orderWithoutPrint(const int customer_id, const std::vector<int> workout_ids,
                           const std::vector<Workout> &workout_options);

    void openTrainer();

    void setId(int newId);

    void closeTrainer();

    int getSalary();

    bool isOpen();

    //Destructor
    virtual ~Trainer();

    //Copy Constructor
    Trainer(const Trainer& other);

private:
    int id;
    int capacity;
    bool open; //indicates if this trainer has a workout session in progress
    std::vector<Customer *> customersList;
    std::vector<OrderPair> orderList; //A list of pairs for each order for the trainer - (customer_id, Workout)
};


#endif