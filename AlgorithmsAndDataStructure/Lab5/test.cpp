#include <string>

#include "pch.h"

#include "../ReversePolishNotation/Stack.h"
#include "../ReversePolishNotation/Functions.h"
#include "../ReversePolishNotation/Functions.cpp"

TEST(FunctionsTesting, isOperator) {
	EXPECT_EQ(isOperator('+'), true);
	EXPECT_EQ(isOperator('1'), false);
}

TEST(FunctionsTesting, isOperand) {
	EXPECT_EQ(isOperand('5'), true);
	EXPECT_EQ(isOperand('.'), true);
	EXPECT_EQ(isOperand('/'), false);
}

TEST(FunctionsTesting, isBrackets) {
	EXPECT_EQ(isOpBrackets('('), true);
	EXPECT_EQ(isOpBrackets(')'), false);
	EXPECT_EQ(isClBrackets(')'), true);
	EXPECT_EQ(isClBrackets('('), false);
}

TEST(FunctionsTesting, precedence) {
	EXPECT_EQ(precedence('+'), 1);
	EXPECT_EQ(precedence('*'), 2);
	EXPECT_EQ(precedence(')'), 0);
}

TEST(FunctionsTesting, operation_1) {
	EXPECT_EQ(operation(5.2, 2.5, '+'), 7.7);
	EXPECT_EQ(operation(2.5, 5.2, '-'), 2.7);
	EXPECT_EQ(operation(5.2, 2.5, '-'), -2.7);
}

TEST(FunctionsTesting, operation_2) {
	EXPECT_EQ(operation(5.2, 2.5, '*'), 13.0);
	EXPECT_EQ(operation(2.5, 5.2, '/'), 2.08);
	EXPECT_EQ(operation(5, 2.5, '/'), 0.5);
}

TEST(FunctionsTesting, operation_3) {
	EXPECT_EQ(operation(2, 5, '^'), 25);
	EXPECT_EQ(operation(-2, 5, '^'), 0.04);
	EXPECT_EQ(operation(0.5, 4, '^'), 2);
}

TEST(FunctionsTesting, canGetNextChar) {
	std::string exp = "123";
	char symb;

	EXPECT_EQ(canGetNextChar(exp, symb), true);
	EXPECT_EQ(exp, "23");
	EXPECT_EQ(symb, '1');
}

TEST(MainTesting, infixToRPN_int) {
	EXPECT_EQ(infixToRPN("2+3*(4+5)+6"), "2 3 4 5 + * + 6 +");
	EXPECT_EQ(infixToRPN("22+333*(4+55)+67"), "22 333 4 55 + * + 67 +");
}

TEST(MainTesting, infixToRPN_double) {
	EXPECT_EQ(infixToRPN("2.1+3.5*(4+5)+6.7"), "2.1 3.5 4 5 + * + 6.7 +");
}

TEST(MainTesting, RPN_int) {
	EXPECT_EQ(RPN("2 3 4 5 + * + 6 +"), 35);
	EXPECT_EQ(RPN("22 333 4 55 + * + 67 +"), 19736);
}
