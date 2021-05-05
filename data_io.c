/**
 *  Diese Quell-Datei dient zur Definition des Input-Output-Streams vom Hangman.
 *  Dabei werden User-Inputs abgefangen und Output-Nachrichten generiert.
 *
 *  @author Jesse Kroeske, Nico Nowak, Timo Thiede - 19.04.2021
 **/

#include "data_io.h"
#define MAXSTRING 100
#define BUFFER_SIZE 1000

struct wordAndLetters solutionWordAndDiscoveredLetters;
char* playerName;

/// <summary>
/// Eine Funktion für die Speicherung des Lösungswortes.
/// </summary>
/// <param name="inputSolutionWord">Das zu speichernde Lösungwort</param>
void setSolutionWord(char* inputSolutionWord)
{
    int i, length;
    char c;
    i = 0;
    length = strlen(inputSolutionWord);
    while (i < length)
    {
        c = inputSolutionWord[i];
        c = toupper(c);
        solutionWordAndDiscoveredLetters.solutionWord[i] = c;
        i++;
    }
}


/// <summary>
/// Eine Funktion um das Lösungswort zu erhalten
/// </summary>
/// <returns>Das Lösungswort</returns>
char* getSolutionword()
{
    return(solutionWordAndDiscoveredLetters.solutionWord);
}

/// <summary>
/// Eine Funktion für die Eingabe der geratenen Buchstaben.
/// </summary>
/// <param name="enteredChar">Eingegebener Buchstabe</param>
/// <returns>1 wenn richtig, 0 wenn falsch, -1 wenn der Buchstabe bereits aufgedeckt wurde aber falsch, -2 wenn der Buchstabe aufgedeckt wurde aber richtig ist.</returns>
int inputEnteredChar()
{
    char enteredLetter[MAXSTRING] = "";
    printf("Geben Sie einen Buchstaben ein: ");
    scanf("%s", &enteredLetter);
    if (checkInputEnteredChar(enteredLetter))
    {
        enteredLetter[0] = toupper(enteredLetter[0]);
        int length = strlen(solutionWordAndDiscoveredLetters.enteredLetters);
        solutionWordAndDiscoveredLetters.enteredLetters[length] = enteredLetter[0];
        int result = 0;
        // Überprüft, ob der Buchstabe bereits einmal eingegeben wurde.
        for(int i = 0; i < length; i++)
        {
            if (solutionWordAndDiscoveredLetters.enteredLetters[i] == enteredLetter[0])
            {
                result = -1;
                break;
            }
        }
        // Überprüft, ob der Buchstabe richtig oder falsch ist.
        for(int i = 0; i < strlen(solutionWordAndDiscoveredLetters.solutionWord); i++)
        {
            if (solutionWordAndDiscoveredLetters.solutionWord[i] == enteredLetter[0])
            {
                if(result == -1)
                {
                    return -2;
                }
                result = 1;
                break;
            }
        }
        return result;

    }//Fehlermeldung erfolgt in checkInputEnteredChar

    return -1;
}

/// <summary>
/// Ueberprueft ob die Eingabe korrekt ist.
/// </summary>
/// <param name="inputChar">Zu überprüfender Buchstabe</param>
/// <returns>JA bei richtiger Eingabe und NEIN bei falscher Eingabe.</returns>
bool checkInputEnteredChar(char* inputChar)
{
    char c;
    if (strlen(inputChar) > 1)
    {
        printf("\nBitte geben Sie nur einen Buchstaben ein!");
        return false;
    }
    c = inputChar[0];
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return true;

    }
    else
    {
        printf("\nBitte geben Sie nur Buchstaben ein.");
        return false;
    }

}
/// <summary>
/// Diese Funktion gibt das Lösungswort mit den bereits aufgedeckten Buchstaben aus.
/// Alle nicht aufgedeckten Buchstaben werden als _ dargestellt.
/// </summary>
void outputDiscoveredLetters()
{
    int i, j, lengthWord, lengthEnteredChars;
    lengthWord = strlen(solutionWordAndDiscoveredLetters.solutionWord);
    lengthEnteredChars = strlen(solutionWordAndDiscoveredLetters.enteredLetters);
    for (i = 0; i < lengthWord; i++)
    {
        for (j = 0; j < lengthEnteredChars; j++)
        {
            if (solutionWordAndDiscoveredLetters.solutionWord[i] == solutionWordAndDiscoveredLetters.enteredLetters[j])
            {
                printf("%c", solutionWordAndDiscoveredLetters.solutionWord[i]);
                break;
            }
            else if (j == lengthEnteredChars - 1)
            {
                printf("_");
            }
        }
        if(lengthEnteredChars == 0)
            printf("_");
    }
    printf("\n");
}

