//#include "intStack.h"
#include "charStack.h"
#include <string>
#include <iostream>
using namespace std;

// function to check if the given string is a palindrome

bool isPalindrome(const string& str) {
  CharStack stack = ' ';
  string res;

  //Decided I wanted to remove spaces from the string since your instructions say
  //check if the *string* is a palindrome, not just a single word.
  for (char c : str) {
    if (c != ' ') {
      res += c;
    }
  }

  int len = res.length();

  for (int i = 0; i < len; i++) {
    stack.push(res[i]);
  }

  for (int i = 0; i < len; i++) {
    if (res[i] != stack.pop()) {
      return false;
    }
  }
  return true;
}


int main() {
  string str;

  cout << "Enter a string: ";
  getline(cin, str);

  if (isPalindrome(str)) {
    cout << "The string is a palindrome." << endl;
  } else {
    cout << "The string is not a palindrome." << endl;
  }
  return 0;
}

// check if opening and closing symbols match
bool matches(char openSymb, char closeSymb) {
    string opens = "([{";
    string closers = ")]}";
    
    size_t openPos = opens.find(openSymb);
    size_t closePos = closers.find(closeSymb);
    
    return (openPos != s:tring::npos && closePos != string::npos && openPos == closePos);
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
/*
// function for generic symbol checker
int main() {
  string symb;

  cout << "Enter a string of symbols to be checked: ";
  getline(cin, symb);
  if (symChecker(symb)) {
    cout << "The symbols are balanced." << endl;
  } else{
      cout << "The symbols are NOT balanced." << endl;
  }
  return 0;
}*/
