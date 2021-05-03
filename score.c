/**
 *  Diese Quell-Datei dient zur Definition der Scoringfunktionalität.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#include "score.h"

struct score gamescore;
time_t start_time = 0;

/// <summary>
/// Startet die Stopwatch.
/// </summary>
void start_stopwatch() {
	start_time = time(NULL);
	gamescore.stopwatch_time = 0;
}

/// <summary>
/// Stoppt die Stopwatch.
/// </summary>
void stop_stopwatch(){
	gamescore.stopwatch_time = time(NULL) - start_time;
}

/// <summary>
/// Gibt die Zeit des Stopwatches zurück in Sekunden.
/// </summary>
/// <returns>Die Zeit oder 0 wenn der Timer nicht gestartet wurde.</returns>
time_t get_stopwatchtime() {
	if (start_time == 0)
		return 0;
	if(gamescore.stopwatch_time == 0)
		return time(NULL) - start_time;
	return gamescore.stopwatch_time;
}

/// <summary>
/// Gibt die Anzahl der Tipps zurück.
/// </summary>
/// <returns>Tippelement.</returns>
struct guesses get_guesses() {
	return gamescore.guesses;
}

/// <summary>
/// Fügt einen Tipp hinzu.
/// </summary>
/// <param name="correct">Tipp korrekt?</param>
void add_guess(bool correct) {
	if (correct)
		gamescore.guesses.correct_guesses++;
	else
		gamescore.guesses.wrong_guesses++;
}

/// <summary>
/// Gibt ein Score-Objekt zurück.
/// </summary>
struct score get_score() {
	return gamescore;
}
