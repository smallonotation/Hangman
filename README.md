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
