//
// Created by ASUS on 11/16/2023.
//

#ifndef SFML_PROJECT_MOUSEEVENTS_H
#define SFML_PROJECT_MOUSEEVENTS_H

#include "SFML/Graphics.hpp"
namespace MouseEvents
{
    template<typename T>
    bool isHover(const T& obj, sf::RenderWindow& window);

    template<typename T>
    bool isCLicked(const T& obj, sf::RenderWindow& window);

} // MouseEvents

#include "MouseEvents.cpp"
#endif //SFML_PROJECT_MOUSEEVENTS_H
