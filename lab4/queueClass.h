#include <cstdlib> // This is what I use For rand()
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class QueueClass {
public:
  QueueClass(int sz); // Constructor
  void push(T val);
  T pop();
  T front() const;
  T back() const;
  int size() const;
  bool empty() const;

private:
  std::vector<T> queue;
  int capacity;
  int head;
  int tail;
  int count;
};

template <typename T>
QueueClass<T>::QueueClass(int sz) : capacity(sz), head(0), tail(0), count(0) {
  queue.resize(capacity);
}

template <typename T> void QueueClass<T>::push(T val) {
  if (count == capacity) {
    throw std::overflow_error("Queue is full");
  }
  if (queue.size() < capacity) {
    queue.push_back(val);
  } else {
    queue[tail] = val;
  }
  tail = (tail + 1) % capacity;
  count++;
}

template <typename T> T QueueClass<T>::pop() {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  T val = queue[head];
  head = (head + 1) % capacity;
  count--;
  return val;
}

template <typename T> T QueueClass<T>::front() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[head];
}

template <typename T> T QueueClass<T>::back() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[(tail - 1 + capacity) % capacity];
}

template <typename T> int QueueClass<T>::size() const { return count; }

template <typename T> bool QueueClass<T>::empty() const { return count == 0; }
