#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


//My assertTrue function
int assertTrue(int test, char* message){
    if(test == 0){
        printf("TEST FAILED: %s\n", message);
        return 1;
    }else{
        printf("TESTS SUCCESSFULLY COMPLETED\n");
        return 0;
    }
}

//buyCard()
int main(int argc, char **argv){
    printf("Testing buyCard()\n");
    
    struct gameState G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &G);
    
    G.numBuys = 0;
    G.coins = 5;
    assertTrue(buyCard(1, &G) == -1, "Should not be able to buy card");
    
    G.coins = 2;
    G.numBuys = 2;
    assertTrue(buyCard(1,&G)==0, "Should be able to buy card");
}