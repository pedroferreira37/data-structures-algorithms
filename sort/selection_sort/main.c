#include <stdlib.h>
#include <stdio.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *A, int n) {
    int i, j, k;

    for(i = 0; i < n - 1; i++) {
        for(j = k = 1; j < n; j++) {
            if(A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int main() {
    return 0;
}

