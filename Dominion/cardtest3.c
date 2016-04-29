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
    printf("testing steward\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    initializeGame(2, k, 2, &G);
    G.hand[0][0] = outpost;
    G.outpostPlayed = 0;
    assertTrue(numHandCards(&G)==5, "Should have five cards");
    cardEffect(outpost, 1, 0, 0, &G, 0, 0);
    assertTrue(G.outpostPlayed = 1, "outpostPlayed should be one");
    assertTrue(numHandCards(&G)==5, "Should have four cards");
}