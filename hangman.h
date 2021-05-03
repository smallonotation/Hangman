/**
 *  Diese Header-Datei dient zur Deklaration der Spielfunktionalit�t.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#ifndef HANGMAN_H
#define HANGMAN_H

#define MAXGUESSES 10

#include <stdbool.h>
#include "score.h"
#include "data_io.h"
#include "graphics.h"

struct game {
	bool game_won;
	bool game_lost;
};

extern struct game game;

/// <summary>
/// Gibt zurück, ob das Spiel gewonnen wurde.
/// </summary>
/// <returns>Gewonnen</returns>
bool game_won();

/// <summary>
/// Gibt zurück, ob das Spiel verloren ist.
/// </summary>
/// <returns>Verloren</returns>
bool game_lost();

/// <summary>
/// Setzt den Spielstand.
/// </summary>
void set_game_status(bool won);

/// <summary>
/// Startet das Spiel.
/// </summary>
void game_start();

/// <summary>
/// Stellt das Spiel dar.
/// </summary>
void game_progress();

/// <summary>
/// Ende des Spiels.
/// </summary>
void game_end();

/// <summary>
/// Anzeige Score.
/// </summary>
void print_score();

#endif // HANGMAN_H
