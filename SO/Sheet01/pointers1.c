#include <stdio.h>

int main() {
    int i, j, *p, *q;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    i = 5;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    p = &i;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    *p = 7;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    j = 3;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    p = &j;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    q = p;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    p = &i;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    *q = 2;
    printf("i=%d, j=%d, p=%p, q=%p, *p=%d, *q=%d\n", i, j, p, q, *p, *q);
    return 0;
}
