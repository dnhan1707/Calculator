//
// Created by ASUS on 11/14/2023.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LAST_STATE; ++i)
    {
        states[static_cast<StateEnum>(i)] = false;
    }
}

void States::disableState(StateEnum state) {
    states[state] = false;
}

void States::enableState(StateEnum state) {
    states[state] = true;
}

void States::toggleState(StateEnum state) {
    states[state] = !states[state];
}

bool States::getState(StateEnum state) const {
    return states.at(state);
}
