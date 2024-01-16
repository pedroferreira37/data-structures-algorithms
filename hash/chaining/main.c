#include <stdio.h>

#include "Chains.h"

int hash(int key) { return key % 10; }

void insert(struct Node *H[], int key) {
  int __ix = hash(key);
  ins_sorted(&H[__ix], key);
}

int main() {
  struct Node *HT[10];
  struct Node *temp;
  int i;

  for (i = 0; i < 10; i++) {
    HT[i] = NULL;
  }
  insert(HT, 12);
  insert(HT, 22);
  insert(HT, 42);

  temp = search(HT[hash(22)], 22);

  printf("%d", temp->data);

  return 0;
}