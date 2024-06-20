#ifndef wr
#define wr
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include "structure.h"
void trans1(int m);
void trans2(int m);
void ftrans1(int m,FILE* fp);
void ftrans2(int m,FILE* fp);
void trans_2(int m);
void print_plyr(plyr* player);
void print_pile(card* stoke);
void paint_card(int suit,int rank);
void fprint_plyr(FILE* fp,plyr* player);
#endif