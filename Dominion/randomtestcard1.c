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
    int i, passed =0, failed = 0;
    for(i=0; i<10; i++){
        struct gameState G;
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	                 sea_hag, tribute, smithy};
    
        initializeGame(2, k, 2, &G);
        G.hand[0][0] = steward;
        G.coins = 0;
        //assertTrue(numHandCards(&G)==5, "Should have five cards");
        cardEffect(steward, 1, 0, 0, &G, 0, 0);
        //assertTrue(numHandCards(&G)==6, "Should have six cards if choice is 1");
    
        cardEffect(steward, 2, 0, 0, &G, 0, 0);
        //assertTrue(G.coins==2, "Should have two coins if choice is 2");
    
        cardEffect(steward, 0, 0, 0, &G, 0, 0);
        //assertTrue(numHandCards(&G)==2, "Should have two cards if choice not 1 or 2");
    }
    printf("Tests passed: %i\n", passed);
    printf("Tests failed: %i\n", failed);
}