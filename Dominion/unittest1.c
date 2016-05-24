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
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 5, &G);
    assertTrue(isGameOver(&G)== 0, "isGameOver() should return 0");
    
    //Province cards are out
    initializeGame(2, k, 5, &G);
    G.supplyCount[province] = 0;
    assertTrue(isGameOver(&G)== 1, "Province cards empty, isGameOver() should return 1");
   
    //Three empty supply piles
    initializeGame(2, k, 5, &G);
    G.supplyCount[1] = 0;
    G.supplyCount[2] = 0;
    G.supplyCount[3] = 0;
    assertTrue(isGameOver(&G)== 1, "Three empty supply piles, isGameOver() should return 1");
    
    
}