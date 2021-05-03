/**
 *  Diese Quell-Datei dient zur Definition der Encrypt - und Decryptfunktionalit�t.
 *
 *  @author Jesse Kroeske, Timo Thiede, Nico Nowak - 07.04.2021
 **/

#include "security.h"

 /// <summary>
 /// Verschl�sselt Text.
 /// </summary>
 /// <param name="text">Text</param>
 /// <returns>Verschl�sselter Text</returns>
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
/// Entschl�sselt Text.
/// </summary>
/// <param name="text">Text</param>
/// <returns>Entschl�sselter Text</returns>
char* decrypt(char* text) {
	return encrypt(text);
}
