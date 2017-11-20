/*
 * Tanner Quesenberry
 * Fall 2017 CS362
 * Unit test file for the scoreFor function
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

    // Set starting hand and deck count
    game.hand[currentPlayer][0] = estate; // +1 score
    game.hand[currentPlayer][1] = village; 
    game.hand[currentPlayer][2] = province; // +6 score
    game.hand[currentPlayer][3] = mine;
    game.hand[currentPlayer][4] = silver;
    game.deck[currentPlayer][0] = duchy; // +3 score
    game.deck[currentPlayer][1] = gold;
    game.discard[currentPlayer][0] = gold;
    game.discard[currentPlayer][1] = curse; // -1 score
   
    game.handCount[currentPlayer] = 5;
    game.deckCount[currentPlayer] = 2;
    game.discardCount[currentPlayer] = 2;
    
    game.hand[opponent][0] = estate; // +1 score
    game.hand[opponent][1] = province; // +6 score
    game.hand[opponent][2] = province; // +6 score
    game.hand[opponent][3] = mine;
    game.hand[opponent][4] = silver;
    game.deck[opponent][0] = duchy; // +3 score
    game.deck[opponent][1] = curse; // -1 score
    game.discard[opponent][0] = gold;
    game.discard[opponent][1] = curse; // -1 score

    game.handCount[opponent] = 5;
    game.deckCount[opponent] = 2;
    game.discardCount[opponent] = 2;


    printf("_____________NOW TESTING scoreFor____________\n");

    // Move the current game state to a testing struct
    memcpy(&testGame, &game, sizeof(struct gameState));
    int output = scoreFor(currentPlayer, &testGame);
    printf("Player has estate, province, duchy and curse.\nExpected score: 9  Actual: %d\n", output);
    if(output == 9){
        printf("TEST CASE SUCCESSFUL\n");
    }else{
        printf("TEST CASE FAILURE\n");
    }

    output = scoreFor(opponent, &testGame);
    printf("Opponent has estate, province x2, duchy, curse x2.\nExpected score: 14  Actual: %d\n", output);
    if(output == 14){
        printf("TEST CASE SUCCESSFUL\n");
    }else{
        printf("TEST CASE FAILURE\n");
    }

    printf("ALL TESTS SUCCESSFULLY RAN\n");
    printf("__________FINISHED TESTING scoreFor_____________\n\n");

    return 0;
}
