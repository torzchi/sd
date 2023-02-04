#include<stdio.h>
#include<stdlib.h>

struct Node {
  int key;
  struct Node *left, *right;
};

struct Node* newNode(int key) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->key = key;
  node->left = node->right = NULL;
  return node;
}

void printGivenLevel(struct Node* root, int level) {
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root->key);
  else if (level > 1) {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}

int maxGivenLevel(struct Node* root, int level, int max) {
  if (root == NULL)
    return max;
  if (level == 1) {
    if (root->key > max)
      max = root->key;
  }
  else if (level > 1) {
    max = maxGivenLevel(root->left, level-1, max);
    max = maxGivenLevel(root->right, level-1, max);
  }
  return max;
}

int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  int level = 3;
  int max = 0;
  max = maxGivenLevel(root, level, max);
  printf("Highest value at level %d: %d", level, max);
  return 0;
}
