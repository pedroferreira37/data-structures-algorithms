#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node {
  int data;
  int color; // 0 for black, 1 for red
  struct Node *left;
  struct Node *right;
  struct Node *parent;
} Node;

Node *createNode(int data, Node *parent) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->color = RED;
  newNode->left = newNode->right = NULL;
  newNode->parent = parent;
  return newNode;
}

Node *rotateLeft(Node *root, Node *node) {
  Node *rightChild = node->right;
  node->right = rightChild->left;
  if (rightChild->left != NULL) {
    rightChild->left->parent = node;
  }
  rightChild->parent = node->parent;
  if (node->parent == NULL) {
    root = rightChild;
  } else if (node == node->parent->left) {
    node->parent->left = rightChild;
  } else {
    node->parent->right = rightChild;
  }
  rightChild->left = node;
  node->parent = rightChild;
  return root;
}

Node *rotateRight(Node *root, Node *node) {
  Node *leftChild = node->left;
  node->left = leftChild->right;
  if (leftChild->right != NULL) {
    leftChild->right->parent = node;
  }
  leftChild->parent = node->parent;
  if (node->parent == NULL) {
    root = leftChild;
  } else if (node == node->parent->left) {
    node->parent->left = leftChild;
  } else {
    node->parent->right = leftChild;
  }
  leftChild->right = node;
  node->parent = leftChild;
  return root;
}

Node *insertFixup(Node *root, Node *node) {
  while (node != NULL && node->parent != NULL && node->parent->color == RED) {
    if (node->parent == node->parent->parent->left) {
      Node *uncle = node->parent->parent->right;
      if (uncle != NULL && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->right) {
          node = node->parent;
          root = rotateLeft(root, node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        root = rotateRight(root, node->parent->parent);
      }
    } else {
      Node *uncle = node->parent->parent->left;
      if (uncle != NULL && uncle->color == RED) {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        node->parent->parent->color = RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->left) {
          node = node->parent;
          root = rotateRight(root, node);
        }
        node->parent->color = BLACK;
        node->parent->parent->color = RED;
        root = rotateLeft(root, node->parent->parent);
      }
    }
  }
  root->color = BLACK;
  return root;
}

Node *insert(Node *root, int key) {
  Node *parent = NULL;
  Node *current = root;
  while (current != NULL) {
    parent = current;
    if (key < current->data) {
      current = current->left;
    } else if (key > current->data) {
      current = current->right;
    } else {
      return root;
    }
  }

  Node *newNode = createNode(key, parent);
  if (parent == NULL) {
    root = newNode;
  } else if (key < parent->data) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
  return insertFixup(root, newNode);
}

void inorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  inorderTraversal(root->left);
  printf("%d ", root->data);
  inorderTraversal(root->right);
}

void freeTree(Node *root) {
  if (root == NULL) {
    return;
  }
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

int main() {
  Node *root = NULL;

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);

  printf("In-order traversal: ");
  inorderTraversal(root);
  printf("\n");

  freeTree(root);

  return 0;
}
