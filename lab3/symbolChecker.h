#include <iostream>
#include <string>
#include "charStack.h"
using namespace std;

// check if opening and closing symbols match
bool matches(char openSymb, char closeSymb) {
    string opens = "([{";
    string closers = ")]}";
    
    size_t openPos = opens.find(openSymb);
    size_t closePos = closers.find(closeSymb);
    
    return (openPos != string::npos && closePos != string::npos && openPos == closePos);
}

// check if symbols in a string are balanced
bool symChecker(const string& symbolString) {
    CharStack s('0'); // Initialize with a character (seems to be used for capacity)
    bool balanced = true;
    size_t index = 0;
    
    while (index < symbolString.length() && balanced) {
        char symbol = symbolString[index];
        
        if (symbol == '(' || symbol == '[' || symbol == '{') {
            // an opener
            s.push(symbol);
        } else if (symbol == ')' || symbol == ']' || symbol == '}') {
            // a closer
            if (s.isEmpty()) {
                balanced = false;
            } else {
                char top = s.pop();
                if (!matches(top, symbol)) {
                    balanced = false;
                }
            }
        }
        
        index++;
    }
    
    return balanced && s.isEmpty();
}

