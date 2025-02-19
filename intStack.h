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

