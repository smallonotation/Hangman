/**
 *  Diese Header-Datei dient zur Deklaration der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#ifndef GRAPHICS_H
#define GRAPHICS_H

/// <summary>
///		Ändert die Codepage um die Ascii-Zeichen für die Rahmen nutzen zu können.
/// </summary>
void change_codepage();

/// <summary>
///		Löscht alle Zeichen aus der Konsole.
/// </summary>
void clear_console();

/// <summary>
///		Erzeugt einen Rahmen aus den Ascii-Zeichen. (Die obere Linke Ecke startet an der Cursor-Position)
///		width = Die Breite des Rahmens (muss mindestens 2 sein).
///		height = Die Höhe des Rahmens (muss mindestens 2 sein).
/// </summary>
int draw_border(int width, int height);

#endif // GRAPHICS_H
