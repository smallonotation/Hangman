/**
 *  Diese Quell-Datei dient zur Definition der Speicher - und Lesevorgänge.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#include "file_io.h"

/// <summary>
/// Gibt die Lines einer Datei zurück.
/// </summary>
/// <param name="path">Pfad</param>
/// <returns>Lines einer Datei</returns>
char** getLines(char* path)
{
    char lines[MAXLINES][MAXSTRINGLENTH];
    char line[MAXSTRINGLENTH] = {0};
    unsigned int line_count = 0;

    /* Open file */
    FILE *file = fopen(path, "r");

    if (!file)
    {
        return 0;
    }

    /* Lines bis end */
    while (fgets(line, MAXSTRINGLENTH, file))
    {
        /* Füge die Line ein. */
        lines[line_count][0] = line;
        ++line_count;

        /* Add a trailing newline to lines that don't already have one */
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
    }

    /* Close file */
    if (fclose(file))
    {
        return 0;
    }

    return lines;
}

/// <summary>
/// Gibt die Lines einer Datei zurück.
/// </summary>
/// <param name="path">Pfad</param>
/// <returns>Zufällige Zeile einer Datei</returns>
const char* getRandomLine(char* path, double chance)
{
    static char line[MAXSTRINGLENTH] = "";
    unsigned int line_count = 0;
    double a = 0;
    srand(time(NULL));

    /* Open file */
    FILE *file = fopen(path, "r");

    if (!file)
    {
        return 0;
    }

    /* Lines bis end */
    while (true)
    {
        if(!fgets(line, MAXSTRINGLENTH, file))
        {
            fclose(file);
            file = fopen(path, "r");
        }
        double a = rand()/(double)RAND_MAX;
        unsigned int random_n=(unsigned int)(BIG_MAXIMUM_NUMBER*a);
        double chance = (double)BIG_MAXIMUM_NUMBER * chance;
        if((double)random_n < (double)BIG_MAXIMUM_NUMBER * chance)
        {
            fclose(file);
            return line;
        }
    }
    return "";
}

/// <summary>
/// Splittet einen Text.
/// </summary>
/// <param name="a_str">Text</param>
/// <param name="a_delim">Delimiter</param>
/// <returns>Splitter</returns>
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

/// <summary>
/// Gibt die Wörter einer CSV-Datei zurück.
/// </summary>
/// <param name="path">Pfad</param>
/// <returns>Wörter einer CSV-Datei</returns>
char*** getCSVLines(char* path)
{
    //char resultLines[MAXLINES][MAXSTRINGLENTH] = getLines(path);
    char resultLines[MAXLINES][MAXSTRINGLENTH];
    char resultFromCSV[MAXLINES][MAXWORDS][MAXSTRINGLENTH];
    for(int i = 0; *(resultLines + i); i++)
    {
        char** split = str_split(*(resultLines + i), ';');
        for (int k = 0; *(split + k); k++)
        {
            //resultFromCSV[i][k] = *(split + k));
            free(*(split + k));
        }
    }
    return resultFromCSV;
}

void encryptFile(char* path)
{
    FILE* file = fopen(path, "r");
    FILE* fTemp = fopen("replace.tmp", "w");

    if (file == NULL || fTemp == NULL)
    {
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        fputs(encrypt(line), fTemp);
    }
    fclose(file);
    fclose(fTemp);
    remove(path);
    rename("replace.tmp", path);
}
