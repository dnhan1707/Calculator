#include "SFML/Graphics.hpp"

#include "Calculator.h"

int main() {
    sf::RenderWindow window({1000, 1000, 32}, "Calculator");
    window.setFramerateLimit(60);


    Calculator calculator(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                window.close();
            }
            calculator.eventHandler(window, event);
        }
        window.clear();
        window.draw(calculator);
        window.display();
    }

    return 0;
}
