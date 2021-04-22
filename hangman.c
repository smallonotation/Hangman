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
bool game_won() {
	return game.game_won;
}

/// <summary>
/// Gibt zurück, ob das Spiel verloren ist.
/// </summary>
/// <returns>Verloren</returns>
bool game_lost() {
	return game.game_lost;
}

/// <summary>
/// Startet das Spiel.
/// </summary>
void game_start() {
	start_stopwatch();
	gamescore.guesses.correct_guesses = gamescore.guesses.wrong_guesses = 0;
	game.game_lost = game.game_won = false;
	game_progress();
}

/// <summary>
/// Stellt das Spiel dar.
/// </summary>
void game_progress() {
	do {
		// Ausgabe und Eingabe
	} while (game_lost || game_won);
	game_end();
}

/// <summary>
/// Ende des Spiels.
/// </summary>
void game_end() {
	stop_stopwatch();
	// Ausgabe des Spielstandes
}
