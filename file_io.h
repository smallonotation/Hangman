/**
 *  Diese Header-Datei dient zur Deklaration der Speicher - und Lesevorgänge.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <assert.h>

#define MAXSTRINGLENTH 255
#define MAXWORDS 10
#define MAXLINES 100

char** getLines(char* path);

char** str_split(char* a_str, const char a_delim);

char*** getCSVLines(char* path);

#endif // FILE_IO_H
