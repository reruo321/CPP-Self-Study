#include <stdio.h>
#include <stddef.h>

struct P1{
    short i;
    int c;
    int *j;
    short *d;
};

struct P4{
    char w[16];
    char *c[2];
};

struct P5{
    struct P4 a[2];
    struct P1 t;
};

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

struct rec2{
    int *a;
    char *h;
    double f;
    long e;
    float b;
    int g;
    short d;
    char c;
};

int main()
{
    printf("i\tc\tj\td\tsize\n");
    printf("%lu\t%lu\t%lu\t%lu\t%lu\n\n",
    offsetof(struct P1, i),
    offsetof(struct P1, c),
    offsetof(struct P1, j),
    offsetof(struct P1, d),
    sizeof(struct P1));
    
    printf("w\tc\tsize\n");
    printf("%lu\t%lu\t%lu\n\n",
    offsetof(struct P4, w),
    offsetof(struct P4, c),
    sizeof(struct P4));
    
    printf("P4\tP1\tsize\n");
    printf("%lu\t%lu\t%lu\n\n",
    offsetof(struct P5, a),
    offsetof(struct P5, t),
    sizeof(struct P5));
    
    printf("a\tb\tc\td\te\tf\tg\th\tsize\n");
    printf("%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\n\n",
    offsetof(struct rec, a),
    offsetof(struct rec, b),
    offsetof(struct rec, c),
    offsetof(struct rec, d),
    offsetof(struct rec, e),
    offsetof(struct rec, f),
    offsetof(struct rec, g),
    offsetof(struct rec, h),
    sizeof(struct rec));
    
    printf("a\th\tf\te\tb\tg\td\tc\tsize\n");
    printf("%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\t%lu\n\n",
    offsetof(struct rec2, a),
    offsetof(struct rec2, h),
    offsetof(struct rec2, f),
    offsetof(struct rec2, e),
    offsetof(struct rec2, b),
    offsetof(struct rec2, g),
    offsetof(struct rec2, d),
    offsetof(struct rec2, c),
    sizeof(struct rec2));

    return 0;
}

/*
Practice 3.44 and 3.45 from Computer Systems - A Programmer's Perspective
*/
