#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"
#include "dominion.c"

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
    village_function(1,&G,1);
    int i = G.numActions;
    assertTrue(G.numActions == i+3, "village function should add 3");
   
}