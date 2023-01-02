/*
1. Sa se construiasca si sa se afiseze in preordine un arbore binar de cautare ce contine nodurile: 54, 85, 28, 32, 14

2. Sa se actualizeze si sa se afiseze factorii de balansare.
 
3. Considerand ca arborele anterior este un arbore AVL sa se insereze cheile 19 si 21 si apoi sa se afiseze arborele in preordine.

*/

#include <iostream>

using namespace std;

class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};


int max(int a, int b) {
  return (a > b) ? a : b;
}
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}


Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

//rotatie dreapta
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

//rotatie stanga
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

//balance factor
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

Node *insertNode(Node *node, int key) {
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}
void printTree(Node *root,bool last) {
  if (root != nullptr) {
    cout << root->key<<" ";
    printTree(root->left,false);
    printTree(root->right,true);
  }
}

int main() {
  Node *root = NULL;
  root = insertNode(root, 54);
  root = insertNode(root, 85);
  root = insertNode(root, 28);
  root = insertNode(root, 32);
  root = insertNode(root, 14);
  printTree(root, true);
  cout<<endl;
  root = insertNode(root, 19);
  root = insertNode(root, 21);
  printTree(root,true);
}
