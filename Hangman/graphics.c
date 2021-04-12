/**
 *  Diese Quell-Datei dient zur Definition der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

//#include <windows.h>
#include "graphics.h"

void change_codepage()
{
	// �ndert die Codepage zu 437 f�r die Ascii-Zeichen des Rahmens.
	system("chcp 437");
}

void clear_console()
{
	// L�scht alle Zeichen die sich in der Konsole befinden.
	system("cls");
}

int draw_border(int width, int height)
{
	// Z�hlervariablen
	int y, x;

	// Rahmen erzeugen.
	// Y-Achse
	for (y = 0; y < height; y++)
	{
		// X-Achse auf der H�he Y
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