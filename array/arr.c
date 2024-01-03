#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Array {
  int length;
  int size;
  int A[20];
};

void printWithBrackets(struct Array arr) {
  printf("[");
  for (int i = 0; i < arr.length; i++) {
    if (i < arr.length - 1) {
      printf("%d,", arr.A[i]);
    } else {
      printf("%d", arr.A[i]);
    }
  }
  printf("]");
}

void push(struct Array* arr, int x) {
  arr->A[arr->length] = x;
  arr->length++;
}

// my code
void insert(struct Array* arr, int index, int x) {
  if (index < arr->length) {
    int i = arr->length;
    while (i > index) {
      arr->A[i] = arr->A[i - 1];
      i--;
    }

    arr->A[index] = x;
    arr->length++;
  }
};

// professor code

void insertTwo(struct Array* arr, int index, int x) {
  for (int i = arr->length; i > index; i--) {
    arr->A[i] = arr->A[i - 1];
  }

  arr->A[index] = x;
  arr->length++;
}

void pop(struct Array* arr) { arr->length--; }

void delete(struct Array* arr, int index) {
  for (int i = index; i < arr->length; i++) {
    arr->A[i] = arr->A[i + 1];
  }

  arr->length--;
}

void ls(struct Array* arr, int num) {
  for (int i = 0; i < arr->length; i++) {
    if (arr->A[i] == num) {
      printf("%d", i);
      return;
    }
  }
}

int BS(struct Array* arr, int key) {
  int start = 0;
  int end = arr->length - 1;
  int m;

  while (start <= end) {
    m = floor(((start + end) / 2));
    if (arr->A[m] == key) {
      return m;
    } else if (key < arr->A[m]) {
      end = m - 1;
    } else {
      start = m + 1;
    }
  }

  return -1;
}

int get(struct Array* arr, int index) { return arr->A[index]; }

void set(struct Array* arr, int index, int x) {
  if (index >= 0 && index < arr->length) {
    arr->A[index] = x;
    arr->length++;
  }
}

int max(struct Array arr) {
  int i = arr.A[0];

  for (int i = 0; i < arr.length; i++) {
    if (arr.A[i] > i) {
      i = arr.A[i];
    }
  }

  return i;
}

void swap(struct Array* arr, int head, int n) {
  int temp = arr->A[head];
  arr->A[head] = arr->A[n];
  arr->A[n] = temp;
}

void reverse(struct Array* arr) {
  int i = 0;
  int j = arr->length - 1;

  while (i <= j) {
    swap(arr, i, j);
    i++;
    j--;
  }
}

void reverseRecurse(struct Array* arr, int head, int n) {
  if (head < n) {
    swap(arr, head, n);
    reverseRecurse(arr, head + 1, n - 1);
  }
}

int sum(int A[], int n) {
  if (n < 0) {
    return 0;
  }

  return sum(A, n - 1) + A[n];
}

void shiftLeft(int A[], int n) {
  int j = 0;
  while (j < n) {
    int temp = A[0];

    for (int i = 0; i < n; i++) {
      A[i] = A[i + 1];
    }
    A[n] = temp;

    for (int i = 0; i < n + 1; i++) {
      printf("%d", A[i]);
    }
    j++;
  }
}

int* merge(int A[], int n, int B[], int m) {
  int i = 0;
  int j = 0;
  int k = 0;
  int* C = (int*)malloc(sizeof(int) * (m + n));

  while (i < n && j < m) {
    if (A[i] < B[j]) {
      C[k++] = A[i++];
    } else {
      C[k++] = B[j++];
    }
  }

  for (; i < n; i++) {
    C[k++] = A[i];
  }

  for (; j < m; j++) {
    C[k++] = B[j];
  }

  return C;
}

void c_print(int A[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", A[i]);
  }
}

int* un(int A[], int n, int B[], int m) {
  int i = 0, j = 0, k = 0;
  int* C = (int*)malloc(sizeof(int) * (m + n));

  while (i < n && j < m) {
    if (A[i] < B[j]) {
      C[k++] = A[i++];
    } else if (A[i] > B[j]) {
      C[k++] = B[j++];
    } else {
      C[k++] = A[i++];
      j++;
    }
  }

  for (; i < n; i++) {
    C[k++] = A[i];
  }

  for (; j < m; j++) {
    C[k++] = B[j];
  }

  return C;
}

