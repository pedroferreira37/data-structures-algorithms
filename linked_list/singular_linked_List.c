#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

/*


*/

void create(int A[], int n) {
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

struct Node *_create(int A[], int n) {
  int i;
  struct Node *t, *p, *last;
  p = (struct Node *)malloc(sizeof(struct Node));
  p->data = A[0];
  p->next = NULL;
  last = p;

  for (i = 1; i < n; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }

  return p;
}

int count(struct Node *p) {
  int l = 0;
  while (p) {
    l++;
    p = p->next;
  }
  return l;
}
int Rcount(struct Node *p) {
  if (p != NULL)
    return Rcount(p->next) + 1;
  else
    return 0;
}
int sum(struct Node *p) {
  int s = 0;

  while (p != NULL) {
    s += p->data;
    p = p->next;
  }
  return s;
}
int Rsum(struct Node *p) {
  if (p == NULL)
    return 0;
  else
    return Rsum(p->next) + p->data;
}
void Display(struct Node *p) {
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}
void Insert(struct Node *p, int index, int x) {
  struct Node *t;
  int i;

  if (index < 0 || index > count(p)) return;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  if (index == 0) {
    t->next = first;
    first = t;
  } else {
    for (i = 0; i < index - 1; i++) p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

int RMax(struct Node *p) {
  int x = 0;

  if (p == 0) return INT32_MIN;
  x = RMax(p->next);
  if (x > p->data)
    return x;
  else
    return p->data;
}

struct Node *LSearch(struct Node *p, int key) {
  struct Node *q;

  while (p != NULL) {
    if (key == p->data) {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}
struct Node *RSearch(struct Node *p, int key) {
  if (p == NULL) return NULL;
  if (key == p->data) return p;
  return RSearch(p->next, key);
}

void insertSort(struct Node *p, int x) {
  struct Node *t, *q = NULL;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  if (first == NULL) {
    first = t;
  } else {
    while (p && p->data < x) {
      q = p;
      p = p->next;
    }

    if (p == first) {
      t->next = first;
      first = t;
    } else {
      t->next = q->next;
      q->next = t;
    }
  }
}

int Delete(struct Node *p, int ix) {
  struct Node *q;
  int x = -1;

  if (ix < 1 || ix > count(p)) {
    return -1;
  }

  if (ix == 1) {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  } else {
    for (int i = 0; i < ix - 1; i++) {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int isSorted(struct Node *p) {
  int x = -65536;

  while (p != NULL) {
    if (p->data < x) return 0;
    x = p->data;
    p = p->next;
  }
  return 1;
}

void RemoveDuplicate(struct Node *p) {
  struct Node *q = p->next;

  while (q != NULL) {
    if (p->data != q->data) {
      p = q;
      q = q->next;
    } else {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}

void Reverse1(struct Node *p) {
  int *A, i = 0;
  struct Node *q = p;

  A = (int *)malloc(sizeof(int) * count(p));

  while (q != NULL) {
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q != NULL) {
    q->data = A[i];
    q = q->next;
    i--;
  }
}
void Reverse2(struct Node *p) {
  struct Node *q = NULL, *r = NULL;

  while (p != NULL) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}
void Reverse3(struct Node *q, struct Node *p) {
  if (p) {
    Reverse3(p, p->next);
    p->next = q;
  } else
    first = q;
}

void concat(struct Node *p, struct Node *q) {
  third = p;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = q;
}

void _mergeL(struct Node *p, struct Node *q) {
  struct Node *last;
  if (p->data < q->data) {
    third = last = p;
    p = p->next;
    third->next = NULL;
  } else {
    third = last = q;
    q = q->next;
    third->next = NULL;
  }

  while (p && q) {
    if (p->data < q->data) {
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    } else {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if (p) {
    last->next = p;
  }
  if (q) {
    last->next = q;
  }
}

int isLoop(struct Node *f) {
  struct Node *p, *q;
  p = q = f;

  do {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while (p && q && p != q);

  if (p == q)
    return 1;
  else
    return 0;
}

int Length(struct Node *p) {
  int len = 0;
  do {
    len++;
    p = p->next;

  } while (p != Head);
  return len;
}

void InsertCircular(struct Node *p, int index, int x) {
  struct Node *t;
  int i;
  if (index < 0 || index > Length(p)) return;

  if (index == 0) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (Head == NULL) {
      Head = t;
      Head->next = Head;
    } else {
      while (p->next != Head) p = p->next;
      p->next = t;
      t->next = Head;
      Head = t;
    }

  } else {
    for (i = 0; i < index - 1; i++) p = p->next;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = p->next;
    p->next = t;
  }
}

int Delete(struct Node *p, int ix) {
  struct Node *q;
  int i, x;

  if (ix < 0) return -1;

  if (ix == 1) {
    while (p->next != Head) {
      p = p->next;
    }
    x = Head->data;
    if (Head == p) {
      free(p);
      Head = NULL;
    } else {
      for (i = 0; i < ix - 2; i++) {
        p = p->next;
      }
      q = p->next;
      p->next = q->next;
      x = q->data;
      free(q);
    }
  }
  return x;
}

int main() {
  struct Node *t1, *t2;
  int A[] = {2, 4, 6, 7, 9};
  create(A, 5);
  struct Node *Head = _create(A, 5);

  t1 = Head->next->next;
  t2 = Head->next->next->next->next;
  t2->next = t1;
  InsertCircular(Head, 2, 8);
  Display(Head);

  return 0;
}
