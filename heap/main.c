#include <stdlib.h>
#include <stdio.h>

typedef struct Heap {
    int size;
    int capacity;
    int *data;
} Heap;



Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    
    heap->size = 0;
    heap->capacity = capacity;
    heap->data = (int*)malloc(sizeof(int) * capacity);
    if (heap->data == NULL) {
        perror("Memory allocation error");
        free(heap);
        exit(EXIT_FAILURE);
    }

    return heap;

}

void insert(Heap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    int index = heap->size;
    heap->data[index] = value;
    heap->size++;

    while (index > 0 && heap->data[index] > heap->data[(index - 1) / 2]) {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Heap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;

    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapify(heap, largest);
    }
}

int main() {

    printf("hellow world");
    return 0;
}
