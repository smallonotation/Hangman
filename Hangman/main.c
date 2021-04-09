/**
 *  Diese Datei beschreibt die Main-Funktionalit�t.
 *
 *  @author Jesse Kroeske, Timo Thiede - 07.04.2021
 **/

#include <stdlib.h>
#include "hangman.h"
#include "score.h"

void test_score();

int main()
{
    test_score();

    return 0;
}

void test_score() {
    // Score Test
    int c, d;

    printf("Starte Score...\n");
    printf("Starte Timer\n");

    start_stopwatch();

    printf("Delay...\n");

    for (c = 1; c <= 32767; c++)
        for (d = 1; d <= 32767; d++)
        {
        }

    printf("Tipp add... (4 true, 2 false)\n");

    add_guess(true);
    add_guess(true);
    add_guess(true);
    add_guess(true);
    add_guess(false);
    add_guess(false);

    printf("current time: %llu\n", get_stopwatchtime());

    printf("Delay...\n");

    for (c = 1; c <= 32767; c++)
        for (d = 1; d <= 32767; d++)
        {
        }

    printf("Stop Timer\n");

    stop_stopwatch();

    printf("approx 2 sec\n");

    struct score score = get_score();

    printf("guesses: %i, wrong guesses: %i, time: %llu", score.guesses.correct_guesses + score.guesses.wrong_guesses, score.guesses.wrong_guesses, get_stopwatchtime());
}
