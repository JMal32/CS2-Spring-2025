#include "intStack.h"
#include "charStack.h"
#include <iostream>
#include <string>
#include <vector>

class CharStack {
public:
  charStack(char c); // Constructor
  void push(char item);
  bool isEmpty();
  char pop();
  char peek();
  char size();
private:
  std::vector<char> vec;
};

charStack::charStack(char c) {
  vec.reserve(c + 100);
}

void CharStack::push(char item) {
  vec.push_back(item);
}

bool CharStack::isEmpty() {
  return vec.size() == 0;
}

char CharStack::pop() {
  char res;
  if (this->isEmpty()) {
    cout:: << "Error: Popping an empty charStack: NULL returned." << endl;
    return NULL;
  }
  else {
    return vec.back();
  }

char CharStack::peek() {
  if (this->isEmpty()) {
      cout << "Error: Peeking an empty charStack: NULL returned." << endl;
  }
  else {
    return vec.back();
  }
}

char CharStack::size() {
  return vec.size();
}
