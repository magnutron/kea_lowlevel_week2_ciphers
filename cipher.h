#ifndef CIPHER_H
#define CIPHER_H

extern char alphabet[52];

int letterToNumber( char letter );

char numberToLetter( int number );

int shift( int number, int shiftvalue );

void init(char alphabet[]);

void encrypt( char* text, int shift );

//void decrypt( char* text, int shift );

#endif // CIPHER_H