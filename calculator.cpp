#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include "reversepolish.h"

//We are making a calculator by having the user type in an equation with / + * -
//We convert the string the gave us into an array of char values representing a number or an arithmetic operator
//

// void reversePolishNotationConverter(std::string& equation);
// bool isOperator(char c);
// void solve(std::string& equation, int& result);
// int priority(char c);

int main() {
    std::string equation = "";
    double result = 0;

    std::cout << "Enter an equation to solve:\n";
    std::getline((std::cin ), equation);
    std::string infix = "3 + 4 * 2 / (1 - 5) ^ 2 ^ 3";
    
    reversePolishNotationConverter(equation);
    result = solve(equation);

    std::cout << "Here is the solution: " << result << '\n';

    return 0;
}

/*
    To solve the reverse polish notation equation we are going to use a stack.
    With the stack we add all of the numbers into the stack by default.
    Everytime we see an operator, we pop the top 2 elements in the stack,
     and use the operator on the 2 elements and push the result to the stack.

     The final element in the stack is the overall result of the equation.

*/

double solve(std::string& equation) {
    std::stack<double> stackNumbers;
    std::string numAsString;

    for(int i = 0; i < equation.size(); i++) {
        char c = equation[i];
        if(isOperator(c)){
            if(c == '-' && isdigit(equation[i+1])){
                numAsString += '-';
            }
            else {
                double firstNum = stackNumbers.top();
                stackNumbers.pop();
                double secondNum = stackNumbers.top();
                stackNumbers.pop();

                switch (c)
                {
                case '+':
                    stackNumbers.push(secondNum + firstNum);
                    break;

                case '-':
                    stackNumbers.push(secondNum - firstNum);
                    break;

                case '*':
                    stackNumbers.push(secondNum * firstNum);
                    break;

                case '/':
                    stackNumbers.push(secondNum / firstNum);
                    break;

                case '^':
                    stackNumbers.push(pow(secondNum, firstNum));
                    break;
                
                default:
                    break;
                }
            
            }
        }
        else if(c == ','){
            stackNumbers.push(stod(numAsString));
            numAsString="";
        }
        else {
            numAsString += c;
        }
    }

    

    return stackNumbers.top();
}



