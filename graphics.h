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
void changeCodepage();

/// <summary>
///		L�scht alle Zeichen aus der Konsole.
/// </summary>
void clearConsole();

/// <summary>
///		Erzeugt einen Rahmen aus den Ascii-Zeichen. (Die obere Linke Ecke startet an der Cursor-Position)
///		width = Die Breite des Rahmens (muss mindestens 2 sein).
///		height = Die H�he des Rahmens (muss mindestens 2 sein).
/// </summary>
int drawBorder(int width, int height);

/// <summary>
///		Zeichnet anhand der Position und der aktuellen Fehlerzahl den Hangman.
///		xPos = X-Position
///		yPos = Y-Position
///		errorCount = Die Anzahl der Fehler (Wenn die Fehlerzahl �ber 11 steigt ist das Spiel verloren).
/// </summary>
void drawHangman(/*int xPos, int yPos,*/ int errorCount);

/// <summary>
///		Setzt den Konsolen-Cursor an die gew�hlte Position der Konsole.
///		xCoord = X-Position
///		yCoord = Y-Position
/// </summary>
int setCursorPosition(int xCoord, int yCoord);

/// <summary>
///     Setzt den Konsolen-Cursor auf 0,1.
/// </summary>
int resetCursorPosition();

#endif // GRAPHICS_H
