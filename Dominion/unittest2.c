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
        printf("TEST PASSED\n");
        return 0;
    }
}

int main(){
    printf("Testing initialize\n");
    
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    int result;
    
    result = initializeGame(5, k, 3, &G);
    assertTrue(result == -1, "Added five players, should return error");
    
    result = initializeGame(0, k, 3, &G);
    assertTrue(result == -1, "Added zero players, should return error");
    
    result = initializeGame(3, k, 3, &G);
    assertTrue(result == 0, "Initialize error");
    
    assertTrue(G.numPlayers = 3, "Number of players not set");
    assertTrue(G.supplyCount[silver] == 40, "Silver supply count should be 40");
    assertTrue(G.supplyCount[gold] == 30, "Silver supply count should be 40");
    
    int k2[10] = {gardens, gardens, embargo, village, village, mine, cutpurse,
	       sea_hag, tribute, smithy};
    
    result = initializeGame(3, k2, 3, &G);
    assertTrue(result == -1, "Two kingdom cards are the same, should return error");
    
    initializeGame(2, k, 3, &G);
    assertTrue(G.supplyCount[curse] == 10, "Curse supply count should be 10"); //
    
    initializeGame(2, k, 3, &G);
    assertTrue(G.supplyCount[estate] == 8, "Estate supply count should be 8"); //
    assertTrue(G.supplyCount[duchy] == 8, "Duchy supply count should be 8");
    assertTrue(G.supplyCount[province] == 8, "Province supply count should be 8"); //
    
    initializeGame(4, k, 3, &G);
    assertTrue(G.supplyCount[curse] == 30, "Curse supply count should be 30"); //
    assertTrue(G.supplyCount[estate] == 12, "Estate supply count should be 12"); //
    assertTrue(G.supplyCount[duchy] == 12, "Duchy supply count should be 12");
    assertTrue(G.supplyCount[province] == 12, "Province supply count should be 12");
    

    printf("All initialize tests completed\n");
}


