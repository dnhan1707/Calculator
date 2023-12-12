//
// Created by ASUS on 11/14/2023.
//

#include "Background.h"

Background::Background()
:Background({400, 700})
{

}

Background::Background(sf::Vector2f size)
: sf::RectangleShape(size), States()
{

}

void Background::eventHandler(sf::RenderWindow &window, sf::Event event) {

    if (MouseEvents::isHover(*this, window))
    {
        enableState(HOVERED);

    }
    else disableState(HOVERED);
}

void Background::update() {
    if(getState(HOVERED))
    {
        setFillColor(sf::Color::Blue);
    }
    else setFillColor(sf::Color::White);

}

