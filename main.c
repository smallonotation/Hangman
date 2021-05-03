/**
 *  Diese Datei beschreibt die Main-Funktionalit�t.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
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
    /*
        Main-Funktion von Hangman
        Hier wird das Spiel gespielt.
        Die Schleife verhindert, dass das Spiel beendet wird, nachdem es
        gespielt wurde.
    */

    // Identifiziert, ob die Schleife wiederholt wird.
    bool isGameLoopActive = true;
    // Inputvariable für das Menü.
    char menuInput = '0';

    // Game-Loop, isGameLoopActive wird auf false gesetzt,
    // wenn im Menü das Spiel beendet wird.
    do
    {
        /*
            Menü Code
        */
        clearConsole();

        drawBorder(68,25);

        setCursorPosition(1,1); // x = 1, y = 1 (Zeile 2)
        printf("Willkommen zu Hangman!");

        setCursorPosition(1,2); // x = 1, y = 2 (Zeile 3)
        printf("Geben Sie den Befehl ein:");

        setCursorPosition(1,4);
        printf("S: Spiel starten!");

        setCursorPosition(1,5);
        printf("E: Spiel schließen!");

        setCursorPosition(2,7);
        scanf("%c", &menuInput);
        fflush(stdin);

        switch(menuInput)
        {
        case 'S':
            {
                /*
                    Game Code
                    Hier kommt der Code für das Spiel rein, als wäre es eine leere main() :)
                */

                // Aktuell gleicht das Spiel dem "Console-Game-Menu-Simulator".

                game_start();
                test_score();
                test_encrypt_decrypt();
                test_dataio();
                break;
            }
        case 'E':
        default:
            {
                // Das Spiel (Schleife) wird beendet.
                isGameLoopActive = false;
                break;
            }
        }
    }
    while(isGameLoopActive);

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
    setPlayerName();
    setSolutionWord("moin");
<<<<<<< Updated upstream
    if (checkInputEnteredChar(testString))
    {
        inputEnteredChar(testString[0]);
    }
    inputEnteredChar('m');
    inputEnteredChar('N');
    inputEnteredChar('A');
    inputEnteredChar('O');
    inputEnteredChar('U');
=======
    inputEnteredChar();
>>>>>>> Stashed changes
    outputDiscoveredLetters();
    outputEnteredChars();
    if (isSolutionworDiscovered()){
        printf("Wort aufgedeckt\n");
    }
    else{
        printf("Wort nicht aufgedeckt\n");
    }
}

void test_score()
{
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

    // llu im Formatstring wird in dieser Version von C nicht unterstützt.
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

void test_encrypt_decrypt()
{
    char text[] = "Dies ist ein test\n";
    printf(text);
    encrypt(text);
    printf(text);
    decrypt(text);
    printf(text);
}
