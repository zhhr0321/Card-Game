#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"structure.h"
#include"functions.h"
#include"write.h"
void shuffle(card *stoke){
    int a=0,b=0,num=0,temp=0,i=0;
    num=stoke->total;
    for(i=1;i<=num*10;i++){
        a=rand()%num;
        b=rand()%num; 
        temp=stoke->rank[a]; stoke->rank[a]=stoke->rank[b]; stoke->rank[b]=temp;
        temp=stoke->suit[a]; stoke->suit[a]=stoke->suit[b]; stoke->suit[b]=temp;
    }
}

void draw(card *stoke,plyr *player){
    int m=0,n=0,i=0,j=0,k=0;
    m=(stoke)->rank[0];n=(stoke)->suit[0];i=0;j=0;
    if(player->total==0){
        player->total=1;
        player->suit[0]=n;
        player->rank[0]=m;
    }
    else{
         while(i<player->total&&(n>player->suit[i]||(n==player->suit[i]&&player->rank[i]<m)))
            i++;
        k=i;
        for(j=player->total;j>=k;j--){
            player->rank[j+1]= player->rank[j];
            player->suit[j+1]= player->suit[j];
        }
        player->rank[k]=m;
        player->suit[k]=n;
        player->total=player->total+1;
    }
    for (j=1;j<stoke->total;j++)
    {
        stoke->rank[j-1]=stoke->rank[j];
        stoke->suit[j-1]=stoke->suit[j];
    }
    stoke->total=stoke->total-1;
    if(stoke->total!=0){
        stoke->rank=realloc(stoke->rank,(unsigned long)(stoke->total)*sizeof(int));
        if (stoke->rank==NULL) exit(-1);
        stoke->suit=realloc(stoke->suit,(unsigned long)(stoke->total)*sizeof(int));
        if(stoke->suit==NULL) exit(-1);
    }
    else{
        stoke->rank=realloc(stoke->rank,(unsigned long)((stoke->total)+1)*sizeof(int));
        if (stoke->rank==NULL) exit(-1);
        stoke->suit=realloc(stoke->suit,(unsigned long)((stoke->total)+1)*sizeof(int));
        if(stoke->suit==NULL) exit(-1);
    }
}

void pcard(card* discard,plyr* player,int i){
    int n=0;
    discard->rank=realloc(discard->rank,(unsigned long)(discard->total+1)*sizeof(int));
    if(discard->rank==NULL) exit(-1);
    discard->suit=realloc(discard->suit,(unsigned long)(discard->total+1)*sizeof(int));
    if(discard->suit==NULL) exit(-1);
    discard->total=discard->total+1;
    n=discard->total;
    discard->rank[n-1]=player->rank[i-1];
    discard->suit[n-1]=player->suit[i-1];
    n=0;int j=0;
    n=player->total;
    if(n==1){
        player->total=0;
        printf("you win this round!");
        if(player->at==0){int ch1=getchar();ch1=ch1;ch1=getchar();ch1=ch1;}
    }
    else{
        for(j=i;j<n;j++){
            player->rank[j-1]=player->rank[j];
            player->suit[j-1]=player->suit[j];
        }
        player->total=player->total-1;
    }
}

void reset(card* stoke,card* discard){
    int i=0;
    stoke->rank=realloc(stoke->rank,(unsigned long)(discard->total+1)*sizeof(int));
    if(stoke->rank==NULL) exit(-1);
    stoke->suit=realloc(stoke->suit,(unsigned long)(discard->total+1)*sizeof(int));
    if(stoke->suit==NULL) exit(-1);
    for(i=0;i<discard->total;i++){
        stoke->rank[i]=discard->rank[i];
        stoke->suit[i]=discard->suit[i];        
    }
    stoke->total=discard->total;
    discard->total=0;
    discard->rank=realloc(discard->rank,sizeof(int));
    if(discard->rank==NULL) exit(-1);
    discard->suit=realloc(discard->suit,sizeof(int));
    if(discard->suit==NULL) exit(-1);
}

int judge(int suit1,int suit2,int rank1,int rank2){
    if (suit1==suit2) return 1;
    else if (rank1==rank2) return 1;
    else return 0;

}

int sumcard(int i,int j){
    int f=0;
    f=15*i+j;
    return f;
}

plyr* first(card* stoke,plyr* player,int num,card* discard){
    plyr* start=0;int i=0,turn=0,max=0,t=0;
    discard->suit=realloc(discard->suit,sizeof(int)*(unsigned long)(num+1));
    if(discard->suit==NULL) exit(-1);
    discard->rank=realloc(discard->rank,sizeof(int)*(unsigned long)(num+1));
    if(discard->rank==NULL) exit(-1);
    for(i=0;i<num;i++){
        discard->suit[i]=stoke->suit[i];
        discard->rank[i]=stoke->rank[i];       
    }
    discard->total=num;
    for(i=0;i<(stoke->total)-num;i++){
        stoke->suit[i]=stoke->suit[i+num];
        stoke->rank[i]=stoke->rank[i+num];
    }
    stoke->total=stoke->total-num;
    stoke->rank=realloc(stoke->rank,(unsigned long)(stoke->total+1)*sizeof(int));
    if(stoke->rank==NULL) exit(-1);
    stoke->suit=realloc(stoke->suit,(unsigned long)(stoke->total+1)*sizeof(int));
    if(stoke->suit==NULL) exit(-1);
    turn=0;max=0;
    for(i=0;i<num;i++){
        printf("Player%d:",i+1);trans1(discard->suit[i]);trans2(discard->rank[i]);
        t=sumcard(discard->suit[i],discard->rank[i]);
        if(t>max){
            turn=i;
            max=t;
        }
    }
    for(i=0;i<turn;i++){
        player=player->next;
    }
    start=player;
    if(player->at==0){int ch=getchar();ch=ch;}
    return start;
}

int first_card(card* stoke,card* discard,plyr* player){
    int t=0,i=0;
    t=sumcard(stoke->suit[0],stoke->rank[0]);
    discard->suit[discard->total]=stoke->suit[0];
    discard->rank[discard->total]=stoke->rank[0];
    printf("first card:");trans1(stoke->suit[0]);trans2(stoke->rank[0]);
    stoke->total=stoke->total-1;
    for(i=0;i<stoke->total;i++){
        stoke->suit[i]=stoke->suit[i+1];
        stoke->rank[i]=stoke->rank[i+1];
    }
    if(player->at==0){int ch=getchar();ch=ch;}
    return t;
}

int search_card(plyr* player,int suit,int rank){
    int i=0;
    for(i=0;i<player->total;i++){
        if(player->suit[i]==suit||player->rank[i]==rank) return(i+1);
    }
    return 0;
}

int move(plyr** player,int step,int r){
    if((*player)->total==0) r++;
    if(step==1) {
        (*player)=(*player)->next;
    }
    else if(step==-1) {
        (*player)=(*player)->pre;
    }
    return r;
}