# Hangman
## graphics.c - Author: Nico Nowak
### change_codepage() - Experimental
Ändert die Codepage um die Ascii-Zeichen für die Rahmen nutzen zu können.
### clear_console()
Löscht alle Zeichen aus der Konsole.
### draw_border(int width, int height) - Experimental
Erzeugt einen Rahmen aus den Ascii-Zeichen. (Die obere Linke Ecke startet an der Cursor-Position)
- width = Die Breite des Rahmens (muss mindestens 2 sein).
- height = Die Höhe des Rahmens (muss mindestens 2 sein).
### draw_hangman(int xPos, int yPos, int errorCount)
Zeichnet (anhand der Position [TBD]) und der aktuellen Fehlerzahl den Hangman.
- xPos = Die X-Position der oberen linken Ecke des Ascii-Arts
- yPos = Die Y-Position der oberen linken Ecke des Ascii-Arts
- errorCount = Die Anzahl der Fehler (Wenn die Fehlerzahl über 11 steigt ist das Spiel verloren).
## dataio.c - Author: Timo Thiede
### setSolutionWord(char* inputSolutionWord)
Eine Funktion für die Speicherung des Lösungswortes.
- inputSolutionword = Das zu speichernde Lösungwort.
### getSolutionword()
Eine Funktion um das Lösungswort zu erhalten
-Return: Das Lösungswort
### inputEnteredChar()
Eine Funktion für die Eingabe der geratenen Buchstaben.
- enteredChar = Eingegebener Buchstabe
- Return: 1 wenn richtig, 0 wenn falsch, -1 wenn der Buchstabe bereits aufgedeckt wurde aber falsch, -2 wenn der Buchstabe aufgedeckt wurde aber richtig ist.
### checkInputEnteredChar(char* inputChar)
Ueberprueft ob die Eingabe korrekt ist.
-inputChar: zu überprüfender Buchstabe.
-Return: JA bei richtiger Eingabe und NEIN bei falscher Eingabe.
### outputDiscoveredLetters()
Diese Funktion gibt das Lösungswort mit den bereits aufgedeckten Buchstaben aus.
Alle nicht aufgedeckten Buchstaben werden als _ dargestellt.
### isSolutionworDiscovered()
Überprüft ob das Lösungswort schon aufegedeckt wurde.
- Return: JA wenn das Lösungswort aufgedeckt wurde und NEIN wenn es nicht aufgedeckt wurde.
### getPlayerName()
Gibt den Spielernamen zurück.
### setPlayerName(char* name)
Speichert den Spielenamen.
-name: Zu speichernde Name.
### outputEnteredChars()
Diese Funktion gibt die bisher eingegebenen Buchstaben in der alphabetischen Reihenfolge aus.
### sortChar(char* letter)
Diese Funktion ist für die Sortierung eines char Arrays in der alphabetischen Reihenfolge.
-letter: Buchstaben, die sortiert werden sollen.
### swap(char* x, char* y)
Eine Funktion, die zwei Chars miteinander tauscht.
-x: Erster Buchstabe.
-y: Zweiter Buchstabe.
### reset()
Stellt den Anfangszustand der IO her.


