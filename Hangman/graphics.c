/**
 *  Diese Quell-Datei dient zur Definition der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

//#include <windows.h>
#include "graphics.h"

void change_codepage()
{
	// Ändert die Codepage zu 437 für die Ascii-Zeichen des Rahmens.
	system("chcp 437");
}

void clear_console()
{
	// Löscht alle Zeichen die sich in der Konsole befinden.
	system("cls");
}

int draw_border(int width, int height)
{
	// Zählervariablen
	int y, x;

	// Rahmen erzeugen.
	// Y-Achse
	for (y = 0; y < height; y++)
	{
		// X-Achse auf der Höhe Y
		for (x = 0; x < width; x++)
		{
			if (y == 0 && x == 0)
			{
				printf("\xC9");
			}
			else if (y == 0 && x == width - 1)
			{
				printf("\xBB");
			}
			else if (y == height - 1 && x == 0)
			{
				printf("\xC8");
			}
			else if (y == height - 1 && x == width - 1)
			{
				printf("\xBC");
			}
			else if (y == 0 || y == height)
			{
				printf("\xCD");
			}
			else if (x == 0 || x == width - 1)
			{
				printf("\xBA");
			}
			else
			{
				printf(" ");
			}
		}
	}

	return 0;
}

void draw_hangman(int xPos, int yPos, int errorCount)
{
	switch (errorCount)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	default: // > 11
	}
}

/*
struct MousePosition get_mouse_position()
{
	struct MousePosition position;

	position.cursorX = wherex();
	position.cursorY = wherey();

	return position;
}
*/