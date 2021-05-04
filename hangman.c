/**
 *  Diese Quell-Datei dient zur Definition der Spielfunktionalit�t.
 *
 *  @author Jesse Kroeske, Timo Thiede - 07.04.2021
 **/

#include "hangman.h"

struct game game;

/// <summary>
/// Gibt zurück, ob das Spiel gewonnen wurde.
/// </summary>
/// <returns>Gewonnen</returns>
bool game_won()
{
    return game.game_won;
}

/// <summary>
/// Gibt zurück, ob das Spiel verloren ist.
/// </summary>
/// <returns>Verloren</returns>
bool game_lost()
{
    return game.game_lost;
}

/// <summary>
/// Setzt den Spielstand.
/// </summary>
void set_game_status(bool won)
{
    if (won)
        game.game_won = true;
    else
        game.game_lost = true;
}

/// <summary>
/// Startet das Spiel.
/// </summary>
void game_start()
{
    start_stopwatch();
    gamescore.guesses.correct_guesses = gamescore.guesses.wrong_guesses = 0;
    game.game_lost = game.game_won = false;
    game_progress();
}

/// <summary>
/// Stellt das Spiel dar.
/// </summary>
void game_progress()
{
    int ctr = 0;
    int result = 0;
    // Ausgabe und Eingabe Name
    setCursorPosition(2,7);
    setPlayerName();
    // Setzen des Rätsels
    setSolutionWord("TEST");
    // Ratespiel
    do
    {
        // Zeichnung des Hangmans
        drawHangman(2,10,ctr);
        setCursorPosition(2,22);
        // Anzeige der eingegebenen Buchstaben
        outputDiscoveredLetters();
        setCursorPosition(2,23);
        printf("Richtig: %i, Falsch: %i", get_guesses().correct_guesses, get_guesses().wrong_guesses);
        setCursorPosition(2,27);
        // Anzeige der eingegebenen Buchstaben
        outputEnteredChars();
        setCursorPosition(2,25);
        // Zeile löschen.
        printf("                                         ");
        if(ctr == MAXGUESSES || isSolutionworDiscovered()){
            break;
        }
        setCursorPosition(2,25);
        result = inputEnteredChar();
        if(result == 1){
            add_guess(true);
        }
        else if (result == 0 || result == -1){
            add_guess(false);
            ctr++;
        }
    }
    while(true);

    set_game_status(ctr < MAXGUESSES);

    game_end();
}

/// <summary>
/// Ende des Spiels.
/// </summary>
void game_end()
{
    stop_stopwatch();
    print_score();
}

/// <summary>
/// Anzeige Score.
/// </summary>
void print_score()
{
    // Ausgabe des Spielstandes
    drawHangman(2,10,11);
    setCursorPosition(2,10);
    printf("%s", game_won() ? "Gewonnen" : "Verloren");
    setCursorPosition(2,11);
    printf("_______________________");
    setCursorPosition(2,12);
    printf("Zeit:\t\t%i", get_stopwatchtime());
    setCursorPosition(2,13);
    printf("Richtig:\t%i", get_guesses().correct_guesses);
    setCursorPosition(2,14);
    printf("Falsch:\t%i", get_guesses().wrong_guesses);
    fflush(stdin);
    getchar();
}
