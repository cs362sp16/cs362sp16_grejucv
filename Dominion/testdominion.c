#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "interface.h"
#include "dominion.h"
#include <time.h>

//Shuffle taken from: http://stackoverflow.com/questions/6127503/shuffle-array-in-c
void shuffleDeck(int *array, size_t n){
    if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++){
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main(int argc, char *argv[] ){
    srand(time(NULL));
    
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};
    int result, passed = 0, failed = 0;
    //int mySeed = atoi(argv[1]);
    
    int randomSeed = rand() % 42;
    int num_players = rand() % 3 + 2;
    
    //shuffleDeck(k, 10);
    printf("Starting Dominion Game\n");
    result = initializeGame(num_players, k, randomSeed, &G);
    if(result != 0){
        failed++;
    }else{
        passed++;
    }
    
    
    while(!isGameOver(&G)){
        int currentPlayer = whoseTurn(&G);
        
     
    }
    
    
        
        
    
    /* -------------------------------*/
    printf("Passed: %i\n", passed);
    printf("failed: %i\n", failed);
    
}




