#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <getopt.h>
#include<string.h>
#include"init.h"
#include"structure.h"
#include"functions.h"
#include"write.h"
int main(int argc, char *argv[]){
    int d=0,round=0,num=0,r0=0,r=0,i=0,j=0,leap=0,step=1,out=0,pun=0,pre_suit=0,pre_rank=0,p=0,min=9999,winner[12]={0},winner_num=0,c=0,op=0,flag=0;char s[100];card* stoke=0;card* discard=0;plyr* player=0;plyr* start=0;FILE* fp=0;srand((unsigned)time(NULL));round=1;d=2;num=4;c=5;op=0;r=1;r0=0;int a=0;
    int option_index = 0, opt=0;
    struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"log filename", required_argument, NULL,'l'},
        {"player-number", required_argument, NULL,'n'},
        {"initial-card",required_argument,NULL,'c'},
        {"desk",required_argument,NULL,'d'},
        {"round",required_argument,NULL,'r'},
        {"auto",no_argument,NULL,'a'},
        {NULL, 0, NULL, 0}};
        while((opt =getopt_long(argc, argv, "hl:n:c:d:r:a", long_options, &option_index))!= -1) {
        switch (opt) {
                case 'h': printf("-h|--help print this help message\n--log filename write the logs in filename (default: onecard.log)\n-n n|--player-number=n n players, n must be larger than 2 (default: 4)\n-c c|--initial-cards=c deal c cards per player, c must be at least 2 (default: 5)\n-d d|--decks=d use d decks 52 cards each, d must be at least 2 (default: 2)\n-r r|--rounds=r play r rounds, r must be at least 1 (default: 1)\n-a|--auto run in demo mode\n"); break;
                case 'l':fp=fopen(optarg,"w+");op=1;break;
                case 'n':num=atoi(optarg);break;
                case 'c':c=atoi(optarg);break;
                case 'd':d=atoi(optarg);break;
                case 'r':round=atoi(optarg);break;
                case 'a':a=1;break;
                default: printf("Invalid.\n");
            }
        }
    player=init_plyr(num);
    if(a==1){for(i=0;i<num;i++){player->at=1;player=player->next;}}//initliaze the player,judge if the game run in demo.
    printf("GAME START\n\n");if(op==1) fprintf(fp,"GAME START\n\n");
    while(r0<round){
        stoke=(card*)calloc(1,sizeof(card));if(stoke==NULL) exit(-1);
        discard=(card*)calloc(1,sizeof(card));if(discard==NULL) exit(-1);
        printf("Filelog name:%s.\nPlayer number:%d.\nInitial card number:%d.\nDesk of card(52cards each):%d.\nGame round:%d.\n",s,num,c,d,round);
        if(op==1) fprintf(fp,"Filelog name:%s.\nPlayer number:%d.\nInitial card number:%d.\nDesk of card(52cards each):%d.\nGame round:%d.\n",s,num,c,d,round);
        if(player->at==0){int ch=getchar();ch=ch;}
        system("clear");
        printf("ROUND %d\n",r0+1);if(player->at==0){int ch=getchar();ch=ch;}if(op==1) fprintf(fp,"ROUND%d\n\n",r0+1);
        init(stoke,d);if(op==1) fprintf(fp,"initilize...\n");
        r0=r;leap=0;pun=0;step=1;//step means the direction is going to;leap means the next player will be leaped.
        shuffle(stoke);if(op==1)fprintf(fp,"shuffling...\n");
        if(op==1){
            for(i=0;i<stoke->total;i++){
                ftrans1(stoke->suit[i],fp);ftrans2(stoke->rank[i],fp);
            }fprintf(fp,"\n");
        }
        for(i=0;i<c;i++){
            for(j=0;j<num;j++){draw(stoke,player);player=player->next;}
        }
        if(op==1){
            fprintf(fp,"dealing with cards...\n");
            for(i=0;i<num;i++){
                fprintf(fp,"Player%d:",player->no+1);
                for(j=0;j<player->total;j++){ftrans1(player->suit[j],fp);ftrans2(player->rank[j],fp);}
                fprintf(fp,"\n");
                player=player->next;
            }
        }
        start=first(stoke,player,num,discard);
        if(op==1){
            fprintf(fp,"deciding the first one...\n");
            for(i=0;i<num;i++){fprintf(fp,"Player%d:",player->no+1);ftrans1(discard->suit[i],fp);ftrans2(discard->rank[i],fp);fprintf(fp,"\n");player=player->next;}
        }
        player=start;//to give the start point to the player.
        printf("start with player%d.\n",player->no+1);
        if(op==1){fprintf(fp,"start at player%d\n.",player->no+1);}
        p=first_card(stoke,discard,player);pre_suit=p/15;pre_rank=p%15;
        paint_card(pre_suit,pre_rank);
        if(player->at==0){int ch=getchar();ch=ch;}
        if(op==1){fprintf(fp,"start at card:");ftrans1(pre_suit,fp);ftrans2(pre_rank,fp);fprintf(fp,"\n");}
            while(r==r0){
                system("clear");
                printf("ROUND %d\n\n",r0);
                printf("\n previous card is:");trans1(pre_suit);trans2(pre_rank);
                if(stoke->total==0){reset(stoke,discard);fprintf(fp,"reset the stoke\n");}
                printf("player %d your card:\n",player->no+1);
                print_plyr(player);
                if(leap==1){
                    printf("player %d, your turn is skipped\n",player->no+1);
                    if(op==1) fprintf(fp,"player %d, your turn is skipped\n",player->no+1);
                    leap=0;
                    if(player->at==0){int ch1=getchar();ch1=ch1;ch1=getchar();ch1=ch1;}
                    r=move(&player,step,r);
                }
                else{
                    if(player->at==0){scanf("%d",&out);}
                    else {out=search_card(player,pre_suit,pre_rank);} 
                    if(out==0){
                        if(pun==0){
                            if(op==1) {fprintf(fp,"player%d draw card:",player->no+1);ftrans1(stoke->suit[0],fp);ftrans2(stoke->rank[0],fp);fprintf(fp,"\n");}
                            draw(stoke,player);if(op==1) fprint_plyr(fp,player);
                            r=move(&player,step,r);
                        }
                        else if(pun>0){
                            if(op==1) fprintf(fp,"player%d draw card:",player->no+1);
                            while(pun>0){
                                if(op==1){ftrans1(stoke->suit[0],fp);ftrans2(stoke->rank[0],fp);}
                                draw(stoke,player);
                                if(stoke->total==0){reset(stoke,discard);
                                if(op==1) fprintf(fp,"reset the stoke\n");}
                                pun--;player=player;
                            }
                            if(op==1) {fprintf(fp,"\n");fprint_plyr(fp,player);}
                        }
                    }
                    else if(out!=0){
                        if(judge(player->suit[out-1],pre_suit,player->rank[out-1],pre_rank)==0||out>player->total||out<1){
                            printf("wrong card.\n");
                        }
                        else{
                            if(op==1) {fprintf(fp,"player%d plays:",player->no+1);ftrans1(player->suit[out-1],fp);ftrans2(player->rank[out-1],fp);fprintf(fp,"\n");}
                            if(pun>0){
                                if(player->rank[out-1]==2||player->rank[out-1]==3){
                                    pun=pun+player->rank[out-1];pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    r=move(&player,step,r);
                                }
                                else if(player->rank[out-1]==7){
                                    pun=0;pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    if(player->total==0) r++;
                                    printf("Do you want to play one more card?1 for yes,0 for no.");
                                    if(player->at==0){scanf("%d",&flag);}
                                    else{
                                        if(search_card(player,pre_suit,pre_rank)!=0){ flag=1;}
                                        else if(search_card(player,pre_suit,pre_rank)==0){flag=0;}
                                        }
                                    if(flag==0) r=move(&player,step,r);
                                    if(flag==1) player=player;
                                }
                                else if(player->rank[out-1]==12){
                                    step=-step;pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    r=move(&player,step,r);
                                }
                                else{
                                    if(op==1) fprintf(fp,"player%d draw card:",player->no+1);
                                    pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    if(player->rank[out-1]==11) leap=1;
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    while(pun>0){
                                        if(op==1){ftrans1(stoke->suit[0],fp);ftrans2(stoke->rank[0],fp);}
                                        draw(stoke,player);
                                        if(stoke->total==0){reset(stoke,discard);}
                                        pun--;player=player;
                                    }
                                    if(op==1) {fprint_plyr(fp,player);fprintf(fp,"\n");}
                                    r=move(&player,step,r);
                                }
                            }
                            else{
                                if(player->rank[out-1]==2||player->rank[out-1]==3){
                                    pun=player->rank[out-1];pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    r=move(&player,step,r);
                                }
                                else if(player->rank[out-1]==12){
                                    step=-step;if(op==1) fprintf(fp,"change direction!\n");pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    r=move(&player,step,r);
                                }
                                else if(player->rank[out-1]==11){
                                    leap=1;pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    r=move(&player,step,r);                                
                                }
                                else{
                                    pre_suit=player->suit[out-1];pre_rank=player->rank[out-1];
                                    pcard(discard,player,out);if(op==1) fprint_plyr(fp,player);
                                    r=move(&player,step,r);
                                }
                            }
                        }
                    }
                }                               
            }
    end_round(player,num,stoke,discard);
    if(op==1) fprintf(fp,"end round\n");
    }
    system("clear");
    winner_num=0;min=player->score;winner[0]=player->no+1;winner_num=1;
    printf("player%d score=%d\n",player->no+1,player->score);if(op==1) fprintf(fp,"player%d score=%d\n",player->no+1,player->score);
    player=player->next;
    for(i=0;i<num-1;i++){
        printf("player%d score=%d\n",player->no+1,player->score);
        if(op==1) fprintf(fp,"player%d score=%d\n",player->no+1,player->score);
        if(min==player->score){
                winner[winner_num]=player->no+1;winner_num++;
            }//if the cards left are the same and the least,then record them all.
        else if(min>player->score){
                winner[0]=player->no+1;min=player->score;winner_num=1;
            }//if the player's cards is less than min,adjust it as the less and clear the contain.
        player=player->next;
    }
    printf("The winner of the game is:");if(op==1) fprintf(fp,"The winner of the game is:");
    for(i=0;i<winner_num;i++){
        printf("player %d ",winner[i]); 
        if(op==1) fprintf(fp,"player %d ",winner[i]);
    }
    if(op==1){fclose(fp);}
    end_game(player,num);
    return 0;
}
