#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CharStack {
public:
  CharStack(char c); // Constructor
  void push(char item);
  bool isEmpty();
  char pop();
  char peek();
  char size();
private:
  vector<char> vec;
};

CharStack::CharStack(char c) {
  vec.reserve(c + 100);
}

void CharStack::push(char item) {
  vec.push_back(item);
}

bool CharStack::isEmpty() {
  return vec.empty();
}

char CharStack::pop() {
  if (this->isEmpty()) {
    cout << "Error: Popping an empty charStack: NULL returned." << endl;
    return '\0';
  }
  else {
    char res = vec.back(); // I changed this up a little and just put the res variable in here because its only used in the else portion
    vec.pop_back();
    return res;
  }
}
char CharStack::peek() {
  if (this->isEmpty()) {
      cout << "Error: Peeking an empty charStack: NULL returned." << endl;
      return '\0';
  }
  else {
    return vec.back();
  }
}

char CharStack::size() {
  return vec.size();
}