/// <summary>
/// Überprüft ob das Lösungswort schon aufegedeckt wurde.
/// </summary>
/// <returns>JA wenn das Lösungswort aufgedeckt wurde und NEIN wenn es nicht aufgedeckt wurde</returns>
bool isSolutionworDiscovered()
{
    int i, j, lengthSolutionWord, counter;
    lengthSolutionWord = strlen(solutionWordAndDiscoveredLetters.solutionWord);
    counter = 0;
    sortChar(solutionWordAndDiscoveredLetters.enteredLetters);
    for(i = 0; i < strlen(solutionWordAndDiscoveredLetters.solutionWord); i++)
    {
        for(j = 0; j < strlen(solutionWordAndDiscoveredLetters.enteredLetters); j++)
        {
            if (solutionWordAndDiscoveredLetters.solutionWord[i] == solutionWordAndDiscoveredLetters.enteredLetters[j])
            {
                counter++;
            }
        }
    }
    if (counter == lengthSolutionWord)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Speichert den Spielenamen.
/// </summary>
char* getPlayerName()
{
    return playerName;
}

/// <summary>
/// Speichert den Spielernamen.
///<param name="name">Zu speichernde Name</param>
/// </summary>
void setPlayerName(char* name)
{
    printf("Bitte geben Sie ihren Spielernamen ein: ");
    scanf("%s", &playerName);
}

/// <summary>
/// Diese Funktion gibt die bisher eingegebenen Buchstaben in der alphabetischen Reihenfolge aus.
/// </summary>
void outputEnteredChars()
{
    int i, length;
    printf("Folgende Buchstaben haben Sie bisher eingegeben: ");
    length = strlen(solutionWordAndDiscoveredLetters.enteredLetters);
    sortChar(solutionWordAndDiscoveredLetters.enteredLetters);
    for (i = 0; i < length; i++)
    {
        printf("%c", solutionWordAndDiscoveredLetters.enteredLetters[i]);
    }
    printf("\n");
}

/// <summary>
/// Diese Funktion ist für die Sortierung eines char Arrays in der alphabetischen Reihenfolge.
/// </summary>
/// <param name="letter">Buchstaben, die sortiert werden sollen.</param>
void sortChar(char* letter)
{
    int i, j, length;
    length = strlen(letter);
    for (i = 0; i < length - 1; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (letter[i] > letter[j])
            {
                swap(&letter[i], &letter[j]);
            }
        }
    }
    int n = sizeof(letter) / sizeof(letter[0]);
    n = removeDuplicates(letter, n);
}

int removeDuplicates(char arr[], int n)
{
    if (n==0 || n==1)
        return n;

    int temp[n];

    int j = 0;
    for (int i=0; i<n-1; i++)
    {
        if (arr[i] != arr[i+1])
            temp[j++] = arr[i];
    }
    temp[j++] = arr[n-1];

    for (int i=0; i<j; i++)
        arr[i] = temp[i];

    return j;
}

/// <summary>
/// Eine Funktion, die zwei Chars miteinander tauscht.
/// </summary>
/// <param name="x">Erster Buchstabe</param>
/// <param name="y">Zweiter Buchstabe</param>
void swap(char* x, char* y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

/// <summary>
/// Stellt den Anfangszustand der IO her.
/// </summary>
void reset(){
    strcpy(solutionWordAndDiscoveredLetters.enteredLetters, "");
    strcpy(solutionWordAndDiscoveredLetters.solutionWord, "");
}
