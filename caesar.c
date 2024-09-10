#include <stdio.h>
#include "cipher.h"
#include <windows.h>  // For Windows OS

//  gcc -o caesar caesar.c cipher.c

int main() {
    SetConsoleOutputCP(CP_UTF8);  // Set the console to UTF-8 encoding
    char inputText[256];
    int shiftValue;
    int choice;

    // Initialize the alphabet array
    init(alphabet);

    //Menu loop
    do {
        printf("Choose an option:\n");
        printf("1. Encrypt text\n");
        printf("2. Decrypt text\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Encrypt text
                printf("Enter text to encrypt: ");
                scanf("%255s", inputText);
                printf("Enter shift value: ");
                scanf("%d", &shiftValue);
                encrypt(inputText, shiftValue);
                break;

            case 2:
                // Decrypt text
                printf("Enter text to decrypt: ");
                scanf("%255s", inputText);
                printf("Enter shift value: ");
                scanf("%d", &shiftValue);
                decrypt(inputText, shiftValue);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }

        printf("\n");  // Print a new line for better readability

    } while (choice != 3);  // Continue looping until the user chooses to exit

    return 0;
}