#pragma once

#include "robotState.h"
#include <vector>
#include <functional>
#include <unordered_map>
#include <string>


class StateManager
{
    public:
    static StateManager& getInstance();
    void setState(robotState newState);
    robotState getState()const;
    void registerCallback(std::function<void(robotState)> call);
    std::string getStateStr(robotState ns) const;
    

    private:
    std::vector<std::function<void (robotState)>> callbacks;
    robotState currentstate = robotState::INITIALIZING;
    std::unordered_map<robotState, std::vector<robotState>> validTransitions;

    StateManager()
    {
        validTransitions[robotState::INITIALIZING] = {robotState::RUNNING};
        validTransitions[robotState::RUNNING] = {robotState::ERROR, robotState::STOPPED};
        validTransitions[robotState::ERROR] = {robotState::INITIALIZING};
        validTransitions[robotState::STOPPED] = {};
    }
};