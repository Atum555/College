#include "list.h"
#include <stdio.h>
#include <stdlib.h>

node *node_new(int val, node *p) {
    node *q = (node *)malloc(sizeof(node));
    q->val  = val;
    q->next = p;
    return q;
}

list *list_new() {
    list *l  = (list *)malloc(sizeof(list));
    l->size  = 0;
    l->first = NULL;
    return l;
}

list *list_new_random(int size, int range) {
    list *l = list_new();
    int   i;
    for (i = 0; i < size; i++) list_add_first(rand() % range, l);
    return l;
}

void list_add_first(int val, list *l) {
    node *n  = node_new(val, l->first);
    l->first = n;
    l->size++;
}

void list_add_last(int val, list *l) {
    node *p = node_new(val, NULL);
    if (l->size == 0) {
        l->first = p;
    } else {
        node *q = l->first;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
    l->size++;
}

int list_get_first(list *l) {
    /* assumes list l is not empty */
    return l->first->val;
}

int list_get_last(list *l) {
    /* assumes list l is not empty */
    node *n = l->first;
    while (n->next != NULL) n = n->next;
    return n->val;
}

void list_remove_first(list *l) {
    /* assumes list l is not empty */
    node *p  = l->first;
    l->first = l->first->next;
    l->size--;
    /* free memory allocated for node p */
    free(p);
}

void list_remove_last(list *l) {
    /* assumes list l is not empty */
    node *n  = l->first;
    node *n1 = n->next;
    while (n1 != NULL) {
        n  = n1;
        n1 = n1->next;
    }
    n->next = NULL;
    l->size--;
    free(n1);
}

int list_size(list *l) { return l->size; }

void list_print(list *l) {
    printf("[");
    node *n = l->first;
    while (n != NULL) {
        printf("%d,", n->val);
        n = n->next;
    }
    printf("]\n");
}
