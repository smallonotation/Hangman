/**
 *  Diese Header-Datei dient zur Deklaration der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#ifndef GRAPHICS_H
#define GRAPHICS_H

 /// <summary>
 ///		Struktur f�r die Cursorposition.
 /// </summary>
struct MousePosition
{
	int cursorX;
	int cursorY;
};

/// <summary>
///		�ndert die Codepage um die Ascii-Zeichen f�r die Rahmen nutzen zu k�nnen.
/// </summary>
void change_codepage();

/// <summary>
///		L�scht alle Zeichen aus der Konsole.
/// </summary>
void clear_console();

/// <summary>
///		Erzeugt einen Rahmen aus den Ascii-Zeichen. (Die obere Linke Ecke startet an der Cursor-Position)
///		width = Die Breite des Rahmens (muss mindestens 2 sein).
///		height = Die H�he des Rahmens (muss mindestens 2 sein).
/// </summary>
int draw_border(int width, int height);

/// <summary>
///		Zeichnet anhand der Position und der aktuellen Fehlerzahl den Hangman.
///		xPos = X-Position
///		yPos = Y-Position
///		errorCount = Die Anzahl der Fehler (Wenn die Fehlerzahl �ber 11 steigt ist das Spiel verloren).
/// </summary>
void draw_hangman(/*int xPos, int yPos,*/ int errorCount);

/// <summary>
///		Speichert die aktuelle Mausposition.
/// </summary>
//struct MousePosition get_mouse_position();

#endif // GRAPHICS_H
