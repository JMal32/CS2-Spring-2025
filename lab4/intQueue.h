#include <cstdlib> // This is what I use For rand()
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class IntQueue {
public:
  IntQueue(int sz); // Constructor
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
IntQueue<T>::IntQueue(int sz) : capacity(sz), head(0), tail(0), count(0) {
  queue.reserve(capacity);
}

template <typename T> void IntQueue<T>::push(T val) {
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

template <typename T> T IntQueue<T>::pop() {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  T val = queue[head];
  head = (head + 1) % capacity;
  count--;
  return val;
}

template <typename T> T IntQueue<T>::front() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[head];
}

template <typename T> T IntQueue<T>::back() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[(tail - 1 + capacity) % capacity];
}

template <typename T> int IntQueue<T>::size() const { return count; }

template <typename T> bool IntQueue<T>::empty() const { return count == 0; }
