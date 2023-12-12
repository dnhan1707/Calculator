//
// Created by ASUS on 11/14/2023.
//

#include "Button.h"

Button::Button()
:Button("0", {80,80,80}, {28, 28, 28})
{

}

Button::Button(const std::string &text, sf::Color color)
:Button(text, 30.f, color, sf::Color::White)
{

}

Button::Button(const std::string &text, sf::Color color, sf::Color textColor)
:Button(text, 30.f, color, textColor)
{

}

Button::Button(const std::string &text, float radius, sf::Color color, sf::Color textColor)
:Button(text, radius, Font::getFont(OPEN_SANS), color, textColor)
{

}

Button::Button(const std::string& text, float radius, sf::Font& font, sf::Color color, sf::Color textColor)
: defaultColor{color}, clickColor{212, 212, 210}
{
    setupCircle(radius);
    setUpText(text, font);
    setTextColor(textColor);

}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!getState(HIDDEN))
    {
        states.transform = circleShape.getTransform();
        window.draw(circleShape);
        window.draw(text, states);
    }

}

void Button::setRadius(float radius) {
    this->circleShape.setRadius(radius);
    setCharacterSize();
    Position::centerText(circleShape, text);
}

void Button::setFont(const sf::Font &font) {
    this->text.setFont(font);
}

void Button::setText(const std::string &text) {

    this->text.setString(text);
    Position::centerText(circleShape, this->text);
}

std::string Button::getText() {
    return text.getString();
}

void Button::setClickColor(sf::Color color) {
    this->clickColor = color;
}

void Button::setDefaultColor(sf::Color color) {
    this->defaultColor = color;
}

void Button::setPosition(sf::Vector2f position)
{
    this->circleShape.setPosition(position);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isCLicked(circleShape, window))
    {
        enableState(CLICK);
    }
    else {
        disableState(CLICK);
    }
}

sf::CircleShape& Button::getButton()
{
    return this->circleShape;
}

void Button::setupCircle(float radius)
{
    setRadius(radius);
    circleShape.setFillColor(defaultColor);
}

void Button::setUpText(const std::string &text, sf::Font &font)
{
    this->text.setFont(font);
    this->text.setString(text);
    setCharacterSize();
    Position::centerText(circleShape, this->text);
}

void Button::update() {
    if(getState(CLICK))
    {
        circleShape.setFillColor(clickColor);
    }
    else circleShape.setFillColor(defaultColor);
}

void Button::setCharacterSize() {
    float size = (2.f/3) * (2 * circleShape.getRadius());
    this->text.setCharacterSize(size);
}

void Button::setTextColor(sf::Color color) {
    text.setFillColor(color);
}
