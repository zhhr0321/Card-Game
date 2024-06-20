# README
## p2 onecard
### basic infomations
- r rounds are taken.
- n nums of people pariticipate in the game.
- d means desk of cards.
- c means the cards you get at first.
- h can help you handle with som problem.
- I use dynamic arraies in the stoke and discard.
- double circle link list is used between the players.
### brief introduction of the functions
#### init.c
- init:intiliazation of the original stoke.
- initdis:intiliazation of the discard pile.
- init_plyr:create a double link list to connect the players.
- end_round:end the round,and free the stoke and discard,which is intiliazed in the begining of the round.
- end_game:free the players structure.
#### write.c
- trans1,trans2:turn the number of suit and rank into their names.
- fprintf1,fprintf2:turn the number into their names and write into the file.
- trans_2,paint:paint a card.
- print_card,print_pile:print the card of the stoke or a certain player.
#### functions.c
- shuffle:shuffle the stoke.
- first:to figure out the first person to play a card.
- draw:draw a card from the stoke and insert into the player's hand card in order.
- pcard:play a card with the certain number.
- reset:reset the stoke.
- judge:if the card meets the requirement to be the same with the previous in suit or rank.
- sumcard:to give a weight coefficent to suit,in order to better compare which card is bigger,and easier to insert the card when comparing.
- first_card:the card on the top of the stoke--to decide the first card.
- search_card:search the card that fit the requirmeen.(under the demo)
- move:to omve to the next player.(also judge if the player had played all its card before move.)
### basic rules
- you can play a card which is the same as the previous card's suit or rank.(typing the number before the card,for example, to play the first card you just type 1 and the enter to play the card.)
- Jack card can skipped your next player.
- Queen card can overturn the direction.
- 2 and 3 is attack,can add 2 and 3 card for the next each.the attack can be added or be defended or the queen card can replaced the punishment to the previous one.
- 7 defend card,can defend the attack.and if you successfully defend an attack you can choose whether to play another card.
- who has no card suitable to play ,input an 0 and will draw a card from the stoke.
- those who print 0 when being punished can draw first and play a card later.
- who play all the card first will win the round,and the round ended.
- the card in hand when a round ended will be added to the score,who got the lowest score win the game. 
### steps
- before the game come to the play part,just enter to see the next step.
- play card when it is your turn.
- remember that you can get a chance to play another card when a attack is defended by you. 
### tips&&bonus
- you can play two cards if you successfully defend a attack.(-a also can)
- you can paint a card at the begining,and it can b called in the main.However,due to it will hard to look your cards if paint all the cards,so I decided only to paint the first card as a example.