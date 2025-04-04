#include <iostream>
#include <stdexcept>

template <typename T> class radLink {
public:
  radLink(); // Constructor
  ~radLink(); // Destructor
private:
  /* After doing some reearch, I am going to put my node in this class file
  as a struct.*/
  struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr){}
  };
  Node* head; // Pointer to first node
  Node* tail; // Pointer to last node
  int count; // This is where I track the nodes
};

