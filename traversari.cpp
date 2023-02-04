#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
  int data;
  struct bst_node *left;
  struct bst_node *right;
} bst_node;

bst_node *create_bst_node(int data) {
  bst_node *new_node = (bst_node *)malloc(sizeof(bst_node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void in_order_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  in_order_traversal(root->left);
  printf("%d ", root->data);
  in_order_traversal(root->right);
}

void pre_order_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  pre_order_traversal(root->left);
  pre_order_traversal(root->right);
}

void post_order_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  post_order_traversal(root->left);
  post_order_traversal(root->right);
  printf("%d ", root->data);
}
