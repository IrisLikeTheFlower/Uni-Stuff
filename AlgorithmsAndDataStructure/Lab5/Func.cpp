#include <iostream>
#include <cmath>
#include <string>

#include "Stack.h"
#include "Functions.h"


bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') return true;
    return false;
}

bool isOperand(char ch) {
    if ((ch >= '0' && ch <= '9') || ch == '.') return true;
    return false;
}

bool isOpBrackets(char ch) {
    if (ch == '(') return true;
    return false;
}

bool isClBrackets(char ch) {
    if (ch == ')') return true;
    return false;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double operation(double a, double b, char op) {
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a);
    else
        return INT_MIN;
}

bool canGetNextChar(std::string& expression, char& next) {
    bool result = false;

    if (expression.length() > 0) {
        next = expression[0];
        expression.erase(0, 1);
        result = true;
    }

    return result;
}

std::string getNextElement(std::string& expression) {
    std::string result;
    char symbol;

    while (canGetNextChar(expression, symbol)) {
        if (symbol == ' ') break;
        if (isOpBrackets(symbol) || isClBrackets(symbol) || isOperator(symbol)) { result += symbol; break; }
        if (isOperand(symbol)) {
            result += symbol;
        }
        else {
            expression = symbol + expression;
            break;
        }
    }

    return result;
}

std::string infixToRPN(const std::string& expression) {
    std::string rpn;
    Stack<char> operators;

    for (char symbol : expression) {
        if (symbol == ' ') {
            continue;
        }
        else if (isOperand(symbol)) {
            rpn += symbol;
        }
        else if (isOperator(symbol)) {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(symbol)) {
                rpn += ' ';
                rpn += operators.peek();
                operators.pop();
            }
            operators.push(symbol);
            rpn += ' ';
        }
        else if (isOpBrackets(symbol)) {
            operators.push(symbol);
        }
        else if (isClBrackets(symbol)) {
            while (!operators.isEmpty() && !isOpBrackets(operators.peek())) {
                rpn += ' ';
                rpn += operators.peek();
                operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.isEmpty()) {
        rpn += ' ';
        rpn += operators.peek();
        operators.pop();
    }

    return rpn;
}


double RPN(std::string expression) {
    Stack<double> operands;
    char symbol;
    std::string exp = expression;

    while (canGetNextChar(exp, symbol)) {
        if (symbol == ' ') { continue; }
        else if (isOperand(symbol)) {
            double operand = 0.0;
            bool operandInitialized = false;
            double divisor = 1.0; 
            bool decimalPart = false;
            while (isOperand(symbol) || symbol == '.') {
                if (symbol == '.') {
                    decimalPart = true;
                    canGetNextChar(exp, symbol);
                    continue;
                }
                if (!decimalPart) {
                    operand = operand * 10 + (symbol - '0');
                }
                else {
                    divisor *= 0.1;
                    operand += (symbol - '0') * divisor;
                }
                canGetNextChar(exp, symbol);
                operandInitialized = true;
            }
            if (operandInitialized) {
                operands.push(operand);
                continue;
            }
        }
        else if (isOperator(symbol)) {
            if (!operands.isEmpty()) {
                double operand2 = operands.peek(); operands.pop();
                if (!operands.isEmpty()) {
                    double operand1 = operands.peek(); operands.pop();
                    double result = operation(operand1, operand2, symbol);
                    operands.push(result);
                }
                else {
                    std::cerr << "Error: Not enough operands on the stack for the operation." << std::endl;
                    return 0.0;
                }
            }
            else {
                std::cerr << "Error: Not enough operands on the stack for the operation." << std::endl;
                return 0.0;
            }
        }
    }
    if (operands.isEmpty()) {
        std::cerr << "Error: No result left on the stack." << std::endl;
        return 0.0;
    }
    return operands.peek();
}
