#include "charStack.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// I struggled with changing this over to c++ so I got some help with it. I understand it, but I had
// a hard time with this one. 
string in2post(const string& infixexpr) {
    int prec[128] = {0};
    prec['*'] = 3;
    prec['/'] = 3;
    prec['+'] = 2;
    prec['-'] = 2;
    prec['('] = 1;

    CharStack opStack(10); // I wasn't sure what to initialize this with, so I just picked 10 
    vector<string> postfixList;
    string token;
    string result;

    for (char ch : infixexpr) {
        if (isalpha(ch)) {
            result += ch;
            result += ' ';
        } else if (ch == '(') {
            opStack.push(ch);
        } else if (ch == ')') {
            char topToken = opStack.pop();
            while (topToken != '(') {
                result += topToken;
                result += ' ';
                topToken = opStack.pop();
            }
        } else if (ch == ' ') {
            continue;
        } else {
            while (!opStack.isEmpty() && prec[opStack.peek()] >= prec[ch]) {
                result += opStack.pop();
                result += ' ';
            }
            opStack.push(ch);
        }
    }

    while (!opStack.isEmpty()) {
        result += opStack.pop();
        result += ' ';
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back(); // Remove the trailing space
    }

    return result;
}

int main() {
    string infixexpr;
    cout << "Enter an infix expression: ";
    getline(cin, infixexpr);

    string postfix = in2post(infixexpr);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

