/**
 *  Diese Header-Datei dient zur Deklaration des Input-Output-Streams vom Hangman.
 *  Dabei werden User-Inputs abgefangen und Output-Nachrichten generiert.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

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
void inputEnteredChar();
void outputDiscoveredLetters();
void outputEnteredChars();
void sortChar(char* letter);
void swap(char* x, char* y);
bool checkInputEnteredChar(char* inputChar);
char* getPlayerName();
void setPlayerName();
bool isSolutionworDiscovered();
#endif // DATA_IO_H
