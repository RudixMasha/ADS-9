// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct Node {
    T value;
    int k = 0;
    Node* left = nullptr;
    Node* right = nullptr;;
  };
  Node* root;
  Node* addNode(Node* root, const T& val) {
    if (root == nullptr) {
      root = new Node;
      root->value = val;
      root->k = 0;
      root->left = root->right = nullptr;
    } else if (root->value < val) {
      root->left = addNode(root->left, val)
    } else if (root->value > val) {
      root->right = addNode(root->right, val);
    } else {
      root->k++;
    }
      return root;
  }
  int searchNode(Node* root, const T& val) {
    if (root == nullptr) {
      return 0;
    } else if (root->value == val) {
      return root->k;
    } else if (root->value < val) {
      return searchNode(root->left, val);
    } else {
      return searchNode(root->right, val);
    }
  }
  int depth(Node* root) {
    int l = 0, r = 0;
    if (root == nullptr) {
      return 0;
    } else {
      l = depth(root->left);
      r = depth(root->right);
    }
    if (r > l) {
      return ++r;
    } else {
      return ++l;
    }
  }

 public:
  BST() :root(nullptr) {}
  void Add(const T& val) {
    root = addNode(root, val);
  }
  int search(const T& val) {
    return searchNode(root, val);
  }
  int depth() {
    return depth(root)-1;
  }
};
#endif  // INCLUDE_BST_H_
