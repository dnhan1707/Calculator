//
// Created by ASUS on 11/14/2023.
//

#ifndef SFML_PROJECT_RPN_H
#define SFML_PROJECT_RPN_H

#include <iostream>
#include <string>
#include "stack"
#include "cmath"
#include "map"
#include "Display.h"

class RPN {
private:
    double evaluate(double left, char op, double right); //string is characters
public:
    static std::string toRPN(const std::string& postfixExpression);
    static double evaluate(const std::string& postfixExpression);
};




#endif //SFML_PROJECT_RPN_H
