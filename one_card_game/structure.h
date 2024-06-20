#ifndef functions
#define functions
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
typedef struct _card{
    int* rank;
    int* suit;
    int total;
}card;
typedef struct _plyr{
    int rank[1000];
    int suit[1000];
    int total;
    int score;
    int no;
    int at;
    struct _plyr* next;
    struct _plyr* pre;
}plyr;
#endif 