int* intsec(int A[], int n, int B[], int m) {
  int i = 0, j = 0, k = 0;
  int* C = (int*)malloc(sizeof(int) * (m + n));

  while (i < n && j < m) {
    if (A[i] < B[j]) {
      i++;
    } else if (A[i] > B[j]) {
      j++;
    } else {
      C[k++] = A[i++];
      j++;
    }
  }

  return C;
}

int* diff(int A[], int n, int B[], int m) {
  int i = 0, j = 0, k = 0;
  int* diff = (int*)malloc(sizeof(int) * (m + n));

  while (i < n && j < 0) {
    if (A[i] < B[j]) {
      diff[k++] = A[i];
    } else if (A[i] > B[j]) {
      j++;
    } else {
      i++;
      j++;
    }
  }

  for (; i < n; i++) {
    diff[k++] = A[i];
  }

  return diff;
}

// for sorted array
int findMissin(int A[], int n) {
  int sum = 0;
  int diff = (A[n - 1] * (A[n - 1] + 1)) / 2;

  for (int i = 0; i < n; i++) {
    sum = sum + A[i];
  }

  return diff - sum;
}

int findMissinRec(int A[], int n) {
  static int sum = 0;
  int diff = A[n - 1] * A[n - 1] + 1 / 2;

  if (n < 0) {
    return diff - sum;
  }

  findMissinRec(A, n - 1);
}

// for sorted array
int find(int A[], int n) {
  int diff = A[0];

  for (int i = 0; i < n; i++) {
    if (A[i] - i != diff) return diff + i;
  }
}

int maxN(int A[], int n) {
  int max = A[0];

  for (int i; i < n; i++) {
    if (A[i] > max) {
      max = A[i];
    }
  }

  return max;
}

void fill(int A[], int n, int x) {
  for (int i = 0; i < n; i++) {
    A[i] = x;
  }
}

int findHash(int A[], int n) {
  int greater = maxN(A, n);
  int cache[greater];
  fill(cache, greater, 0);

  for (int i = 0; i < n; i++) {
    cache[A[i]]++;
  }

  for (int j = 1; j < greater; j++) {
    if (cache[j] == 0) {
      return j;
    }
  }
  return -1;
}

void swae(char S[], int n, int m) {
  char temp = S[n];
  S[n] = S[m];
  S[m] = temp;
}

void perm(char S[], int l, int r) {
  if (l == r) {
    printf("%s\n", S);
  }

  for (int i = l; i <= r; i++) {
    swae(S, l, i);
    perm(S, l + 1, r);
    swae(S, l, i);
  }
}

int main() {
  struct Array arr = {5, 20, {1, 2, 3, 4, 5}};
  int A[] = {1, 2, 3, 5};
  int B[] = {2, 5, 6};
  int C[10];

  char name[] = "abc";
  perm(name, 0, 3);
  // printf("%s", name);

  // printf("%d",findMissin(A, 4));
  // printf("%d",findMissinRec(A, 4));
  // printf("%d", find(A, 4));

  // int *C = merge(A, 3, B, 3);
  // int *D = un(A, 3, B, 3);
  // int *E = intsec(A, 3, B, 3);
  // int *F = diff(A, 3, B, 3);
  // merge(A, 3, B, 3, C);
  // c_print(C, 6);

  // c_print(F, 4);
  // push(&arr, 6);
  // insert(&arr, 2, 10);
  // insertTwo(&arr, 3, 11);
  // delete(&arr, 1);
  // pop(&arr);
  // set(&arr, 0, 100);
  // swap(&arr, 0, arr.length - 1);
  // reverse(&arr);
  // reverseRecurse(&arr, 0, arr.length - 1);

  // printf("%d", sum(arr2, 4));
  // shiftLeft(arr2, 3);
  // print(arr);
  return 0;
}
