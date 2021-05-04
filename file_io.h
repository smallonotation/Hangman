/**
 *  Diese Header-Datei dient zur Deklaration der Speicher - und Lesevorgänge.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "security.h"

#define MAXSTRINGLENTH 255
#define MAXWORDS 10
#define MAXLINES 100
#define BIG_MAXIMUM_NUMBER 4294967295

char** getLines(char* path);

char** str_split(char* a_str, const char a_delim);

char*** getCSVLines(char* path);

void savePlayerStats(char* name, int highscoretime, int correct_guesses, int wrong_guesses, char* word);

void encryptFile(char* path);

const char* getRandomLine(char* path, double chance);

#endif // FILE_IO_H
