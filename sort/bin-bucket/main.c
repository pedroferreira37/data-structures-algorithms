#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

int find_max_range(int A[], int n) {
  int i = 0;
  int max = INT32_MIN;
  for (i = 0; i < n - 1; i++) {
    if (max < A[i]) {
      max = A[i];
    }
  }

  return max;
}

void sortBinBucket(int *A, int n) {
  int i, j, max;
  Node **Bins;

  max = find_max_range(A, n);
  Bins = (Node **)malloc(sizeof(Node *) * (max + 1));

  for (i = 0; i < (max + 1); i++) {
    Bins[i] = NULL;
  }

  for (i = 0; i < n; i++) {
    Node *b = (Node *)malloc(sizeof(Node));
    b->data = A[i];
    b->next = Bins[A[i]];
    Bins[A[i]] = b;
  }

  for (i = 0, j = 0; i <= max; i++) {
    Node *tmp = Bins[i];

    while (tmp != NULL) {
      A[j++] = tmp->data;
      Node *toFree = tmp;
      tmp = tmp->next;
      free(toFree);
    }
  }

  free(Bins);
}

void printArray(int *A, int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", A[i]);
    if (i < n - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main() {
  int A[] = {1, 5, 4, 0};
  int n = 4;

  printArray(A, n);
  sortBinBucket(A, n);

  printArray(A, n);

  return 0;
}
