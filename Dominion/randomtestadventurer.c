#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "interface.h"
#include "dominion.h"

int main(int argc, char *argv[]){
    printf("Random testing adventurer\n");
    srand(time(NULL));
    int i, passed =0, failed =0, test;
    for(i=0; i<1000;i++){
        struct gameState G;
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	                 sea_hag, tribute, smithy};
    
        int num_players = rand() % 3 + 2;
        int Seed = rand() % 5000;
        int choice1, choice2;

        test = initializeGame(num_players, k, Seed, &G);
        if(test != 0){
            failed++;
            printf("Initialize failure\n");
        }
        
        int current_player = rand() % num_players;
        G.whoseTurn = current_player;
        choice1 = rand() % 26;
        choice2 = rand() % 26;
        
        test = cardEffect(adventurer, choice1,choice2,1, &G);
        if(test == 0){
            passed++;
        }else{
            failed++;
        }
    
    }
    printf("Tests passed: %i\n", passed);
    printf("Tests failed: %i\n", failed);
}