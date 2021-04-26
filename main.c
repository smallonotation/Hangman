/**
 *  Diese Datei beschreibt die Main-Funktionalit�t.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

#include <stdlib.h>
#include "hangman.h"
#include "score.h"
#include "security.h"
#include "data_io.h"

void test_score();
void test_encrypt_decrypt();
void test_dataio();

int main()
{
    //game_start();
    //test_score();
    //test_encrypt_decrypt();
    test_dataio();

    /*
        Main-Funktion von Hangman
        Hier wird das Spiel gespielt.
        Die Schleife verhindert, dass das Spiel beendet wird, nachdem es
        gespielt wurde.
    */

    // Identifiziert, ob die Schleife wiederholt wird.
    bool isGameLoopActive = true;

    // Game-Loop, isGameLoopActive wird auf false gesetzt,
    // wenn im Menü das Spiel beendet wird.
    do
    {
        /*
            Menü Code
        */

        /*
            Game Code
        */
    }while(isGameLoopActive)

    /*
        Game Close Code
        z.B. Auf Wiedersehen! o/
    */

    return 0;
}

void test_dataio()
{
    inputSolutionWord("Moin");
    inputEnteredChar('M');
    inputEnteredChar('A');
    inputEnteredChar('O');
    inputEnteredChar('U');
    outputDiscoveredLetters();
    outputEnteredChars();
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

void test_encrypt_decrypt() {
    char text[] = "Dies ist ein test\n";
    printf(text);
    encrypt(text);
    printf(text);
    decrypt(text);
    printf(text);
}
