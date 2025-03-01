#include "intStack.h"
#include <iostream>
#include <string>

using namespace std;

int evaluatePostfix(const string& postfix) {
    IntStack operandStack(10); // Initial size, constructor will add 100
    string token;

    for (size_t i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            operandStack.push(ch - '0');
        } else if (ch == ' ') {
            continue;
        } else {
            int operand2 = operandStack.pop();
            int operand1 = operandStack.pop();
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cout << "Error: Unknown operator " << ch << endl;
                    return -1;
            }

            operandStack.push(result);
        }
    }

    return operandStack.pop();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}

