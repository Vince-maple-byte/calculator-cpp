#include <iostream>
#include <stack>
#include "reversepolish.h"


/*

 Rules of reverse polish notation (RPN):
    Follows the format of 3 5 +, so the numbers are first, then the operators follow

    To do the conversion:
    
        Anytime we see a number add to the output: add to the output string / queue
        Anytime we see a '(' : add it to the stack
        Anytime we see a operator (+/*-^) while not a '(' or : 
            We first check the priority of the operator:
                The priority list:
                    ^ = 3
                    * / = 2
                    + - = 1
            If the priority is ^ and the top value in the stack is ^
                then we just add the new ^ into the stack
            Else if the priority is higher than the top value in the stack,
                then we add the new operator to the stack
            Else if the priority is the same or less than the top value in the stack,
                then we pop the top operator and add to the output
                and do this again in a loop.
                afterwards add the operator to the stack.
        Anytime we see ')' :
             pop all of the elements in the stack until '(' and add them to the output,
             then pop '(', but don't add it to the output

        Things to make sure:
            The user can type in a multidigit number so we need to make sure to capture that in the input
            The user could type an input that is invalid (valid = digit, . for float, (, ), operators) so we need to ignore them.

*/

void reversePolishNotationConverter(std::string& equation){
    std::string rpn = "";
    std::stack<char> stack;
    //We surrond the equation in a paranthesis because this would pop out all of the remaining operators in the stack.
    equation = '('+equation+')';
    for(int i = 0; i < equation.size(); i++){
        //if digit
        if(isdigit(equation[i])){
            rpn += equation[i];
            while(i < equation.size() - 1 && isdigit(equation[i+1]) || equation[i+1] == '.') {
                rpn += equation[i+1];
                i++;
            }
            rpn += ",";
            
        }
        //if '('
        else if(equation[i] == '('){
            stack.push(equation[i]);
        }
        //if operator
        else if(isOperator(equation[i])){
            if(i < equation.size() - 1 && equation[i] == '-' && isdigit(equation[i+1])){
                rpn += '-';
                // std::cout << rpn << '\n';
            }
            else if(equation[i] == '^'){
                stack.push('^');
            }
            else {
                while(!stack.empty() && priority(equation[i]) <= priority(stack.top())){
                    rpn += stack.top();
                    stack.pop();
                }
                stack.push(equation[i]);
            }
        }
        //if ')'
        else if(equation[i] == ')'){
            while(stack.top() != '('){
                rpn += stack.top();
                stack.pop();
            }
            stack.pop();
        }
    }
    std::cout << rpn << '\n';
    equation = rpn;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';

}

int priority(char c) {
    if(c == '^') {
        return 3;
    }
    else if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '-' || c == '+'){
        return 1;
    }
    else {
        return 0;
    }
}

// int main() {
//     std::string infix = "2 + 2 * 4";
//     reversePolishNotationConverter(infix);

//     return 0;
// }