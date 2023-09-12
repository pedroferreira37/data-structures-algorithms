#include <stdio.h>
#include <stdlib.h>

void Insert(int A[], int n) {
  int i = n, temp;
  temp = A[i];

  while (i > 1 && temp > A[i / 2]) {
    A[i] = A[i / 2];
    i /= 2;
  }
  A[i] = temp;
}

void createHeap(int A[], int n) {
  for (int i = 2; i <= n; i++) {
    Insert(A, i);
  }
}

int delete(int A[], int n) {
  int i, j, x, temp, val;

  val = A[1];
  x = A[n];
  A[1] = A[n];
  A[n] = val;
  i = 1;
  j = i * 2;

  while (j <= n - 1) {
    if (j < n - 1 && A[j + 1] > A[j]) {
      j += 1;
    }

    if (A[i] < A[j]) {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      i = j;
      j = 2 * j;
    } else {
      break;
    }
  }
  return val;
}

void printHeap(int A[], int n) {
  for (int i = 1; i <= 7; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void heapSort(int H[], int n) {
  for (int i = n; i > 1; i--) {
    delete (H, i);
  }
}

int main() {
  int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

  createHeap(H, 7);
  printHeap(H, 7);
  heapSort(H, 7);
  printHeap(H, 7);

  return 0;
}
