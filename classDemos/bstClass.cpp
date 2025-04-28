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
    return find(root->right, data);

  return find(root->left, data);
}

// getSuccessor - from what I understand, this function will mainly work with
// right child not being empty, which is what you want for BST deleting
Node *getSuccessor(Node *curr) {
  curr = curr->right;
  while (curr != nullptr && curr->left != nullptr)
    curr = curr->left;
  return curr;
}

// Deleting a node
Node *remove(Node *root, int data) {
  if (root == nullptr)
    return root;

  // If key we're searching for is in a subtree
  if (root->data > data)
    root->left = remove(root->left, data);
  else if (root->data < data)
    root->right = remove(root->right, data);

  // IF our root matches "data"
  else {
    // cases for root having 0 children or only right child
    if (root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    }

    // when root only has left child
    if (root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // when we have both children
    Node *successor = getSuccessor(root);
    root->data = successor->data;
    root->right = remove(root->right, successor->data);
  }
  return root;
}
