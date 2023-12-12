//
// Created by ASUS on 11/14/2023.
//

#include "Calculator.h"

Calculator::Calculator(sf::RenderWindow& window)
{
    background.setSize({300, 450});
    background.setFillColor(sf::Color{28, 28, 28});

    ///Position background
    Position::centerWithWindow(window, background);

    ///Position display
    Position::alignCenterAndInside(background, display.getDisplayBox());

    display.setSize({300, 100});
    display.setColor(sf::Color{28, 28, 28});
    display.setText("0");


    sf::Color lightgrey = sf::Color{187,187,185};
    sf::Color darkLiver = sf::Color{80, 80, 80};
    sf::Color orange = sf::Color{255, 149, 0};


    Button zero("0", darkLiver);
    Button one("1", darkLiver);
    Button two("2", darkLiver);
    Button three("3", darkLiver);
    Button four("4", darkLiver);
    Button five("5", darkLiver);
    Button six("6", darkLiver);
    Button seven("7", darkLiver);
    Button eight("8", darkLiver);
    Button nine("9", darkLiver);
    Button plus("+", orange);
    Button minus("-", orange);
    Button mult("*", orange);
    Button div("/", orange);
    Button equal("=", orange);
    Button allClear("AC", lightgrey, sf::Color{28, 28, 28});
    Button mod("%", lightgrey, sf::Color{28, 28, 28});
    Button negative_positive("+/-", lightgrey, sf::Color{28, 28, 28});
    Button dot(".", darkLiver);


    buttons = {allClear, negative_positive, mod, div, seven, eight, nine, mult, four, five, six, minus, one, two, three, plus, zero, dot, equal};
    /// Position button
    Position::belowAndAlignCenterForCircleInObject(display.getDisplayBox(), buttons[0].getButton());

    /// Position text in Display
    sf::FloatRect display_bounce = display.getDisplayBox().getGlobalBounds();
    float button_rad = buttons[0].getButton().getRadius();
    float margin_x = (display_bounce.width/ 2) - (button_rad * 4);

    Position::alignLeft(display.getDisplayBox(), display.getTextObject(), margin_x, margin_x);
    for (int i = 1; i < 20; i++) {
        if (i == 4 || i == 8 || i == 12 || i == 16)
        {
            Position::below(buttons[i - 4].getButton(), buttons[i].getButton());
        }
        else
        {
            Position::right(buttons[i-1].getButton(), buttons[i].getButton());
        }
    }
}

void Calculator::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(display);
    for (int i = 0; i < 19; ++i) {
        window.draw(buttons[i]);
    }
}

//void Calculator::pressButton()
//{
//    for (int i = 0; i < 19; ++i) {
//        if (buttons[i].getState(CLICK)) {
//            std::string buttonText = buttons[i].getText();
//            display.setText(buttonText);
//        }
//    }
//
//}


void Calculator::eventHandler(sf::RenderWindow &window, sf::Event event) {
    std::cout.setf(std::ios::showpoint);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    for (int i = 0; i < 19; i++) {
        buttons[i].eventHandler(window, event);
        buttons[i].update();
        if (buttons[i].getState(CLICK)) {
            std::string buttonText = buttons[i].getText();
            if (buttonText == "=")
            {
                if (expression.length() > 2)
                {
                    double res = RPN::evaluate(RPN::toRPN(expression));
                    display.setText(std::to_string(res));
                    resetExpression();
                }
                else display.setText(expression);
            }
            else if(buttonText == "AC")
            {
                resetExpression();
                display.setText("0");
            }
            else {
                setExpression(buttonText);
                display.setText(expression);
            }
        }
    }
}

void Calculator::setExpression(const std::string& character)
{
    expression += character;
}

void Calculator::resetExpression() {
    expression = "";
}
