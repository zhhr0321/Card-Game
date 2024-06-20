#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"structure.h"
#include"write.h"
void trans1(int m){
    switch (m){
        case 1: printf("Spades   ");break;
        case 2: printf("Hearts   ");break;
        case 3: printf("Diamonds ");break;
        case 4: printf("Clubs    ");break;
    }
}
void trans2(int m){
    switch (m) {
    case 14: printf("Ace\n"); break;
    case 13: printf("King\n"); break;
    case 12: printf("Queen\n"); break;
    case 11: printf("Jack\n"); break;
    default: printf("%d\n",m);
    }
}

void ftrans1(int m,FILE* fp){
    switch (m){
        case 1: fprintf(fp,"Spades ");break;
        case 2: fprintf(fp,"Hearts ");break;
        case 3: fprintf(fp,"Diamonds ");break;
        case 4: fprintf(fp,"Clubs ");break;
    }
}
void ftrans2(int m,FILE* fp){
    switch (m) {
    case 14: fprintf(fp,"Ace   "); break;
    case 13: fprintf(fp,"King  "); break;
    case 12: fprintf(fp,"Queen "); break;
    case 11: fprintf(fp,"Jack  "); break;
    default: fprintf(fp,"%d  ",m);
    }
}

void trans_2(int m){
    switch (m) {
    case 14: printf("Ace  "); break;
    case 13: printf("King "); break;
    case 12: printf("Queen"); break;
    case 11: printf("Jack "); break;
    default: printf("  %d  ",m);
    }
}



void print_plyr(plyr* player){
    int i=0;
    for(i=0;i<player->total;i++){
        printf("%d ",i+1);trans1(player->suit[i]);trans2(player->rank[i]);
    }
}

void fprint_plyr(FILE* fp,plyr* player){
    int i=0;
    fprintf(fp,"player%d:",player->no+1);
    for(i=0;i<player->total;i++){
        ftrans1(player->suit[i],fp);ftrans2(player->rank[i],fp);
    }
    fprintf(fp,"\n");
}

void print_pile(card* stoke){
    int i=0;
    for(i=0;i<stoke->total;i++){
        trans1(stoke->suit[i]);trans2(stoke->rank[i]);
    }
}

void paint_card(int suit,int rank){ 
    printf(" ------------\n");printf("|            |\n");printf("|            |\n");printf("|            |\n");printf("|  ");trans1(suit);printf(" |\n");printf("|   ");trans_2(rank);printf("    |\n");printf("|            |\n");printf("|            |\n");printf(" ------------\n");
}