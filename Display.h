//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_DISPLAY_H
#define SFML_PROJECT_DISPLAY_H

#include "SFML/Graphics.hpp"
#include "Font.h"
#include "States.h"
#include "Position.h"

class Display : public sf::Drawable, public States
{
private:
    sf::Text text;
    sf::RectangleShape box;

    int limit; //since we have limit for setter setCharacter

    Display(sf::Vector2f display_screen, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit);


public:
    Display();
//    Display(const sf::Text &text);
    Display(sf::Vector2f display_screen, sf::Font& font, unsigned int characterSize);

    void show();
    void clear();
    void setText(const std::string& text);
    std::string getText();
    void setCharacterLimit(int limit);
    void setColor(sf::Color color);
    void setFont(const sf::Font& font);
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setTextPosition(sf::Vector2f position);
    sf::Text& getTextObject();

    void setCharacterSize(unsigned int size);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::RectangleShape& getDisplayBox();
    void update();
};


#endif //SFML_PROJECT_DISPLAY_H
