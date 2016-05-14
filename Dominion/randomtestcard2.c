#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "interface.h"
#include "dominion.h"



int main(int argc, char *argv[]){
    printf("random testing outpost\n");
    int i, passed =0, failed =0;
    srand(time(NULL));
    
    for(i=0; i<1000; i++){
        struct gameState G;
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
        int num_players = rand() % 3 + 2;
    
        initializeGame(num_players, k, 2, &G);
        G.hand[0][0] = outpost;
        G.outpostPlayed = 0;
    
        if(numHandCards(&G)!=5){
            failed++;
        }else{
            passed++;
        }
    
        cardEffect(outpost, 1, 0, 0, &G, 0, 0);
        if(G.outpostPlayed != 1){
            failed++;
        }else{
            passed++;
        }
        
        if(numHandCards(&G)!=4){
            failed++;
        }else{
            passed++;
        }
        
    }
    printf("Tests passed: %i\n", passed);
    printf("Tests failed: %i\n", failed);
}