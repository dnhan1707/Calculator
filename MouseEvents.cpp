//
// Created by ASUS on 11/16/2023.
//

#ifndef SFML_PROJECT_MOUSEEVENTS_CPP
#define SFML_PROJECT_MOUSEEVENTS_CPP

#include "MouseEvents.h"

namespace MouseEvents {
    template<typename T>

    bool isHover(const T& obj, sf::RenderWindow& window)
    {
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
        return obj.getGlobalBounds().contains(mpos);
    }

    template<typename T>

    bool isCLicked(const T& obj, sf::RenderWindow& window)
    {
        return isHover(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
};


#endif