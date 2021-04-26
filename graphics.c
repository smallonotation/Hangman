/**
 *  Diese Quell-Datei dient zur Definition der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#include <windows.h>
#include <stdio.h>
#include "graphics.h"

void changeCodepage()
{
	// Ändert die Codepage zu 437 für die Ascii-Zeichen des Rahmens.
	system("chcp 437");
}

void clearConsole()
{
	// Löscht alle Zeichen die sich in der Konsole befinden.
	system("cls");
}

int drawBorder(int width, int height)
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

/*
10 x 10 - Feld
+----------+
| ======== | 1
|  |     | | 2
|  |     | | 3
|  O     | | 4
| /|\    | | 5
|  |     | | 6
| / \    | | 7
|        | | 8
|        | | 9
|==========| 10
+----------+
 12345678910
*/
void drawHangman(/*int xPos, int yPos,*/ int errorCount)
{
	switch (errorCount)
	{
	case 0:
	{
		printf("          \n          \n          \n          \n          \n          \n          \n          \n          \n          ");
		break;
	}
	case 1:
	{
		printf("          \n          \n          \n          \n          \n          \n          \n          \n          \n==========");
		break;
	}
	case 2:
	{
		printf("          \n        | \n        | \n        | \n        | \n        | \n        | \n        | \n        | \n==========");
		break;
	}
	case 3:
	{
		printf(" =========\n        | \n        | \n        | \n        | \n        | \n        | \n        | \n        | \n==========");
		break;
	}
	case 4:
	{
		printf(" =========\n  |     | \n  |     | \n        | \n        | \n        | \n        | \n        | \n        | \n==========");
		break;
	}
	case 5:
	{
		printf(" =========\n  |     | \n  |     | \n  O     | \n        | \n        | \n        | \n        | \n        | \n==========");
		break;
	}
	case 6:
	{
		printf(" =========\n  |     | \n  |     | \n  O     | \n  |     | \n  |     | \n        | \n        | \n        | \n==========");
		break;
	}
	case 7:
	{
		printf(" =========\n  |     | \n  |     | \n  O     | \n  |     | \n  |     | \n /      | \n        | \n        | \n==========");
		break;
	}
	case 8:
	{
		printf(" =========\n  |     | \n  |     | \n  O     | \n  |     | \n  |     | \n / \\    | \n        | \n        | \n==========");
		break;
	}
	case 9:
	{
		printf(" =========\n  |     | \n  |     | \n  O     | \n /|     | \n  |     | \n / \\    | \n        | \n        | \n==========");
		break;
	}
	case 10:
	{
		printf(" =========\n  |     | \n  |     | \n  O     | \n /|\\    | \n  |     | \n / \\    | \n        | \n        | \n==========");
		break;
	}
	default:
	{
		break;
	}
	}
}
