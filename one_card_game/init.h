#ifndef init0
#define init0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include "structure.h"
void init(card* stoke,int d);
void initdis(card* discard);
plyr* init_plyr(int num);
void end_round(plyr* player,int num,card* stoke,card* discard);
void end_game(plyr* player,int num);
#endif
