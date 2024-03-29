#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


void create(struct Queue *q, int size) {
  q->size = size;
  q->front = q->rear = -1;
  q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

void enqueue(struct Queue *q, Node *x) {
  if ((q->rear + 1) % q->size == q->front) {
    printf("full");
  } else {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}
Node *dequeue(struct Queue *q) {
  Node *x = NULL;

  if (q->rear == q->front) {
    printf("Queue is empty");
  } else {
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
  }
  return x;
}


int isEmpty(struct Queue q) { return q.front - 1 == q.rear - 1; }

