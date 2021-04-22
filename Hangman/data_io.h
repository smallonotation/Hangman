/**
 *  Diese Header-Datei dient zur Deklaration des Input-Output-Streams vom Hangman.
 *  Dabei werden User-Inputs abgefangen und Output-Nachrichten generiert.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

#ifndef DATA_IO_H
#define DATA_IO_H
void inputEnteredChar(char enteredChar);
void inputSolutionWord(char* inputSolutionWord);
void outputDiscoveredLetters();
void outputEnteredChars();
void sortChar(char* letter);
void swap(char* x, char* y);
#endif // DATA_IO_H
