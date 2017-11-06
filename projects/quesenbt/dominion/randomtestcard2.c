/*
 * Tanner Quesenberry
 * Fall 2017 CS362
 * Random test file for the Smithy card.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Number of tests to perform
#define TEST_TOTAL 100


/*
 * This function verifies that the Smithy card altered the players
 * deck card count and hand count correctly after the smithy card
 * is activated. A return of 0 is a test fail and 1 is a test pass.
*/
int stateValidator(struct gameState* game, int player, int opponent, int deckCount, int handCount, int oppDeck, int oppHand){
    if(handCount + 2 != game->handCount[player]){
        // Test fail Current hand should be more
        printf("TEST FAIL: Incorrect player hand count.\n");
        return 0;
    }else if(oppHand != game->handCount[opponent]){
        printf("TEST FAIL: Incorrect opponent hand count.\n");
        return 0;
    }

    if(deckCount <= game->deckCount[player]){
        // Test fail current deck should be less than previous
        printf("TEST FAIL: Incorrect player deck count\n");
        return 0;
    }else if(oppDeck != game->deckCount[opponent]){
        printf("TEST FAIL: Incorrect opponent deck count.\n");
    }

    // If test successful
    return 1;
}


int main() {

    srand(time(NULL));

    struct gameState testGame;
    struct gameState game;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int gameSeed = 1000;
    int currentPlayer = 0;
    int opponent = 1;
    int handPos = 0;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;
    int outcome;
    int currentHand = 0, currentDeck = 0, oppHand = 0, oppDeck = 0;

    // Initialize the starting state for the game
    initializeGame(2, k, gameSeed, &game);

    // Set starting hand and deck count
    /* game.hand[currentPlayer][0] = adventurer;
    game.hand[currentPlayer][1] = village;
    game.hand[currentPlayer][2] = tribute;
    game.hand[currentPlayer][3] = mine;
    game.hand[currentPlayer][4] = silver;
    game.handCount[currentPlayer] = 5;
    game.deckCount[currentPlayer] = 4;

    game.handCount[opponent] = 5;
    game.deckCount[opponent] = 4;

    */

    printf("_____________NOW TESTING SMITHY____________\n");
    int i;
    for(i = 0; i < TEST_TOTAL; i++){

        gameSeed = rand() % 1000;

        // Set up game
        initializeGame(2, k, gameSeed, &game);

        // Set up deck/hand
        currentDeck = rand() % MAX_DECK;
        game.handCount[currentPlayer] = rand() % MAX_HAND;
        game.handCount[opponent] = rand() % MAX_HAND;
        game.deckCount[currentPlayer] = currentDeck;
        game.deckCount[opponent] = currentDeck;

        // Get values before card is aci=tivated
        currentHand = game.handCount[currentPlayer];
        currentDeck = game.deckCount[currentPlayer];
        oppHand = game.handCount[opponent];
        oppDeck = game.deckCount[opponent];

        // Play the Smithy card using the test game state
        cardEffect(smithy, choice1, choice2, choice3, &game, handPos, &bonus);

        // Test state of game
        outcome = stateValidator(&game, currentPlayer, opponent, currentDeck, currentHand, oppDeck, oppHand);
        if(outcome == 1){
            printf("Currnet test case pass.\n");
        }
    }


    printf("ALL TESTS SUCCESSFULLY RAN\n");
    printf("__________FINISHED TESTING SMITHY______________\n\n");

    return 0;
}
