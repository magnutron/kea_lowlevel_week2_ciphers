#include <stdio.h>
#include "cipher.h"

char alphabet[59];

int letterToNumber(char letter) {
    for (int i = 0; i < 58; i++) {
        // Check if the current array element matches the letter
        if (alphabet[i] == letter) {
            return i;  // Return the index if a match is found
        }
    }
    return -1;  // Return -1 if the letter is not found
}

void textToNumbers(const char* text) {
    while (*text) {               // Iterate through each character in the string
        printf("Character: '%c' ASCII value: %d\n", *text, (int)(*text));
        text++;                   // Move to the next character
    }
}

int shift(int number, int shiftvalue) {
    // Check if the number is within the printable ASCII range
    if (number >= 32 && number <= 126) {
        return (number - 32 + shiftvalue) % 95 + 32;
    }
    return number;  // Return as-is if not in printable ASCII range
}

void encrypt(char* text, int shiftValue) {
    while (*text) {
        *text = (char) shift((int) *text, shiftValue);
        text++;
    }
}

void decrypt(char* text, int shiftValue) {
    // To decrypt, we shift by the negative of the encryption shift value
    while (*text) {
        *text = (char) shift((int) *text, -shiftValue);
        text++;
    }
}

void init(char alphabet[]) {
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;  // Assigning 'a' + i to fill alphabet from 'a' to 'z'
    }

    alphabet[26] = (char)195;  // First byte for UTF-8 encoding of first byte for æøå
    alphabet[27] = (char)166;  // Second byte for UTF-8 encoding of 'æ'
    alphabet[28] = (char)184;  // Second byte for UTF-8 encoding of 'ø'
    alphabet[29] = (char)165;  // Second byte for UTF-8 encoding of 'å'

    for (int i = 30; i < 56; i++) {
        alphabet[i] = i + 'a' - 62;  // Assigning 'ä' + i to fill alphabet from 'A' to 'Z'
    }

    alphabet[56] = (char)134;  // Second byte for UTF-8 encoding of 'Æ'
    alphabet[57] = (char)152;  // Second byte for UTF-8 encoding of 'Ø'
    alphabet[58] = (char)133;  // Second byte for UTF-8 encoding of 'Å'

    // Print the lower case alphabet
    for (int i = 0; i < 26; i++) {
        printf("%c", alphabet[i]);
    }
    printf("%c%c", alphabet[26], alphabet[27]);
    printf("%c%c", alphabet[26], alphabet[28]);
    printf("%c%c", alphabet[26], alphabet[29]);

    // Print the upper case alphabet
    for (int i = 30; i < 56; i++) {
        printf("%c", alphabet[i]);
    }
     printf("%c%c", alphabet[26], alphabet[56]);
    printf("%c%c", alphabet[26], alphabet[57]);
    printf("%c%c\n", alphabet[26], alphabet[58]);
}