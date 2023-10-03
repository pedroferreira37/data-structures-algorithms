#include <stdlib.h>
#include <stdio.h>


void insertionSort(int *A, int n) {
    int i, j, x;
    for(i = 1; i < n; i++) {
        j = i - 1;
        x = A[i];
        
        while(j > - 1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
    A[j + 1] = x;
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
    int A[] = { 11, 13, 7,  2, 6, 9, 4, 5 , 10, 3}, n = 10;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}

