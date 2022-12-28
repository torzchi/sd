#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node in the BST
struct Node {
  char data;
  struct Node* left;
  struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to create a new node
struct Node* createNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
  // If the tree is empty, return a new node
  if (root == NULL) return createNode(data);

  // Recursively insert the new node into the appropriate subtree
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

// Function to print the BST in inorder traversal
void printTree(struct Node* node) {
  if (node == NULL) return;

  // Print the left subtree
  printTree(node->left);

  // Print the value of the current node
  printf("%d ", node->data);

  // Print the right subtree
  printTree(node->right);
};

int main() {
  // Read the name from the user
  char name[100];
  printf("Enter your name: ");
  scanf("%s", name);

  // Create the BST
  struct Node* root = NULL;
  for (int i = 0; i < strlen(name); i++) {
    root = insert(root, (int)name[i]);
  }

  // Print the BST
  printf("Your name as a BST:\n");
  printTree(root);
  printf("\n");

  return 0;
}
