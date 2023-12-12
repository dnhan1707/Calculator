//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_POSITION_CPP
#define SFML_PROJECT_POSITION_CPP
#include "Position.h"

template<typename T, typename S>
void Position::left(const S& constObject, T& object, float spacing)
{
    sf::FloatRect constBounce = constObject.getGlobalBounds();
    sf::FloatRect objectBounce = object.getGlobalBounds();

    float x = constBounce.left - spacing - objectBounce.width;
    float y = constBounce.top;

    object.setPosition({x, y});
}

template<typename T, typename S>
void Position::right(const S &constObject, T &object, float spacing) {
    sf::FloatRect constBounce = constObject.getGlobalBounds();

    float x = constBounce.left + spacing + constBounce.width;
    float y = constBounce.top;

    object.setPosition({x, y});
}

template<typename T, typename S>
void Position::above(const S &constObject, T &object, float spacing) {
    sf::FloatRect constBounce = constObject.getGlobalBounds();
    sf::FloatRect objectBounce = object.getGlobalBounds();

    float x = constBounce.left;
    float y = constBounce.top - spacing - objectBounce.height;

    object.setPosition({x, y});
}

template<typename T, typename S>
void Position::below(const S &constObject, T &object, float spacing) {
    sf::FloatRect constBounce = constObject.getGlobalBounds();
    sf::FloatRect objectBounce = object.getGlobalBounds();

    float x = constBounce.left;
    float y = constBounce.top + constBounce.height + spacing;

    object.setPosition({x, y});
}

template<typename T>
void Position::centerText(const T &obj, sf::Text &text, float spacing)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}

template<typename T, typename S>
void Position::center(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float xDif = cb.width - ob.width;
    float yDif = cb.height - ob.height;
    float x = cb.left + (xDif/2);
    float y = cb.top + (yDif/2);
    obj.setPosition({x,y});
}

template<typename T, typename S>
void Position::alignCenterAndInside(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    float x = cb.left;
    float y = cb.top;
    obj.setPosition({x,y});
}

template<typename T, typename S>
void Position::alignCenter(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float xDif = cb.width - ob.width;
    float x = cb.left + (xDif/2);
    obj.setPosition({x, 0});
}

template<typename T, typename S>
void Position::alignLeft(const T &constObj, S &obj, float margin_x, float margin_y)
{
    sf::FloatRect cb = constObj.getGlobalBounds();

    float x = cb.left + margin_x;
    float y = cb.top + margin_y;

    obj.setPosition({x, y});
}

template<typename T, typename S>
void Position::belowAndAlignCenterForCircle(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    float x = ((cb.width / 2) - (obj.getRadius() * 4)) + cb.left;
    obj.setPosition({x, cb.height + spacing});
}

template<typename T, typename S>
void Position::belowAndAlignCenterForCircleInObject(const T &constObj, S &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    float x = ((cb.width / 2) - (obj.getRadius() * 4)) + cb.left;
    float y = cb.top + cb.height + spacing;
    obj.setPosition({x, y});
}

template<typename T, typename S>
void Position::centerWithWindow(const T &constObj, S &obj, float spacing)
{
    sf::Vector2u cb = constObj.getSize();
    sf::FloatRect ob = obj.getGlobalBounds();
    float xDif = cb.x - ob.width;
    float yDif = cb.y - ob.height;
    float x = xDif/2;
    float y = yDif/2;
    obj.setPosition({x,y});
}
#endif
