#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <iostream>
#include "customer.h"

enum ActionStatus {
    COMPLETED, ERROR
};

//Forward declaration
class Studio;

class BaseAction {
public:
    BaseAction();

    ActionStatus getStatus() const;

    virtual void act(Studio &studio) = 0;

    virtual std::string toString() const = 0;


protected:
    void complete();

    void error(std::string errorMsg);

    std::string getErrorMsg() const;

private:
    std::string errorMsg;
    ActionStatus status;
};


class OpenTrainer : public BaseAction {
public:
    static std::map<std::string, int> openTrainerParamNameToIndex;

    static OpenTrainer *parseCommand(std::vector<std::string> &command);

    OpenTrainer(int id, std::vector<Customer *> &customersList);

    void act(Studio &studio) override;

    std::string toString() const override;

private:
    const int trainerId;
    std::vector<Customer *> customers;
};


class Order : public BaseAction {
public:
    explicit Order(int id);

    void act(Studio &studio) override;

    std::string toString() const override;

    static std::map<std::string, int> orderParamNameToIndex;

    static Order *parseCommand(std::vector<std::string> &command);

private:
    const int trainerId;
};


class MoveCustomer : public BaseAction {
public:
    MoveCustomer(int src, int dst, int customerId);

    void act(Studio &studio) override;

    std::string toString() const override;

    static MoveCustomer *parseCommand(std::vector<std::string> &command);

private:
    const int srcTrainer;
    const int dstTrainer;
    const int id;
};


class Close : public BaseAction {
public:
    explicit Close(int id);

    void act(Studio &studio) override;

    std::string toString() const override;

    static Close *parseCommand(std::vector<std::string> &command);

private:
    const int trainerId;
};


class CloseAll : public BaseAction {
public:
    CloseAll();

    void act(Studio &studio) override;

    std::string toString() const override;

    static CloseAll *parseCommand(std::vector<std::string> &command);


private:
};


class PrintWorkoutOptions : public BaseAction {
public:
    PrintWorkoutOptions();

    void act(Studio &studio) override;

    std::string toString() const override;

    static PrintWorkoutOptions *parseCommand(std::vector<std::string> &command);

private:
};


class PrintTrainerStatus : public BaseAction {
public:
    explicit PrintTrainerStatus(int id);

    void act(Studio &studio) override;

    std::string toString() const override;

    static PrintTrainerStatus *parseCommand(std::vector<std::string> &command);


private:
    const int trainerId;
};


class PrintActionsLog : public BaseAction {
public:
    PrintActionsLog();

    void act(Studio &studio) override;

    std::string toString() const override;

    static PrintActionsLog *parseCommand(std::vector<std::string> &command);


private:
};


class BackupStudio : public BaseAction {
public:
    BackupStudio();

    void act(Studio &studio) override;

    std::string toString() const override;

    static BackupStudio *parseCommand(std::vector<std::string> &command);


private:
};


class RestoreStudio : public BaseAction {
public:
    RestoreStudio();

    void act(Studio &studio) override;

    std::string toString() const override;

    static RestoreStudio *parseCommand(std::vector<std::string> &command);


};


#endif