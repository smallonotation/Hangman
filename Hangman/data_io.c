/**
 *  Diese Quell-Datei dient zur Definition des Input-Output-Streams vom Hangman.
 *  Dabei werden User-Inputs abgefangen und Output-Nachrichten generiert.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_io.h"
#define MAXSTRING 100

char enteredChars[MAXSTRING];
char* solutionWord;


/// <summary>
/// Eine Funktion für die Eingabe der geratenen Buchstaben. 
/// </summary>
/// <param name="enteredChar">Eingegebener Buchstabe</param>
void inputEnteredChar(char enteredChar)
{
	int length = strlen(enteredChars);
	enteredChars[length] = enteredChar;
}

/// <summary>
/// Eine Funktion für die Speicherung des Lösungswortes.
/// </summary>
/// <param name="inputSolutionWord">Eingegebenes Lösungswort</param>
void inputSolutionWord(char* inputSolutionWord)
{
	solutionWord = inputSolutionWord;
	//strncpy(solutionWord, inputSolutionWord, MAXSTRING);
	printf("Test: %s\n", solutionWord);
}

/// <summary>
/// Diese Funktion gibt das Lösungswort mit den bereits aufgedeckten Buchstaben aus.
/// Alle nicht aufgedeckten Buchstaben werden als _ dargestellt.
/// </summary>
void outputDiscoveredLetters()
{
	int i, j, lengthWord, lengthEnteredChars;

	lengthWord = strlen(solutionWord);
	lengthEnteredChars = strlen(enteredChars);
	for (i = 0; i < lengthWord; i++)
	{
		for (j = 0; j < lengthEnteredChars; j++)
		{
			if (solutionWord[i] == enteredChars[j]) {
				printf("%c", solutionWord[i]);
				break;
			}
			else if (j == lengthEnteredChars - 1) {
				printf("_");
			}
		}
	}
	printf("\n");
}

/// <summary>
/// Diese Funktion gibt die bisher eingegebenen Buchstaben in der alphabetischen Reihenfolge aus.
/// </summary>
void outputEnteredChars()
{
	int i, length;
	length = strlen(enteredChars);
	sortChar(enteredChars);
	for (i = 0; i < length; i++){
		printf("%c", enteredChars[i]);
	}
}

/// <summary>
/// Diese Funktion ist für die Sortierung eines char Arrays in der alphabetischen Reihenfolge.
/// </summary>
/// <param name="letter">Buchstaben, die sortiert werden sollen.</param>
void sortChar(char* letter) {
	int i, j, length;
	length = strlen(letter);
	for (i = 0; i < length - 1; i++) {
		for (j = i + 1; j < length; j++) {
			if (letter[i] > letter[j]) {
				swap(&letter[i], &letter[j]);
			}
		}
	}
}

/// <summary>
/// Eine Funktion, die zwei Chars miteinander tauscht.
/// </summary>
/// <param name="x">Erster Buchstabe</param>
/// <param name="y">Zweiter Buchstabe</param>
void swap(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}