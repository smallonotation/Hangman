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
#include "graphics.h"

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

    // Test
    int i = 0;

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

        // Test
        isGameLoopActive = false;
        scanf("%i", &i);
    }while(isGameLoopActive);

    /*
        Game Close Code
    */
    // Alle Charaktere der Konsole löschen und End-Bildschirm bauen.
    clearConsole();

    // Erstellt einen Rahmen.
    drawBorder(24,3);

    // Setzt den Cursor in den Rahmen.
    setCursorPosition(2,1);
    printf("Auf Wiedersehen! o/");

    // Setzt den Cursor tiefer, um die Nachricht "Process returned 0x0..." nicht zu clippen.
    setCursorPosition(0,5);

    return 0;
}

void test_dataio()
{
    char* testString = "FF";
    setSolutionWord("moin");
    if (checkInputEnteredChar(testString)) {
        inputEnteredChar(testString[0]);
    }
    inputEnteredChar('m');
    inputEnteredChar('N');
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
