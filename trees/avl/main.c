#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *left;
  int data;
  int height;
  struct Node *right;
} Node;

Node *root = NULL;

int node_height(Node *p) {
  int hl, hr;

  hl = p && p->left ? p->left->height : 0;
  hr = p && p->right ? p->right->height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}

int is_balanced(Node *p) {
  int hl, hr;

  hl = p && p->left ? p->left->height : 0;
  hr = p && p->right ? p->right->height : 0;

  return hl - hr;
}

Node *ll_rotation(Node *p) {
  Node *pl = p->left;
  Node *plr = pl->right;

  pl->right = p;
  p->left = plr;

  p->height = node_height(p);
  pl->height = node_height(pl);

  if (root == p) {
    root = pl;
  }

  return pl;
}

Node *lr_rotation(Node *p) {
  Node *pl = p->left;
  Node *plr = pl->right;

  pl->right = plr->left;
  p->left = plr->right;

  plr->left = pl;
  plr->right = p;

  pl->height = node_height(pl);
  p->height = node_height(p);
  plr->height = node_height(plr);

  if (root == p) {
    root = plr;
  }

  return plr;
}

Node *rr_rotation(Node *p) {
  Node *pl = p->right;
  Node *plr = pl->left;

  pl->left = p;
  p->right = plr;

  p->height = node_height(p);
  pl->height = node_height(pl);

  if (root == p) {
    root = pl;
  }

  return pl;
}

Node *rl_rotation(Node *p) {
  Node *pl = p->right;
  Node *plr = pl->left;

  pl->left = plr->right;
  p->right = plr->left;

  plr->left = p;
  plr->right = pl;

  pl->height = node_height(pl);
  p->height = node_height(p);
  plr->height = node_height(plr);

  if (root == p)
    root = plr;

  return plr;
}

Node *RInsert(Node *p, int key) {
  Node *t;

  if (p == NULL) {
    t = (Node *)malloc(sizeof(Node));
    t->data = key;
    t->height = 1;
    t->left = t->right = NULL;
    return t;
  }
  if (key < p->data) {
    p->left = RInsert(p->left, key);
  } else if (key > p->data) {
    p->right = RInsert(p->right, key);
  }

  p->height = node_height(p);

  if (is_balanced(p) == 2 && is_balanced(p->left) == 1) {
    // return ll_rotation(p);
  } else if (is_balanced(p) == 2 && is_balanced(p->left) == -1) {
    // return lr_rotation(p);
  } else if (is_balanced(p) == -2 && is_balanced(p->right) == -1) {
    // return rr_rotation(p);
  } else if (is_balanced(p) == -2 && is_balanced(p->right) == 1) {
    return rl_rotation(p);
  }

  return p;
}

void Preorder(Node *p) {

  if (p) {
    Preorder(p->left);
    printf("%d ", p->data);
    Preorder(p->right);
  }
}

int main() {
  root = RInsert(root, 10);
  RInsert(root, 30);

  RInsert(root, 20);

  printf("%d", root->data);
  return 0;
}
