#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include "assert.h"
#include "dominion_helpers.h"


int assertTrue(int test, char* message){
    if(test != 1){
        printf("TEST FAILED: %s\n", message);
        return 1;
    }else{
        printf("TESTS SUCCESSFULLY COMPLETED\n");
        return 0;
    }
}

//getCost()
int main(int argc, char **argv){
    printf("Testing getCost()\n");
    struct gameState G;
    int result;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    initializeGame(2, k, 5, &G);
    
    result = getCost(curse);
    assertTrue(result == 0 , "curse cost error");
    
    result = getCost(estate);
    assertTrue(result == 2, "estate cost error");
    
    result = getCost(duchy);
    assertTrue(result == 5, "duchy cost error");
    
    result = getCost(province);
    assertTrue(result == 8, "province cost error");
    
    result = getCost(copper);
    assertTrue(result == 0, "copper cost error");
    
    result = getCost(silver);
    assertTrue(result == 3, "silver cost error");
    
    result = getCost(gold);
    assertTrue(result == 6, "gold cost error");
    
    result = getCost(adventurer);
    assertTrue(result == 6, "adventurur cost error");
    
    result = getCost(council_room);
    assertTrue(result == 5, "council_room cost error");
    
    result = getCost(feast);
    assertTrue(result == 4, "feast cost error");
    
    result = getCost(gardens);
    assertTrue(result == 4, "gardens cost error");
    
    result = getCost(mine);
    assertTrue(result == 5, "mine cost error");
    
    result = getCost(remodel);
    assertTrue(result == 4, "remodel cost error");
    
    result = getCost(smithy);
    assertTrue(result == 4, "smithy cost error");
    
    result = getCost(village);
    assertTrue(result == 3, "village cost error");
    
    result = getCost(baron);
    assertTrue(result == 4, "baron cost error");
    
    result = getCost(great_hall);
    assertTrue(result == 3, "great_hall cost error");
    
    result = getCost(minion);
    assertTrue(result == 5, "minion cost error");
    
    result = getCost(steward);
    assertTrue(result == 3, "steward cost error");
    
    result = getCost(tribute);
    assertTrue(result == 5, "tribute cost error");
    
    result = getCost(ambassador);
    assertTrue(result == 3, "ambassador cost error");
    
    result = getCost(cutpurse);
    assertTrue(result == 4, "cutpurse cost error");
    
    result = getCost(embargo);
    assertTrue(result == 2, "embargo cost error");
    
    result = getCost(outpost);
    assertTrue(result == 5, "outpost cost error");
    
    result = getCost(salvager);
    assertTrue(result == 4, "salvager cost error");
    
    result = getCost(sea_hag);
    assertTrue(result == 4, "sea_hag cost error");
    
    result = getCost(treasure_map);
    assertTrue(result == 4, "treasure_map cost error");
    
}



















