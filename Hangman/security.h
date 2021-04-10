/**
 *  Diese Header-Datei dient zur Deklaration der Encrypt - und Decryptfunktionalität.
 *
 *  @author Jesse Kroeske, Timo Thiede - 07.04.2021
 **/

#ifndef SECURITY_H
#define SECURITY_H

#include <stdio.h>
#include <string.h>

/// <summary>
/// Verschlüsselt Text.
/// </summary>
/// <param name="text">Text</param>
/// <returns>Verschlüsselter Text</returns>
char* encrypt(char* text);

/// <summary>
/// Entschlüsselt Text.
/// </summary>
/// <param name="text">Text</param>
/// <returns>Entschlüsselter Text</returns>
char* decrypt(char* text);

#endif // SECURITY_H
