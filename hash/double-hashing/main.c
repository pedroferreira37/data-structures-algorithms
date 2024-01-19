#include <stdio.h>

#define SIZE 10
#define PRIME 7

int hash(int x) { return x % SIZE; }

int pr_hash(int x) { return PRIME - (x % PRIME); }

int colln_hash(int x, int i) { return hash(x) + (i * pr_hash(x)) % SIZE; }

int double_hash(int H[], int k) {
  int __ix = hash(k);
  int i = 0;

  while (H[colln_hash(__ix, i)] != 0) {
    i++;
  }

  return H[colln_hash(__ix, i)];
}

void ins(int H[], int k) {
  int __ix = hash(k);

  if (H[__ix] != 0) {
    __ix = double_hash(H, k);
  }
  H[__ix] = k;
}

int search(int H[], int k) {
  int __ix = hash(k);
  int i = 0;

  while (H[colln_hash(__ix, i)] != k) {
    i++;
    if (H[colln_hash(__ix, i)] == 1) {
      return -1;
    }
  }

  return colln_hash(H[__ix], i);
}

int main() {
  int A[] = {5, 25, 15, 35, 95};
  int H[10] = {0};

  for (int i = 0; i < 10; i++) {
    ins(H, A[i]);
  }

  printf("found %d \n ", search(H, 25));

  return 0;
}
