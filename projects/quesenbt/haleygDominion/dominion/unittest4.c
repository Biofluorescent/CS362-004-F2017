/*
 * Tanner Quesenberry
 * Fall 2017 CS362
 * Unit test file for the fullDeckCount function
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
    int currentPlayer = 0;
    int opponent = 1;

    // Initialize the starting state for the game
    initializeGame(2, k, gameSeed, &game);
    // Set card totals
    game.handCount[currentPlayer] = 5;
    game.deckCount[currentPlayer] = 4;
    game.discardCount[currentPlayer] = 7;

    game.handCount[opponent] = 6;
    game.deckCount[opponent] = 8;
    game.discardCount[opponent] = 5;


    printf("_____________NOW TESTING fullDeckCount____________\n");

    // Move the current game state to a testing struct
    memcpy(&testGame, &game, sizeof(struct gameState));
    int output = fullDeckCount(currentPlayer, 0, &testGame);
    printf("Player has 5 cards in hand, 4 in deck, and 7 in discard.\nExpected total: 16  Actual: %d\n", output);
    if(output == 16){
        printf("TEST CASE SUCCESSFUL\n");
    }else{
        printf("TEST CASE FAILURE\n");
    }

    output = fullDeckCount(opponent, 0, &testGame);
    printf("Opponent has 6 cards in hand, 8 in deck, and 5 in discard.\nExpected total: 19  Actual: %d\n", output);
    if(output == 19){
        printf("TEST CASE SUCCESSFUL\n");
    }else{
        printf("TEST CASE FAILURE\n");
    }

    printf("ALL TESTS SUCCESSFULLY RAN\n");
    printf("__________FINISHED TESTING fullDeckCount_____________\n\n");

    return 0;
}
