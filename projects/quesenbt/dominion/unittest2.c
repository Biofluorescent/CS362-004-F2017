/*
 * Tanner Quesenberry
 * Fall 2017 CS362
 * Unit test file for the isGameOver function.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main() {

    struct gameState testGame;
    struct gameState game;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int gameSeed = 1000;

    // Initialize the starting state for the game
    initializeGame(2, k, gameSeed, &game);
    // Set the first end state to test
    game.supplyCount[province] = 0;


    printf("_____________TESTING isGameOver FUNCTION____________\n");

    // Move the current game state to a testing struct
    memcpy(&testGame, &game, sizeof(struct gameState));

    int output;
    output = isGameOver(&testGame);
    printf("Testing empty province supply.\n");
    printf("Expected result: 1    Actual Result: %d\n", output);
    if(output == 1){
        printf("TEST PASS\n");
    }else{
        printf("TEST FAILURE: INCORRECT RETURN STATE\n");
    }

    printf("Testing 3 empty supply end state.\n");
    // Set supply counts appropriate to test
    game.supplyCount[province] = 3;
    game.supplyCount[minion] = 0;
    game.supplyCount[steward] = 0;
    game.supplyCount[smithy] = 0;

    // Apply new game state
    memcpy(&testGame, &game, sizeof(struct gameState));
    
    output = isGameOver(&testGame);
    printf("Expected result: 1    Actual Result: %d\n", output);
    if(output == 1){
        printf("TEST PASS\n");
    }else{
        printf("TEST FAILURE: INCORRECT RETURN STATE\n");
    }

    // Set supply counts appropriate to test
    game.supplyCount[province] = 3;
    game.supplyCount[minion] = 3;

    // Apply new game state
    memcpy(&testGame, &game, sizeof(struct gameState));

    printf("Testing game not over state.\n");    
    output = isGameOver(&testGame);
    printf("Expected result: 0    Actual Result: %d\n", output);
    if(output == 0){
        printf("TEST PASS\n");
    }else{
        printf("TEST FAILURE: INCORRECT RETURN STATE\n");
    }

    printf("ALL TESTS SUCCESSFULLY RAN\n");
    printf("__________FINISHED TESTING isGameOver______________\n\n");

    return 0;
}
