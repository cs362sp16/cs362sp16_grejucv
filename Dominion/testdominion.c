#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"
#include <time.h>


void shuffleDeck(int *array, size_t n){
    if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++){
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int argc, char *argv[] ){
    srand(time(NULL));
    
    struct gameState G;
    int k[10] = {adventurer, gardens, duchy, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

    //int mySeed = atoi(argv[1]);
    int randomSeed = rand() % 100;
    int num_players = rand() % 3 + 2;
    int currentPlayer, i, turnsPlayed = 0;
    int smithyPos = -1, adventurerPos = -1, minePos = -1, villagePos = -1;
    int winner = 0;
    
    shuffleDeck(k, 10);
    printf("Starting Dominion Game\n");
    initializeGame(num_players, k, randomSeed, &G);
    
    while(!isGameOver(&G)){
        smithyPos = -1, adventurerPos = -1, minePos = -1, villagePos = -1;
        int money 0; 
        currentPlayer = whoseTurn(&G);
        printf("Player %i turn\n", currentPlayer);
        
        for (i = 0; i < numHandCards(&G); i++) {
            if(handCard(i, &G) == copper){
                money++;
            }else if(handCard(i, &G) == silver){
                money += 2;
            }else if(handCard(i, &G) == gold){
                money += 3;
            }else if(handCard(i, &G) == adventurer){
                adventurerPos = i;
            }else if(handCard(i, &G) == smithy){
                smithyPos = i;
            }else if(handCard(i, &G) == village){
                villagePos = i;
            }else if(handCard(i, &G) == mine){
                minePos = i;
            }
        }
        
        if(villagePos != -1){
            playCard(villagePos, -1, -1, -1, &G);
            printf("Played village\n");
            int played = 0;
            while(i<numHandCards(&G)){
                if (handCard(i, &G) == copper){
                    playCard(i, -1, -1, -1, &G);
                    money++;
                }
                if (handCard(i, &G) == silver){
                    playCard(i, -1, -1, -1, &G);
                    money += 2;
                }
                if (handCard(i, &G) == gold){
                    playCard(i, -1, -1, -1, &G);
                    money += 3;
                }
                if (handCard(i, &G) == smithy && played < 2){
                    played++;
                    playCard(i, -1, -1, -1, &G);
                    printf("Played Smithy\n");
                    while(i<numHandCards(&G)){
                        if (handCard(i, &G) == copper){
                            playCard(i, -1, -1, -1, &G);
                            money++;
                        }
                        else if (handCard(i, &G) == silver){
                            playCard(i, -1, -1, -1, &G);
                            money += 2;
                        }
                        else if (handCard(i, &G) == gold){
                            playCard(i, -1, -1, -1, &G);
                            money += 3;
                        }
                        i++;
                    }
                }
                
                i++;
            }
        }else if(smithyPos != -1){
            playCard(smithyPos, -1, -1, -1, &G);
            printf("Played Smithy\n");
            while(i<numHandCards(&G)){
                if (handCard(i, &G) == copper){
                    playCard(i, -1, -1, -1, &G);
                    money++;
                }
                else if (handCard(i, &G) == silver){
                    playCard(i, -1, -1, -1, &G);
                    money += 2;
                }
                else if (handCard(i, &G) == gold){
                    playCard(i, -1, -1, -1, &G);
                    money += 3;
                }
                i++;
            }
        }else if(adventurerPos != -1){
            playCard(i, -1, -1, -1, &G);
            printf("Played adventurer");
        }
        printf("Player %i money count: %i\n", currentPlayer, G.coins);
        if(turnsPlayed > 4){
            if(money >= 8){
                buyCard(province, &G);
                printf("Province purchased\n");
            }else if(money >= 5){
                buyCard(duchy, &G);
                printf("Duchy purchased\n");
            }
        }
        
        if(money >=3){
            buyCard(gold, &G);
            printf("Gold purchased\n");
        }else if(money >=2){
            buyCard(silver, &G);
            printf("Silver purchased\n");
        }
        endTurn(&G);
        
        turnsPlayed++;
        printf ("Player %i Score: %i\n", currentPlayer, scoreFor(currentPlayer, &G));
        if(scoreFor(currentPlayer, &G) > winner){
            winner = currentPlayer;
        }
        shuffleDeck(k, 10);
    }
    printf("Player %i wins\n", winner);
    
}




