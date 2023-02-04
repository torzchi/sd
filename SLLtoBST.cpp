#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

node *create_linked_list(int arr[], int n) {
  node *head = create_node(arr[0]);
  node *current = head;
  for (int i = 1; i < n; i++) {
    current->next = create_node(arr[i]);
    current = current->next;
  }
  return head;
}

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

bst_node *linked_list_to_bst(node **head, int n) {
  if (n <= 0) {
    return NULL;
  }
  bst_node *left = linked_list_to_bst(head, n / 2);
  bst_node *root = create_bst_node((*head)->data);
  root->left = left;
  *head = (*head)->next;
  root->right = linked_list_to_bst(head, n - n / 2 - 1);
  return root;
}

void in_order_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  in_order_traversal(root->left);
  printf("%d ", root->data);
  in_order_traversal(root->right);
}
void post_order_traversal(bst_node *root) {
  if (root == NULL) {
    return;
  }
  post_order_traversal(root->left);
  post_order_traversal(root->right);
  printf("%d ", root->data);
}

int main() {
  int arr[] = {5,4,10,2,11};
  int n = sizeof(arr) / sizeof(arr[0]);
  node *head = create_linked_list(arr, n);
  node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");

  bst_node *root = linked_list_to_bst(&head, n);
  post_order_traversal(root);
  printf("\n");

  return 0;
}
