/**
 *  Diese Quell-Datei dient zur Definition der Scoringfunktionalit�t.
 *
 *  @author Jesse Kroeske, Timo Thiede - 07.04.2021
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
/// Gibt die Zeit des Stopwatches zur�ck in Sekunden.
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
/// Gibt die Anzahl der Tipps zur�ck.
/// </summary>
/// <param name="inclwrong">Inklusive falsche Tipps</param>
/// <returns>Anzahl der Tipps.</returns>
int get_guesses(bool inclwrong) {
	if (inclwrong)
		return gamescore.guesses - gamescore.wrong_guesses;
	return gamescore.guesses;
}

/// <summary>
/// F�gt einen Tipp hinzu.
/// </summary>
/// <param name="correct">Tipp korrekt?</param>
void add_guess(bool correct) {
	gamescore.guesses++;
	if (!correct)
		gamescore.wrong_guesses++;
}

/// <summary>
/// Gibt ein Score-Objekt zur�ck.
/// </summary>
struct score get_score() {
	return gamescore;
}