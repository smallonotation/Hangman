/**
 *  Diese Datei beschreibt die Main-Funktionalit�t.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "hangman.h"

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

        drawBorder(80,30);

        setCursorPosition(2,1); // x = 1, y = 1 (Zeile 2)
        printf("Willkommen zu Hangman!");

        setCursorPosition(2,2); // x = 1, y = 2 (Zeile 3)
        printf("Geben Sie den Befehl ein:");

        setCursorPosition(2,4);
        printf("S: Spiel starten!");

        setCursorPosition(2,5);
        printf("E: Spiel schließen!");

        setCursorPosition(2,7);
        scanf("%c", &menuInput);
        fflush(stdin);

        switch(menuInput)
        {
        case 's':
        case 'S' || 's':
            {
                /*
                    Game Code
                    Hier kommt der Code für das Spiel rein, als wäre es eine leere main() :)
                */

                // Aktuell gleicht das Spiel dem "Console-Game-Menu-Simulator".

                game_start();
                break;
            }
        case 'e':
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
