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

struct guesses {
	int wrong_guesses;
	int correct_guesses;
};

struct score {
	time_t stopwatch_time;
	struct guesses guesses;
};

extern struct score gamescore;
extern time_t start_time;

/// <summary>
/// Startet die Stopwatch.
/// </summary>
void start_stopwatch();

/// <summary>
/// Stoppt die Stopwatch.
/// </summary>
void stop_stopwatch();

/// <summary>
/// Gibt die Zeit des Stopwatches zurück in Sekunden.
/// </summary>
/// <returns>Die Zeit oder 0 wenn der Timer nicht gestartet wurde.</returns>
time_t get_stopwatchtime();

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
struct guesses get_guesses();

/// <summary>
/// Gibt ein Score-Objekt zurück.
/// </summary>
struct score get_score();

#endif // SCORE_H
