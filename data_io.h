/**
 *  Diese Header-Datei dient zur Deklaration des Input-Output-Streams vom Hangman.
 *  Dabei werden User-Inputs abgefangen und Output-Nachrichten generiert.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Include ist für toupper(char) - :-)
#include <ctype.h>

#ifndef DATA_IO_H
#define DATA_IO_H
#define MAXSTRING 100

struct wordAndLetters {
    char solutionWord[MAXSTRING];
    char enteredLetters[MAXSTRING];
};

extern struct wordAndLetters solutionWordAndDiscoveredLetters;

void setSolutionWord(char* inputSolutionWord);

char* getSolutionword();

/// <summary>
/// Eine Funktion für die Eingabe der geratenen Buchstaben.
/// </summary>
/// <param name="enteredChar">Eingegebener Buchstabe</param>
/// <returns>1 wenn richtig, 0 wenn falsch, -1 wenn der Buchstabe bereits aufgedeckt wurde.</returns>
int inputEnteredChar();

void outputDiscoveredLetters();

void outputEnteredChars();

void sortChar(char* letter);

void swap(char* x, char* y);

bool checkInputEnteredChar(char* inputChar);

char* getPlayerName();

void setPlayerName();

bool isSolutionworDiscovered();

char* getSolutionWord();

/// <summary>
/// Stellt den Anfangszustand der IO her.
/// </summary>
void reset();

#endif // DATA_IO_H
