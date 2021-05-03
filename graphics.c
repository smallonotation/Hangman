/**
 *  Diese Quell-Datei dient zur Definition der Grafiken.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

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
void drawHangman(int xPos, int yPos, int errorCount)
{
    switch (errorCount)
    {
    case 0:
    {
        // Nichts
        break;
    }
    case 1:
    {
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 2:
    {
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 3:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 4:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            if(i <= 2)
                printf("  |     | ");
            else
                printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 5:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            if(i <= 2)
                printf("  |     | ");
            else if(i == 3)
                printf("  O     | ");
            else
                printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 6:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            if(i <= 2)
                printf("  |     | ");
            else if(i == 3)
                printf("  O     | ");
            else if(i <= 5)
                printf("  |     | ");
            else
                printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 7:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            if(i <= 2)
                printf("  |     | ");
            else if(i == 3)
                printf("  O     | ");
            else if(i <= 5)
                printf("  |     | ");
            else if(i == 6)
                printf(" /      | ");
            else
                printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 8:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            if(i <= 2)
                printf("  |     | ");
            else if(i == 3)
                printf("  O     | ");
            else if(i <= 5)
                printf("  |     | ");
            else if(i == 6)
                printf(" / \\    | ");
            else
                printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 9:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            if(i <= 2)
                printf("  |     | ");
            else if(i == 3)
                printf("  O     | ");
            else if(i == 4)
                printf(" /|     | ");
            else if(i == 5)
                printf("  |     | ");
            else if(i == 6)
                printf(" / \\    | ");
            else
                printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    case 10:
    {
        setCursorPosition(xPos, yPos);
        printf("==========");
        for(int i = 1; i < 9; i++)
        {
            setCursorPosition(xPos, yPos + i);
            if(i <= 2)
                printf("  |     | ");
            else if(i == 3)
                printf("  O     | ");
            else if(i == 4)
                printf(" /|\\    | ");
            else if(i == 5)
                printf("  |     | ");
            else if(i == 6)
                printf(" / \\    | ");
            else
                printf("        | ");
        }
        setCursorPosition(xPos, yPos + 9);
        printf("==========");
        break;
    }
    default:
    {
        for(int i = 0; i < 10; i++)
        {
            setCursorPosition(xPos, yPos + i);
            printf("                          ");
        }
        break;
    }
    }
}

int setCursorPosition(int xCoord, int yCoord)
{
    COORD coord;
    coord.X = xCoord;
    coord.Y = yCoord;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return 0;
}

int resetCursorPosition()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return 0;
}
