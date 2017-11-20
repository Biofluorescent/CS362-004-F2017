/*
 * Tanner Quesenberry
 * Fall 2017 CS362
 * Unit test file for the Village card.
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
    int handPos = 1;
    int choice1 = 0, choice2 = 0, choice3 = 0;
    int bonus = 0;
    int cardsAdded = 1;
    int currentHand = 0, expectedHand = 0;

    // Initialize the starting state for the game
    initializeGame(2, k, gameSeed, &game);
    //currentPlayer = whoseTurn(&game);

    // Set starting hand and deck count
    game.hand[currentPlayer][0] = smithy;
    game.hand[currentPlayer][1] = village;
    game.hand[currentPlayer][2] = tribute;
    game.hand[currentPlayer][3] = mine;
    game.hand[currentPlayer][4] = silver;
    game.handCount[currentPlayer] = 5;
    game.deckCount[currentPlayer] = 4;

    game.handCount[opponent] = 5;
    game.deckCount[opponent] = 4;



    printf("_____________NOW TESTING VILLAGE____________\n");

    // Move the current game state to a testing struct
    memcpy(&testGame, &game, sizeof(struct gameState));

    // Play the Smithy card using the test game state
    cardEffect(village, choice1, choice2, choice3, &testGame, handPos, &bonus);

    // Check cards in current player hand vs expected
    currentHand = testGame.handCount[currentPlayer];
    expectedHand = game.handCount[currentPlayer] + cardsAdded - 1; // -1 for discarding village
    printf("Checking number of cards in player hand.\n");
    printf("Expected cards in hand: %d\n", expectedHand);
    printf("Actual cards in hand:   %d\n", currentHand);
    if(currentHand != expectedHand){
        printf("TEST CASE FAIL: INCORRECT NUMBER OF CARDS IN CURRENT PLAYER HAND\n");
    }else{
        printf("TEST CASE PASS\n");
    }
    printf("\n");

    // Check the current players deck total
    printf("Checking number of cards in player deck.\n");
    int curDeck = testGame.deckCount[currentPlayer];
    int expDeck = game.deckCount[currentPlayer] - cardsAdded;
    printf("Expected cards in deck: %d\n", expDeck);
    printf("Actual cards in deck: %d\n", curDeck);
    if(curDeck != expDeck){
        printf("TEST CASE FAIL: INCORRECT NUMBER OF CARDS IN CURRENT PLAYER DECK\n");
    }else{
        printf("TEST CASE PASS\n");
    }
    printf("\n");

    // Check total number of actions
    printf("Checking correct number of additional actions.\n");
    int curActions = testGame.numActions - 1; // -1 because actions are not decremented through the card effect function, must take into account here
    int expActions = game.numActions + 1;
    printf("Expected actions remaining: %d\n", expActions);
    printf("Actual actions remaining: %d\n", curActions);
    if(curActions != expActions){
        printf("TEST CASE FAIL: INCORRECT NUMBER OF REMAINING ACTIONS\n");
    }else{
        printf("TEST CASE PASS\n");
    }
    printf("\n");

    // Check cards in opponent  hand vs expected
    currentHand = testGame.handCount[opponent];
    expectedHand = game.handCount[opponent];
    printf("Checking number of cards in opponent hand.\n");
    printf("Expected cards in hand: %d\n", expectedHand);
    printf("Actual cards in hand:   %d\n", currentHand);
    if(currentHand != expectedHand){
        printf("TEST CASE FAIL: INCORRECT NUMBER OF CARDS IN OPPONENT HAND\n");
    }else{
        printf("TEST CASE PASS\n");
    }
    printf("\n");

    // Check the opponents deck total
    printf("Checking number of cards in opponents deck.\n");
    curDeck = testGame.deckCount[opponent];
    expDeck = game.deckCount[opponent];
    printf("Expected cards in deck: %d\n", expDeck);
    printf("Actual cards in deck: %d\n", curDeck);
    if(curDeck != expDeck){
        printf("TEST CASE FAIL: INCORRECT NUMBER OF CARDS IN OPPONENT DECK\n");
    }else{
        printf("TEST CASE PASS\n");
    }
    printf("\n");
    printf("ALL TESTS SUCCESSFULLY RAN\n");
    printf("__________FINISHED TESTING VILLAGE______________\n\n");

    return 0;
}
