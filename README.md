# Hangman
## graphics.c - Author: Nico Nowak
### change_codepage() - Experimental : void
Ändert die Codepage um die Ascii-Zeichen für die Rahmen nutzen zu können.
### clear_console() : void
Löscht alle Zeichen aus der Konsole.
### draw_border(int width, int height) - Experimental : int
Erzeugt einen Rahmen aus den Ascii-Zeichen. (Die obere Linke Ecke startet an der Cursor-Position)
- width = Die Breite des Rahmens (muss mindestens 2 sein).
- height = Die Höhe des Rahmens (muss mindestens 2 sein).
### draw_hangman(int xPos, int yPos, int errorCount) : void
Zeichnet anhand der Position und der aktuellen Fehlerzahl den Hangman.
- xPos = Die X-Position der oberen linken Ecke des Ascii-Arts
- yPos = Die Y-Position der oberen linken Ecke des Ascii-Arts
- errorCount = Die Anzahl der Fehler (Wenn die Fehlerzahl über 11 steigt ist das Spiel verloren).
## dataio.c - Author: Timo Thiede
### setSolutionWord(char* inputSolutionWord) : void
Eine Funktion für die Speicherung des Lösungswortes.
- inputSolutionword = Das zu speichernde Lösungwort.
### getSolutionword() : char*
Eine Funktion um das Lösungswort zu erhalten
-Return: Das Lösungswort
### inputEnteredChar() : int
Eine Funktion für die Eingabe der geratenen Buchstaben.
- enteredChar = Eingegebener Buchstabe
- Return: 1 wenn richtig, 0 wenn falsch, -1 wenn der Buchstabe bereits aufgedeckt wurde aber falsch, -2 wenn der Buchstabe aufgedeckt wurde aber richtig ist.
### checkInputEnteredChar(char* inputChar) : bool
Ueberprueft ob die Eingabe korrekt ist.
-inputChar: zu überprüfender Buchstabe.
-Return: JA bei richtiger Eingabe und NEIN bei falscher Eingabe.
### outputDiscoveredLetters() : void
Diese Funktion gibt das Lösungswort mit den bereits aufgedeckten Buchstaben aus.
Alle nicht aufgedeckten Buchstaben werden als _ dargestellt.
### isSolutionworDiscovered() : bool
Überprüft ob das Lösungswort schon aufegedeckt wurde.
- Return: JA wenn das Lösungswort aufgedeckt wurde und NEIN wenn es nicht aufgedeckt wurde.
### getPlayerName() : char*
Gibt den Spielernamen zurück.
### setPlayerName(char* name) : void
Speichert den Spielenamen.
-name: Zu speichernde Name.
### outputEnteredChars() : void
Diese Funktion gibt die bisher eingegebenen Buchstaben in der alphabetischen Reihenfolge aus.
### sortChar(char* letter) : void
Diese Funktion ist für die Sortierung eines char Arrays in der alphabetischen Reihenfolge.
-letter: Buchstaben, die sortiert werden sollen.
### swap(char* x, char* y) : void
Eine Funktion, die zwei Chars miteinander tauscht.
-x: Erster Buchstabe.
-y: Zweiter Buchstabe.
### reset() : void
Stellt den Anfangszustand der IO her.
## file_io.c - Author: Jesse Kroeske
### getLines(char* path) : char**
Gibt die Zeilen einer Datei zurück.
-path: Pfad der Datei.
### str_split(char* a_str, const char a_delim) : char**
Splittet eine Zeichenfolge mithilfe der übergebenen delimiter.
-a_str: Zu splittender String.
-a_delim: Delimiter.
### getCSVLines(char* path) : char***
Gibt die Felder einer CSV-Datei zurück.
-path: Pfad der CSV-Datei.
### savePlayerStats(char* name, int highscoretime, int correct_guesses, int wrong_guesses, char* word) : void
Speichert die Spielerdaten in einer Datei.
-name: Name des Spielers.
-highscoretime: Zeit des Highscores.
-correct_guesses: Richtige Eingaben.
-wrong_guesses: Falsche Eingaben.
-word: Spielwort.
### encryptFile(char* path) : void
Verschlüsselt einer Datei, wobei jede Zeile einzelnd verschlüsselt wird.
-path: Pfad.
### getRandomLine(char* path, double chance) : const char*
Ermittelt eine Zufällige Zeile aus einer Datei.
-path: Pfad.
-chance: Wahrscheinlichkeit.
## hangman.c - Author: Jesse Kroeske
### game_won() : bool
Gibt zurück, ob das Spiel gewonnen wurde.
### game_lost() : bool
Gibt zurück, ob das Spiel verloren ist.
### set_game_status(bool won) : void
Setzt den Spielstand.
-won: Gewonnen.
### game_start() : void
Startet das Spiel.
### game_progress() : void
Stellt das Spiel dar.
### game_end() : void
Ende des Spiels.
### print_score() : void
Anzeige der Score.
## score.c - Author: Jesse Kroeske
### start_stopwatch() : void
Startet die Stopwatch.
### stop_stopwatch() : void
Stoppt die Stopwatch.
### get_stopwatchtime() : time_t
Gibt die Zeit des Stopwatches zurück in Sekunden.
### add_guess(bool correct) : void
Fügt einen Tipp hinzu.
-correct: Eingabe korrekt.
### get_guesses() : guesses
Gibt die Anzahl der Tipps zurück.
### get_score() : score
Gibt ein Score-Objekt zurück.
## security.c - Author: Jesse Kroeske
### encrypt(char* text) : char*
Verschlüsselt Text.
-text: Text.
### decrypt(char* text) : char*
Entschlüsselt Text.
-text: Text.

