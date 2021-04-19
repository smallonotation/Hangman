/**
 *  Diese Quell-Datei dient zur Definition der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#include <windows.h>
#include <stdio.h>
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
	int i, j;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == 0 && j == 0)
			{
				printf("\xC9");
			}
			else if (i == 0 && j == width - 1)
			{
				printf("\xBB");
			}
			else if (i == height - 1 && j == 0)
			{
				printf("\xC8");
			}
			else if (i == height - 1 && j == width - 1)
			{
				printf("\xBC");
			}
			else if (i == 0 || i == height - 1)
			{
				printf("\xCD");
			}
			else if (j == 0 || j == width - 1)
			{
				printf("\xBA");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}

void draw_hangman(/*int xPos, int yPos,*/ int errorCount)
{
	switch (errorCount)
	{
	case 0:
	{

	}
	case 1:
	{

	}
	case 2:
	{

	}
	case 3:
	{

	}
	case 4:
	{

	}
	case 5:
	{

	}
	case 6:
	{

	}
	case 7:
	{

	}
	case 8:
	{

	}
	case 9:
	{

	}
	case 10:
	{

	}
	case 11:
	{

	}
	default:
	{

	}
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
