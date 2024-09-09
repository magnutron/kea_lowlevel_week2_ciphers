#include <stdio.h>

int main() {
    // Directly print 'Æ' with its UTF-8 encoding
    unsigned char utf8_ae[] = {195, 134};  // UTF-8 encoding of 'Æ'
    printf("Direct UTF-8 Output: ");
    printf("%c%c\n", utf8_ae[0], utf8_ae[1]);

    // Print 'Æ' directly using a UTF-8 encoded string
    printf("Direct UTF-8 String: Æ\n");

     // UTF-8 encoded 'Æ'
    const char* utf8_ae2 = "\xC3\x86";  // Directly using UTF-8 byte sequence for 'Æ'

    // Print using string literal
    printf("UTF-8 Character Output: %s\n", utf8_ae2);

    return 0;

    unsigned char utf8_aehex[] = {195, 134};  // UTF-8 encoding of 'Æ'
    
    // Print hexadecimal values of bytes
    printf("Byte 1: 0x%X\n", (unsigned char)utf8_aehex[0]);
    printf("Byte 2: 0x%X\n", (unsigned char)utf8_aehex[1]);
    
    // Print the UTF-8 character
    printf("UTF-8 Character: %c%c\n", utf8_aehex[0], utf8_aehex[1]);
    //printf("Direct UTF-8 Output: Æ\n");
    printf("Check this out: ���\n");

}