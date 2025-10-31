#include <stdio.h>
#include <string.h>

int main() {
    char text[100], text1[100];
    int key, key1;

    // Encryption
    printf("Enter text to encrypt: ");
    scanf("%s", text);

    printf("Enter key: ");
    scanf("%d", &key);

    for (int i = 0; i < strlen(text); i++)
        text[i] = text[i] + key;

    printf("Encrypted text: %s\n", text);

    // Decryption
    printf("\nEnter text to decrypt: ");
    scanf("%s", text1);

    printf("Enter key: ");
    scanf("%d", &key1);

    for (int i = 0; i < strlen(text1); i++)
        text1[i] = text1[i] - key1;

    printf("Decrypted text: %s\n", text1);

    return 0;
}

