#include "state/stateManager.h"
#include <algorithm>
#include "logging/logger.h"

StateManager &StateManager::getInstance()
{
    static StateManager instance;
    return instance;
}

void StateManager::setState(robotState newState)
{
    auto& allowed = validTransitions[currentstate];
    if(std::find(allowed.begin(), allowed.end(), newState) != allowed.end())
    {
        currentstate = newState;
        Logger::getInstance().log(logLevel::INFO,"State Changed to: " + getStateStr(newState));
        for(const auto& callback : callbacks)
        {
            callback(newState);
        }
    }
    else{
        Logger::getInstance().log(logLevel::WARNING,"Invalid Transition from: " 
                                    + getStateStr(currentstate) + " to " + getStateStr(newState) );
    }
}

robotState StateManager::getState()const
{
    return currentstate;
}

void StateManager::registerCallback(std::function<void(robotState)> cb)
{
    callbacks.emplace_back(cb);
}

std::string StateManager::getStateStr(robotState ns) const
{
    switch (ns)
    {
    case robotState::INITIALIZING : return "INITIALIZING";
    case robotState::RUNNING : return "RUNNING";
    case robotState::ERROR : return "ERROR";
    case robotState::STOPPED : return "STOPPED";
    default:                   return "UNKNOWN";
    }
}