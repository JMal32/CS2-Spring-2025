#include <iostream>
#include <vector>
using namespace std;

//Building an integer stack class
class IntStack {
public:
  itStack(int sz = 0);
  void push(int item);
  int pop();
  bool isEmpty();
  int peek();
  int size();
  
private:
  vector<int> vec;
};

intStack::IntStack(int sz) {
  vec.resize(sz) {
    vec.reserve(sz + 100);
  }
}

bool intStack::isEmpty() {
  return vec.empty();
}

int intStack::peek() {
  if (this->isEmpty()) {
    cout << "Error: Peeking an empty intStack: NULL returned" << endl;
    return NULL;
  }
  else {
    return vec.back();
}

int intStack::pop() {
  if (this->isEmpty()) {
    cout << "Error: Popping an empty intStack: NULL returned" << endl;
    return NULL;
  }
  else {
    res = vec.back();
    vec.pop_back();
    return res;
  }
}

int intStack::size() {
  return vec.size();
}
