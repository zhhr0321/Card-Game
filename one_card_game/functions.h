#ifndef fun
#define fun
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include "structure.h"
#include"write.h"
void shuffle(card *stoke);
plyr* first(card* stoke,plyr* player,int num,card* discard);
void draw(card *stoke,plyr *player);
void pcard(card* discard,plyr* player,int i);
void reset(card* stoke,card* discard);
int judge(int suit1,int suit2,int rank1,int rank2);
int sumcard(int i,int j);
int first_card(card* stoke,card* discard,plyr* player);
int search_card(plyr* player,int suit,int rank);
int move(plyr** player,int step,int r);
#endif