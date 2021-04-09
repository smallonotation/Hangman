/**
 *  Diese Header-Datei dient zur Deklaration der Scoringfunktionalität.
 *
 *  @author Jesse Kroeske, Timo Thiede - 07.04.2021
 **/

#ifndef SCORE_H
#define SCORE_H

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

struct score {
	time_t time;
	int guesses;
	int wrong_guesses;
};

extern struct score gamescore;
extern time_t start_time;

/// <summary>
/// Startet den Timer.
/// </summary>
void start_timer();

/// <summary>
/// Stoppt den Timer.
/// </summary>
void stop_timer();

/// <summary>
/// Gibt die Zeit des Timers zurück in Sekunden.
/// </summary>
/// <returns>Die Zeit oder 0 wenn der Timer nicht gestartet wurde.</returns>
time_t get_time();

/// <summary>
/// Fügt einen Tipp hinzu.
/// </summary>
/// <param name="correct">Tipp korrekt?</param>
void add_guess(bool correct);

/// <summary>
/// Gibt die Anzahl der Tipps zurück.
/// </summary>
/// <param name="inclwrong">Inklusive falsche Tipps</param>
/// <returns>Anzahl der Tipps.</returns>
int get_guesses(bool inclwrong);

/// <summary>
/// Gibt ein Score-Objekt zurück.
/// </summary>
struct score get_score();

#endif // SCORE_H
