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
        //int Seed = rand() % 5000;
    
        test = initializeGame(num_players, k, 2, &G);
        if(test != 0){
            failed++;
            printf("Initialize failure\n");
        }
        G.hand[0][0] = steward;
        G.coins = 0;
        if(numHandCards(&G)!=5){
            failed++;
        }else{
            passed++;
        }
        cardEffect(steward, 1, 0, 0, &G, 0, 0);
        if(numHandCards(&G)!=6){
            failed++;
        }else{
            passed++;
        }
        cardEffect(steward, 2, 0, 0, &G, 0, 0);
        if(G.coins !=6){
            failed++;
        }else{
            passed++;
        }
        
        cardEffect(steward, 0, 0, 0, &G, 0, 0);
        if(numHandCards(&G)!=2){
            failed++;
        }else{
            passed++;
        }
        
    }
    printf("Tests passed: %i\n", passed);
    printf("Tests failed: %i\n", failed);
}


