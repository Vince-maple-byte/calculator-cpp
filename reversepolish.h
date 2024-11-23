#pragma once
#include <iostream>

void reversePolishNotationConverter(std::string& equation);
bool isOperator(char c);
int priority(char c);
double solve(std::string& equation);