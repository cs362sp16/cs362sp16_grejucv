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

//isGameOver()
int main(int argc, char **argv){
    printf("Testing isGameOver()\n");
    struct gameState G;
    int result;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    initializeGame(2, k, 5, &G);
    
    
    
    G.supplyCount[province] = 0;
    assertTrue(isGameOver(&G)== 1, "Province cards empty, isGameOver() should return 1");
    
    
    
}