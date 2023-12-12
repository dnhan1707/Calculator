//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H

#include "iostream"
#include "map"
#include "StateEnum.h"

class States
{
private:
    std::map<StateEnum, bool> states;

public:
    States();
    void disableState(StateEnum state);
    void enableState(StateEnum state);
    void toggleState(StateEnum state);
    bool getState(StateEnum state) const;
};


#endif //SFML_PROJECT_STATES_H
