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

void start_timer();
void stop_timer();
time_t get_time();

void add_guess(bool correct);
int get_guesses(bool inclwrong);

struct score get_score();

#endif // SCORE_H
