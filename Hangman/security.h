/**
 *  Diese Header-Datei dient zur Deklaration der Encrypt - und Decryptfunktionalit�t.
 *
 *  @author Jesse Kroeske, Timo Thiede - 07.04.2021
 **/

#ifndef SECURITY_H
#define SECURITY_H

#include <stdio.h>
#include <string.h>

/// <summary>
/// Verschl�sselt Text.
/// </summary>
/// <param name="text">Text</param>
/// <returns>Verschl�sselter Text</returns>
char* encrypt(char* text);

/// <summary>
/// Entschl�sselt Text.
/// </summary>
/// <param name="text">Text</param>
/// <returns>Entschl�sselter Text</returns>
char* decrypt(char* text);

#endif // SECURITY_H
