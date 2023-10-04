#include <stdlib.h>
#include <stdio.h>

void Merge(int A[], int l, int m, int h) {
    int i = l, j = m + 1, k = l;
    int B[100];
    
    while(i <= m && j <= h) {
        if(A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    for(; i <= m; i++) {
        B[k++] = A[i];
    }
for(; j <= m;j++) {
        B[k++] = A[j];
    }

for(int i = l; i <= h; i++) {
    A[i] = B[i];
}
}

void MergeSort(int A[], int n) {
     int p, l, h, m, i;
     
    for(p = 2; p <= n; p = p * 2) {
        for(i = 0; i + p - 1 <= n; i = i + p) {
            l = i;
            h = i + p - 1;
            m = (l + h) / 2;
            Merge(A, l, m, h);
        }
    }
    
    if(p / 2 < n) {
        Merge(A, 0, p/2 - 1, n);
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
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5,10, 3}, n = 10, i;
    
    printArray(A, n);
    MergeSort(A, n);
    printArray(A, n);

}