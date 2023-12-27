#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int A[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(&A[j], &A[j + 1]);
      }
    }
  }
}

void print(int A[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
}
int main() {
  int A[] = {5, 2, 6, 1, 2};
  print(A, 5);
  bubbleSort(A, 5);
  print(A, 5);

  return 0;
}
