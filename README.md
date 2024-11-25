# calculator-cpp
This is a calculator that converts an equation written in infix notation (3 + 3), and converts it to postfix notation(3 3 +)

##Why
Postfix notation is easier for a computer to calculate math equations compared to the way humans write and read equations because with postfix notation we dont need to use parentheses to maintain order of operations.

##How to run
Before running make sure to have gcc compiler running on your machine since I have not built CMake files for cross platform compatibility

```
g++ -c reversepolish.cpp -o reversepolish.o
g++ -c calculator.cpp -o calculator.o
g++ reversepolish.o calculator.o -o calculator.exe
calculator.exe
```
