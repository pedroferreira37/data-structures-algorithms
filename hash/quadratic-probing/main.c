#include <stdio.h>

#define SIZE 10

int hash(x) { return x % 10; }

int quadratic_probing(int H[], int k) {
  int __ix = hash(k);
  int i = 0;

  while (H[__ix * (i * i) % SIZE] != 0) {
    i++;
  }

  return (__ix + (i * i % SIZE));
}

void insert(int H[], int key) {
  int idx = Hash(key);

  if (H[idx] != 0) {
    idx = QuadraticProbe(H, key);
  }
  H[idx] = key;
}

int search(int H[], int key) {
  int idx = Hash(key);
  int i = 0;
  while (H[(idx + i * i) % SIZE] != key) {
    i++;
    if (H[(idx + i * i) % SIZE] == 0) {
      return -1;
    }
  }
  return (idx + i * i) % SIZE;
}

int main() { return 0; }