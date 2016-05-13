#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <math.h>
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
    
    
}