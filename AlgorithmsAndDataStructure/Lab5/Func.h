#pragma once

#include <string>

bool isOperator(char ch);
bool isOperand(char ch);
bool isOpBrackets(char ch);
bool isClBrackets(char ch);
int precedence(char op);
double operation(double a, double b, char op);
bool canGetNextChar(std::string& expression, char& next);
std::string getNextElement(std::string& expression);
std::string infixToRPN(const std::string& expression);
double RPN(std::string expression);
