#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"structure.h"
#include"init.h"
void init(card* stoke,int d){
    stoke->suit=malloc(sizeof(int)*(unsigned long)(d*53));
    if(stoke->suit==NULL) exit(-1);
    stoke->rank=malloc(sizeof(int)*(unsigned long)(d*53));
    if(stoke->rank==NULL) exit(-1);
    int p=0;int i=0,j=0,q=0;
    for(i=1;i<=4;i++){
        for(j=2;j<=14;j++){
            for (q=1;q<=d;q++){
                stoke->suit[p]=i;
                stoke->rank[p]=j;
                p++;
                stoke->total=p;
            }
        }
    }
}

void initdis(card* discard){
    discard->suit=malloc(sizeof(int));
    if(discard->suit==NULL) exit(-1);
    discard->rank=malloc(sizeof(int));
    if(discard->suit==NULL) exit(-1);
}


plyr* init_plyr(int num){
    plyr *head=0,*tmp=0,*p=0;int i=0;
    head=(plyr*)calloc(1,sizeof(plyr));
    if(head==NULL) exit(-1);
    head->next=(plyr*)calloc(1,sizeof(plyr));
    if(head->next==NULL) exit(-1);
    head->total=0;
    head->at=0;
    head->score=0;
    tmp=head;
    head->no=i;
    p=head->next;
    for(i=1;i<num-1;i++){
        p->pre=tmp;
        p->at=0;
        p->total=0;
        p->score=0;
        p->next=(plyr*)calloc(1,sizeof(plyr));
        if(p->next==NULL) exit(-1);
        p->no=i;
        tmp=p;
        p=p->next;
    }
    p->next=head;
    p->total=0;
    p->score=0;
    p->at=0;
    p->pre=tmp;
    tmp=p;
    p->no=i;
    p=p->next;
    p->pre=tmp;
    return head;
}


void end_round(plyr* player,int num,card* stoke,card* discard){
    int i=0;
    for(i=0;i<num;i++){
        player->score=player->total+player->score;
        player->total=0;
        player=player->next;
    }
    free(stoke->rank);free(stoke->suit);stoke->total=0;
    free(discard->rank);free(discard->suit);discard->total=0;
    free(stoke);free(discard);
}

void end_game(plyr* player,int num){
    int i=0;plyr* tmp=0;
    for(i=0;i<num-1;i++){
        tmp=player;
        player=player->next;
        free(tmp);
    }
    free(player);
    printf("congratulations!");
}




