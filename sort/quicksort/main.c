#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h; 
    ;

    do {
        do {
            i++;
        } while (A[i] <= pivot);
        do {
            j--;
        } while (A[j] > pivot);

        if (i < j) {
            swap(&A[i], &A[j]);
        }
    } while (i < j);

    swap(&A[l], &A[j]);

    return j;
}

void quickSort(int *A, int l, int h) {
    int j;
    if (l < h) {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
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
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT32_MAX}, n = 11, i;

    printArray(A, n - 1);
    quickSort(A, 0, 10);
    printArray(A, n - 1);
    return 0;
}