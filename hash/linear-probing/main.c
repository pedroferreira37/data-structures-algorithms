#include <stdio.h>

#define SIZE 10

int hash(int key) { return key % SIZE; }

int probe(int H[], int key) {
  int __ix = hash(key);
  int i = 0;

  while (H[(__ix + i) % SIZE]) {
    i++;
  }

  return (__ix + i % SIZE);
}

void insert(int H[], int key) {
  int __ix = hash(key);

  if (H[__ix] != 0) {
    __ix = probe(H, key);
  }

  H[__ix] = key;
}

int search(int H[], int key) {
  int __ix = hash(key);
  int i = 0;

  while (H[(__ix + i) % SIZE]) {
    i++;
  }

  return (__ix + i) % SIZE;
}

int main() {
  int HT[10] = {0};

  insert(HT, 12);
  insert(HT, 25);
  insert(HT, 35);
  insert(HT, 26);

  printf("key found %d ", search(HT, 35));
  return 0;
}
