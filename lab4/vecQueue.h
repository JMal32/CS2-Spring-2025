#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
// I recently learned that, in header files, it is common to not use namespace
// std.
template <typename T> class QueueClass {
public:
  QueueClass(int sz);
  void push(T val);
  T pop();
  T front() const;
  T back() const;
  int size() const;
  bool empty() const;

private:
  std::vector<T> queue;
  int capacity;
};

template <typename T> QueueClass<T>::QueueClass(int sz) : capacity(sz) {
  queue.reserve(capacity);
}

template <typename T> void QueueClass<T>::push(T val) {
  if (queue.size() >= capacity) {
    throw std::overflow_error("Queue is full");
  }
  queue.push_back(val);
}

template <typename T> T QueueClass<T>::pop() {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }

  T val = queue[0];

  for (size_t i = 0; i < queue.size() - 1; i++) {
    queue[i] = queue[i + 1];
  }

  queue.pop_back();

  return val;
}

template <typename T> T QueueClass<T>::front() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[0];
}

template <typename T> T QueueClass<T>::back() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[queue.size() - 1];
}

template <typename T> int QueueClass<T>::size() const { return queue.size(); }

template <typename T> bool QueueClass<T>::empty() const {
  return queue.empty();
}
