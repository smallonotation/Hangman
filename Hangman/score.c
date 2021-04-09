/**
 *  Diese Quell-Datei dient zur Definition der Scoringfunktionalität.
 *
 *  @author Jesse Kroeske, Timo Thiede - 07.04.2021
 **/

#include "score.h"

struct score gamescore;
time_t start_time = 0;

/// <summary>
/// Startet den Timer.
/// </summary>
void start_timer() {
	start_time = time(NULL);
	gamescore.time = 0;
}

/// <summary>
/// Stoppt den Timer.
/// </summary>
void stop_timer(){
	gamescore.time = time(NULL) - start_time;
}

/// <summary>
/// Gibt die Zeit des Timers zurück in Sekunden.
/// </summary>
/// <returns>Die Zeit oder 0 wenn der Timer nicht gestartet wurde.</returns>
time_t get_time() {
	if (start_time == 0)
		return 0;
	if(gamescore.time == 0)
		return time(NULL) - start_time;
	return gamescore.time;
}

/// <summary>
/// Gibt die Anzahl der Tipps zurück.
/// </summary>
/// <param name="inclwrong">Inklusive falsche Tipps</param>
/// <returns>Anzahl der Tipps.</returns>
int get_guesses(bool inclwrong) {
	if (inclwrong)
		return gamescore.guesses - gamescore.wrong_guesses;
	return gamescore.guesses;
}

/// <summary>
/// Fügt einen Tipp hinzu.
/// </summary>
/// <param name="correct">Tipp korrekt?</param>
void add_guess(bool correct) {
	gamescore.guesses++;
	if (!correct)
		gamescore.wrong_guesses++;
}

/// <summary>
/// Gibt ein Score-Objekt zurück.
/// </summary>
struct score get_score() {
	return gamescore;
}