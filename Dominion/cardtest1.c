#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"

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

int main(){
    printf("testing village_function()\n");
    
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 3, &G);
    
    G.hand[0][0] = village;
    G.numActions = 1;
    printf("Number of actions left: %i\n", G.numActions);
    printf("Playing village card\n");
    cardEffect(village, 1, 0, 0, &G, 0, 0);
    assertTrue(G.numActions == 2, "Should have two additional actions");
    printf("Number of actions left: %i\n", G.numActions);
    /*
    assertTrue(numHandCards(&G)==5, "Should have five cards");
    cardEffect(steward, 1, 0, 0, &G, 0, 0);
    assertTrue(G.numActions == 4, "Should have added 3 actions");
    assertTrue(numHandCards(&G)==5, "Should have five cards after adding and discarding");
    */
}