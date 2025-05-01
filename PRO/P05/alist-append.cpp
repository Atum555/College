#include "alist.h"

void append(alist *a, const alist *b) {
    int  newSize = a->size + b->size;
    int *p       = new int[newSize];
    for (int i = 0; i < a->size; i++) p[i] = a->elements[i];
    for (int i = a->size; i < newSize; i++) p[i] = b->elements[i - (a->size)];
    delete[] a->elements;
    a->elements = p;
    a->size     = newSize;
}
