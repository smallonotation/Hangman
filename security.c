/**
 *  Diese Quell-Datei dient zur Definition der Encrypt - und Decryptfunktionalität.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#include "security.h"

 /// <summary>
 /// Verschlüsselt Text.
 /// </summary>
 /// <param name="text">Text</param>
 /// <returns>Verschlüsselter Text</returns>
char* encrypt(char* text) {
	char secretring[9] = { 13, 33, 44, 21, 66, 17, 253, 112, 0};
	// Encryption
	for (int i = 0; i < strlen(text); i++)
		text[i] ^= secretring[i % 8];
	// Verstecke secret.
	for (int i = 0; i < strlen(secretring); i++)
		secretring[i] = '0';
	return text;
}

/// <summary>
/// Entschlüsselt Text.
/// </summary>
/// <param name="text">Text</param>
/// <returns>Entschlüsselter Text</returns>
char* decrypt(char* text) {
	return encrypt(text);
}
