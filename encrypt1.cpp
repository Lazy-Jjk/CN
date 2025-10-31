#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100];
    int key;

    printf("Enter text: ");
    scanf(" %[^\n]", text); // Reads entire line including spaces

    printf("Enter key: ");
    scanf("%d", &key);

    // Encryption
    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];

        if (isupper(ch))
            text[i] = (ch - 'A' + key) % 26 + 'A';
        else if (islower(ch))
            text[i] = (ch - 'a' + key) % 26 + 'a';
        // Non-alphabetic characters remain unchanged
    }

    printf("Encrypted: %s\n", text);

    // Decryption
    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];

        if (isupper(ch))
            text[i] = (ch - 'A' - key + 26) % 26 + 'A';
        else if (islower(ch))
            text[i] = (ch - 'a' - key + 26) % 26 + 'a';
        // Non-alphabetic characters remain unchanged
    }

    printf("Decrypted: %s\n", text);

    return 0;
}

