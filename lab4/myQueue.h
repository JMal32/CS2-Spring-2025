#include <vector>
#include <stdexcept>

template <typename T> class myQueue {
private:
  std::vector<T> queue;
  int capacity;
  int beg;  // Index of first element
  int end;  // Index after last element

public:
  myQueue(int sz);
  void push(T val);
  T pop();
  T front() const;
  T back() const;
  int size() const;
  bool empty() const;
};

template <typename T>
myQueue<T>::myQueue(int sz) : capacity(std::max(sz, 1000)), beg(0), end(0) {
  queue.resize(capacity);
}

template <typename T> void myQueue<T>::push(T val) {
  if (end >= capacity) {
    // Need to resize
    int newCapacity = capacity + 1000;
    
    // If we have data at the beginning we need to make room
    if (beg > 0) {
      // Shift data to the beginning
      for (int i = 0; i < size(); i++) {
        queue[i] = queue[beg + i];
      }
      end = size();
      beg = 0;
    } else {
      // Just increase capacity
      queue.resize(newCapacity);
      capacity = newCapacity;
    }
  }
  
  queue[end] = val;
  end++;
}

template <typename T> T myQueue<T>::pop() {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  
  T val = queue[beg];
  beg++;
  return val;
}

template <typename T> T myQueue<T>::front() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[beg];
}

template <typename T> T myQueue<T>::back() const {
  if (empty()) {
    throw std::underflow_error("Queue is empty");
  }
  return queue[end - 1];
}

template <typename T> int myQueue<T>::size() const {
  return end - beg;
}

template <typename T> bool myQueue<T>::empty() const {
  return beg == end;
}
