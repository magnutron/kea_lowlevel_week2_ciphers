#include <stdio.h>
#include "cipher.h"
#include <malloc.h>

char alphabet[52];

int letterToNumber(char letter) {
    for (int i = 0; i < 58; i++) {
        // Check if the current array element matches the letter
        if (alphabet[i] == letter) {
            return i;  // Return the index if a match is found
        }
    }
    return -1;  // Return -1 if the letter is not found
}

char numberToLetter(int number) {
    if (number >= 0 && number <= 52) {
        return (char)alphabet[number];
    }
    return ' ';
}

int countLength(char *text) {
    int length = 0;
    
    // Iterate through the array until the null terminator is encountered
    while (text[length] != '\0') {
        length++;
    }

    return length;
}

void encrypt(char* text, int shiftValue) {
    int textLength = countLength(text);

    // Allocate memory for storing index and encrypted text
    int* encryptedTextIndex = (int*)malloc(textLength * sizeof(int));  // Array of indexes
    char* encryptedText = (char*)malloc((textLength + 1) * sizeof(char));  // Encrypted text

    if (encryptedTextIndex == NULL || encryptedText == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Convert each letter to its number, apply shift, and store in encryptedTextIndex
    for (int i = 0; i < textLength; i++) {
        int letterIndex = letterToNumber(text[i]);
        if (letterIndex != -1) {
            encryptedTextIndex[i] = shift(letterIndex, shiftValue);  // Shift the index
        } else {
            encryptedTextIndex[i] = -1;  // Keep non-alphabet characters as -1
        }
    }

    // Convert the shifted numbers back to letters
    for (int i = 0; i < textLength; i++) {
        if (encryptedTextIndex[i] != -1) {
            encryptedText[i] = numberToLetter(encryptedTextIndex[i]);  // Convert back to letter
        } else {
            encryptedText[i] = text[i];  // Keep non-alphabet characters unchanged
        }
    }
    
    encryptedText[textLength] = '\0';  // Null-terminate the string

    printf("Encrypted text: %s\n", encryptedText);

    // Free allocated memory
    free(encryptedTextIndex);
    free(encryptedText);
}

void decrypt(char* text, int shiftValue) 
{
    int textLength = countLength(text);

    // Allocate memory for storing index and decrypted text
    int* decryptedTextIndex = (int*)malloc(textLength * sizeof(int));  // Array of indexes
    char* decryptedText = (char*)malloc((textLength + 1) * sizeof(char));  // Decrypted text

    if (decryptedTextIndex == NULL || decryptedText == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Convert each letter to its number, apply shift, and store in decryptedTextIndex
    for (int i = 0; i < textLength; i++) {
        int letterIndex = letterToNumber(text[i]);
        if (letterIndex != -1) {
            decryptedTextIndex[i] = shift(letterIndex, -shiftValue);  // Shift the index
        } else {
            decryptedTextIndex[i] = -1;  // Keep non-alphabet characters as -1
        }
    }

    // Convert the shifted numbers back to letters
    for (int i = 0; i < textLength; i++) {
        if (decryptedTextIndex[i] != -1) {
            decryptedText[i] = numberToLetter(decryptedTextIndex[i]);  // Convert back to letter
        } else {
            decryptedText[i] = text[i];  // Keep non-alphabet characters unchanged
        }
    }
    
    decryptedText[textLength] = '\0';  // Null-terminate the string

    printf("Decrypted text: %s\n", decryptedText);

    // Free allocated memory
    free(decryptedTextIndex);
    free(decryptedText);
}


int shift(int number, int shiftValue) {
    if (number >= 0 && number < 52) {
        return (number + shiftValue) % 52;  // Wrap around the alphabet with modulo
    }
    return number;  // Return as-is if it's not part of the alphabet
}

void init(char alphabet[]) {
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;
    }

    for (int i = 26; i < 52; i++) {
        alphabet[i] = '&' + i + 1;
    }

    // Print the lower case alphabet
    for (int i = 0; i < 52; i++) {
        printf("%c", alphabet[i]);
    }
    printf("\n");
}