#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"


int assertTrue(int test, char* message){
    if(test == 0){
        printf("TEST FAILED: %s\n", message);
        return 1;
    }else{
        printf("TESTS SUCCESSFULLY COMPLETED\n");
        return 0;
    }
}

//initializeGame()
int main(int argc, char **argv){
    printf("TESTING initializeGame()\n");
    
    struct gameState G;
    struct gameState *p = &G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    int result = initializeGame(2, k, 5, p);

    assertTrue(result == 0, "Game did not initialize");
}