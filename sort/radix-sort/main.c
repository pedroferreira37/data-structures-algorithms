#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

int find_max(int *A, int n) {
  int i = 0;
  int max = INT32_MIN;

  for (i = 0; i < n - 1; i++) {
    if (max < A[i]) {
      max = A[i];
    }
  }

  return max;
}

int count_digits(int x) {
  int c = 0;
  while (x != 0) {
    x = x / 10;
    c++;
  }

  return c;
}

void initiliaze(Node **A, int size) {
  for (int i = 0; i < size; i++) {
    A[i] = NULL;
  }
}

int _pow(int base, int exp) {
  int p = 1;

  for (int i = 0; i < exp; i++) {
    p = (p * base);
  }

  return p;
}

void insert_b(Node **b, int value, int i) {
  Node *tmp = (struct Node *)malloc(sizeof(Node));
  tmp->data = value;
  tmp->next = NULL;

  if (b[i] == NULL) {
    b[i] = tmp;
  } else {
    Node *p = b[i];

    while (p->next != NULL) {
      p = p->next;
    }

    p->next = tmp;
  }
}

int delete_b(Node **b, int i) {
  Node *p = b[i];

  b[i] = b[i]->next;
  int x = p->data;
  free(p);

  return x;
}

void radix_sort(int A[], int n) {
  int max, i, p;
  Node **b;

  max = find_max(A, n);
  p = count_digits(max);

  b = (struct Node **)malloc(sizeof(Node *) * 10);

  initiliaze(b, 10);

  for (i = 0; i < p; i++) {
    for (int k = 0; k < n; k++) {
      int ix = (int)(A[k] / _pow(10, i)) % 10;
      insert_b(b, A[k], ix);
    }

    int z = 0;
    int j = 0;
    while (z < 10) {
      while (b[z] != NULL) {
        A[j++] = delete_b(b, z);
      }
      z++;
    }

    initiliaze(b, 10);
  }

  for (int i = 0; i < 10; i++) {
    Node *current = b[i];
    while (current != NULL) {
      Node *next = current->next;
      free(current);
      current = next;
    }
  }
  free(b);
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
  int A[] = {230, 10, 0, 2, 400, 1};
  int n = sizeof(A) / sizeof(A[0]);

  printArray(A, n);
  radix_sort(A, n);
  printArray(A, n);
  return 0;
}
