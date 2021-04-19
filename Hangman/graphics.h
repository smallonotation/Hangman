/**
 *  Diese Header-Datei dient zur Deklaration der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#ifndef GRAPHICS_H
#define GRAPHICS_H

 /// <summary>
 ///		Struktur für die Cursorposition.
 /// </summary>
struct MousePosition
{
	int cursorX;
	int cursorY;
};

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

/// <summary>
///		Zeichnet anhand der Position und der aktuellen Fehlerzahl den Hangman.
///		xPos = X-Position
///		yPos = Y-Position
///		errorCount = Die Anzahl der Fehler (Wenn die Fehlerzahl über 11 steigt ist das Spiel verloren).
/// </summary>
void draw_hangman(/*int xPos, int yPos,*/ int errorCount);

/// <summary>
///		Speichert die aktuelle Mausposition.
/// </summary>
//struct MousePosition get_mouse_position();

#endif // GRAPHICS_H
