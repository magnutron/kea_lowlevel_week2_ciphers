#ifndef CIPHER_H
#define CIPHER_H

extern char alphabet[59];

int letterToNumber( char letter );

char numberToLetter( int number );

void textToNumbers(const char* text);

int shift( int number, int shiftvalue );

void init(char alphabet[]);

void encrypt( char* text, int shift );

void decrypt( char* text, int shift );

#endif // CIPHER_H