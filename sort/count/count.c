#include "stdio.h"
#include "stdlib.h"
#include <stdint.h>

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

void count_sort(int A[], int n) {
  int i, j, max, *C;
  max = find_max_range(A, n);

  C = (int *)malloc(sizeof(int) * (max + 1));

  for (i = 0; i < max + 1; i++) {
    C[i] = 0;
  }

  for (i = 0; i < n; i++) {
    C[A[i]]++;
  }

  i = 0;
  j = 0;
  while (j < max + 1) {
    if (C[j] > 0) {
      A[i] = j;
      C[j]--;
    } else {
      j++;
    }
  }
}

int main() {
  int A[] = {1, 4, 9, 10};
  count_sort(A, 3);
  for (int i = 0; i < 3; i++) {
    printf("%d\n", A[i]);
  }

  return 0;
}
