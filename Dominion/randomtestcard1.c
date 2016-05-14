#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "interface.h"
#include "dominion.h"

int main(){
    printf("random testing steward\n");
    int i, passed =0, failed = 0, test;
    srand(time(NULL));
    
    for(i=0; i<1000; i++){
        struct gameState G;
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	                 sea_hag, tribute, smithy};
        
        int num_players = rand() % 3 + 2;
        int Seed = rand() % 2000;
        int choice1, choice2, choice3, handPos;
    
        test = initializeGame(num_players, k, Seed, &G);
        if(test != 0){
            failed++;
            printf("Initialize failure\n");
        }
        int current_player = rand() % num_players;
        G.whoseTurn = current_player;
        choice1 = rand() % 5;
        choice2 = rand() % 5;
        handPos = rand() % 5;
        G.hand[0][0] = steward;
        G.coins = rand() % 20; 
        
        test = cardEffect(steward, choice1,choice2,choice3, &G, handPos, 1);
        if(test == 0){
            passed++;
        }else{
            failed++;
        }
        
    }
    printf("Tests passed: %i\n", passed);
    printf("Tests failed: %i\n", failed);
}


