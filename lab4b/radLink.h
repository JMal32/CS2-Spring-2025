#include <iostream>
#include <stdexcept>

template <typename T> class LinkedList2 {

private:
  /* After doing some reearch, I am going to put my node in this class file
  as a struct.*/
  struct Node {
    T data;
    Node *next;
    Node(T val) : data(val), next(nullptr) {}
  };
  Node *head; // Pointer to first node
  Node *tail; // Pointer to last node
  int count;  // This is where I track the nodes

public:
  LinkedList2() : head(nullptr), tail(nullptr), count(0) {} // Constructor
  ~LinkedList2() {                                          // Destructor
    while (head != nullptr) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  // Queueing ops
  void enqueue(T value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
    count++;
  }

  T dequeue() {
    if (head == nullptr) {
      throw std::runtime_error("Queue is empty");
    }
    T value = head->data;
    Node *temp = head;
    head = head->next;
    if (head == nullptr) { // If the queue becomes empty, reset tail
      tail = nullptr;
    }
    delete temp;
    count--;
    return value;
  }

  bool isEmpty() const { return head == nullptr; }

  int size() const { return count; }
};

template <typename T> class LLQueue {
private:
  LinkedList2<T> list;

public:
  void push(T val) { list.enqueue(val); }

  T pop() { return list.dequeue(); }

  bool empty() const { return list.isEmpty(); }

  int size() const { return list.size(); }
};
