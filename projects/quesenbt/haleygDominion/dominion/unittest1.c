/*
 * Tanner Quesenberry
 * Fall 2017 CS362
 * Unit test file for getCost function
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

    // Move the current game state to a testing struct
    memcpy(&testGame, &game, sizeof(struct gameState));

    printf("_____________TESTING getCost FUNTION____________\n");
    int output;
    output = getCost(treasure_map);
    printf("Treasure map, Expects: 4, Result: %d\n", output);

    output = getCost(sea_hag);
    printf("Sea hag, Expects: 4, Result: %d\n", output);

    output = getCost(salvager);
    printf("Salvager, Expects: 4, Result: %d\n", output);

    output = getCost(outpost);
    printf("Outpost, Expects: 5, Result: %d\n", output);

    output = getCost(embargo);
    printf("Embargo, Expects: 2, Result: %d\n", output);

    output = getCost(cutpurse);
    printf("Cutpurse, Expects: 4, Result: %d\n", output);

    output = getCost(ambassador);
    printf("Ambassador, Expects: 3, Result: %d\n", output);

    output = getCost(tribute);
    printf("Tribute, Expects: 5, Result: %d\n", output);

    output = getCost(steward);
    printf("Steward, Expects: 3, Result: %d\n", output);

    output = getCost(minion);
    printf("Minion, Expects: 5, Result: %d\n", output);

    output = getCost(great_hall);
    printf("Great hall, Expects: 3, Result: %d\n", output);

    output = getCost(baron);
    printf("Baron, Expects: 4, Result: %d\n", output);

    output = getCost(village);
    printf("Village, Expects: 3, Result: %d\n", output);

    output = getCost(smithy);
    printf("Smithy, Expects: 4, Result: %d\n", output);

    output = getCost(remodel);
    printf("Remodel, Expects: 4, Result: %d\n", output);

    output = getCost(mine);
    printf("Mine, Expects: 5, Result: %d\n", output);

    output = getCost(gardens);
    printf("Gardens, Expects: 4, Result: %d\n", output);

    output = getCost(feast);
    printf("Feast, Expects: 4, Result: %d\n", output);

    output = getCost(council_room);
    printf("Council room, Expects: 5, Result: %d\n", output);

    output = getCost(adventurer);
    printf("Adventurer, Expects: 6, Result: %d\n", output);

    output = getCost(gold);
    printf("Gold, Expects: 6, Result: %d\n", output);

    output = getCost(silver);
    printf("Silver, Expects: 3, Result: %d\n", output);

    output = getCost(copper);
    printf("Copper, Expects: 0, Result: %d\n", output);

    output = getCost(province);
    printf("Province, Expects: 8, Result: %d\n", output);

    output = getCost(duchy);
    printf("Duchy, Expects: 5, Result: %d\n", output);

    output = getCost(estate);
    printf("Estate, Expects: 2, Result: %d\n", output);

    output = getCost(curse);
    printf("Curse, Expects: 0, Result: %d\n", output);

    output = getCost(-1);
    printf("Now testing invalid card, Expect -1, Result: %d\n", output);
    printf("____________getCost TESTS COMPLETE____________\n\n");
    return 0;
}
