//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_CALCULATOR_H
#define SFML_PROJECT_CALCULATOR_H

#include "SFML/Graphics.hpp"
#include "Background.h"
#include "RPN.h"
#include "Display.h"
#include "Button.h"
#include "Position.h"
#include "vector"

class Calculator : public sf::Drawable
{
private:
    Background background;
    Display display;

    std::vector<Button> buttons;
    std::string expression;
public:
    Calculator(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void pressButton();

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void setExpression(const std::string& character);
    void resetExpression();
};


#endif //SFML_PROJECT_CALCULATOR_H
