#include <stdio.h>
#include <stddef.h>

struct rec{
    int *a;
    float b;
    char c;
    short d;
    long e;
    double f;
    int g;
    char *h;
};

int main() {
    // Write C code here
    printf("a\tb\tc\td\te\tf\tg\th\n");
    printf("%u\t%u\t%u\t%u\t%u\t%u\t%u\t%u\n", offsetof(struct rec, a), offsetof(struct rec, b), offsetof(struct rec, c), offsetof(struct rec, d), offsetof(struct rec, e), offsetof(struct rec, f), offsetof(struct rec, g), offsetof(struct rec, h));

    return 0;
}

/*
RESULT:
a	b	c	d	e	f	g	h
0	8	12	14	16	24	32	40
*/
