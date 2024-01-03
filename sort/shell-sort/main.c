#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void shell_sort(int *A, int n) {
  int i;
  int j;
  int g;
  int temp;

  i = 0;
  g = n / 2;

  for (g = n / 2; g >= 1; g /= 2) {
    for (i = g; i < n; i++) {
      temp = A[i];
      j = i - g;
      while (j >= 0 && A[j] > temp) {
        A[j + g] = A[j];
        j = j - g;
      }
      A[j + g] = temp;
    }
  }
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
  int A[] = {10, 2, 5, 1, 1000, 0, 3};
  printArray(A, 7);
  shell_sort(A, 7);
  printArray(A, 7);

  return 0;
}
