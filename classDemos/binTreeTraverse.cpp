#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int item) {
    data = item;
    left = right = nullptr;
  }
};

// Inserting a node
Node *insert(Node *node, int data) {
  if (node == nullptr)
    return new Node(data);

  if (node->data == data)
    return node;

  if (node->data < data)
    node->right = insert(node->right, data);

  else
    node->left = insert(node->left, data);

  return node;
}

// Finding a node
Node *find(Node *root, int data) {
  if (root == nullptr || root->data == data)
    return root;

  if (root->data < data)
    return find(root->left, data);
}
