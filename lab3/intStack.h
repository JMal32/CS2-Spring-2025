#include "intStack.h"
#include "charStack.h"
#include <iostream>
#include <string>
#include <vector>

class IntStack {
public:
  intStack(int sz); // Constructor
  bool isEmpty();
  void push(int item);
  int peek();
  int pop();
  int size();
private:
std::vector<int> vec;
};

inStack::intStack(int sz) {
  vec.reserve(sz + 100);
}

bool IntStack::isEmpty() {
  return vec.size() == 0;
}

void IntStack::push(int item) {
  vec.push_back(item);
}

int IntStack::peek() {
  if (this->isEmpty()) {
    cout << "Error: Peeking an empty intStack: NULL returned." << endl;
    return NULL;
  }
  else {
    return vec.back();
  }
}

int IntStack::size() {
  return vec.size();
}

int IntStack::pop() {
  int res;
  if (this->isEmpty()) {
    cout << "Error: Popping an empty intStack: NULL returned." << endl;
    return NULL;
  }
  else {
    res = vec.back();
    vec.pop_back();
    return res;
  }
}
