#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data[2];
  struct Node *children[3];
  int size;
  int isLeaf;
} Node;

Node *create(int key) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data[0] = key;
  node->size = 1;
  node->isLeaf = 0;

  for (int i = 1; i < 3; i++) {
    node->children[i] = NULL;
  }

  return node;
}
void insert(Node **root, int key) {
  if (*root == NULL) {
    *root = createNode(key);
  } else {
    Node *node = search(*root, key);
    if (node->size < 2) {
      // Insert the key into the current node
      int i = node->size - 1;
      while (i >= 0 && node->data[i] > key) {
        node->data[i + 1] = node->data[i];
        i--;
      }
      node->data[i + 1] = key;
      node->size++;
    } else {
      Node *parent = node->parent;
      if (parent == NULL) {
        Node *newRoot = split(node);
        *root = newRoot;
      } else {
        int middleKey = node->data[1];
        Node *newNode = split(node);
        insert(&parent, middleKey);
        int i = parent->size - 1;
        while (i >= 0 && parent->data[i] > middleKey) {
          parent->data[i + 1] = parent->data[i];
          i--;
        }
        parent->data[i + 1] = middleKey;
        parent->size++;
        parent->children[i + 1] = newNode;
      }
    }
  }
}

Node *search(Node *root, int key) {
  Node *cur = root;

  while (cur != NULL) {
    if (cur->size == 1) {
      if (key < cur->data[0]) {
        cur = cur->children[0];
      } else if (key > cur->data[0]) {
        cur = cur->children[1];
      } else {
        return cur;
      }
    } else {
      if (key < cur->data[0]) {
        cur = cur->children[0];
      } else if (key > cur->data[1]) {
        cur = cur->children[2];
      } else {
        return cur;
      }
    }
  }

  return NULL;
}

void treeTraversal(Node *node) {
  if (node != NULL) {
    treeTraversal(node->children[0]);
    printf("%d ", node->data[0]);
    treeTraversal(node->children[1]);
    if (node->size == 2) {
      printf("%d ", node->data[1]);
      treeTraversal(node->children[1]);
    }
  }
}

int main() {
  printf("%s\n", "2-3-4-trees");

  Node *root = NULL;
  int data[] = {4, 8, 15, 16, 23, 42};

  for (int i = 0; i < 6; i++) {
    insert(&root, data[i]);
  }

  treeTraversal(root);
  printf("\n");

  return 0;
}
