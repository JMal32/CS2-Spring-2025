#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int item) {
    data = item;
    left = right = nullptr;
  }
};

void Node::GFG(Node *root) {}
