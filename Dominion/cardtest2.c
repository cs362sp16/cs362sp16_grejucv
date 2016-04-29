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
    printf("tesing smithy_function()\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

    initializeGame(2, k, 3, &G);
    
    G.hand[0][0] = smithy;
    assertTrue(numHandCards(&G) == 5, "Should have five cards in hand");
    cardEffect(smithy,0,0,&G,0,0);
    assertTrue(numHandCards(&G) == 7, "Should have seven cards in hand");
}