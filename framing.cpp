#include <stdio.h>
#include <string.h>

// Function for Character Count framing
void charCount(char *data) {
    int len = strlen(data);
    printf("\n[1] Character Count Frame: %d%s\n", len, data);
}

// Function for Character Stuffing
void charStuffing(char *data) {
    char FLAG = '$', ESC = '/';
    printf("[2] Character Stuffing Frame: %c ", FLAG);

    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == FLAG || data[i] == ESC)
            printf("%c ", ESC);  // Escape the flag or escape character

        printf("%c ", data[i]);
    }

    printf("%c\n", FLAG);
}

// Function for Bit Stuffing
void bitStuffing(char *data) {
    printf("[3] Bit Stuffed Frame: 01111110 ");
    int count = 0;

    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '1')
            count++;
        else
            count = 0;

        printf("%c", data[i]);

        // After five consecutive 1's, stuff a 0
        if (count == 5) {
            printf("0");
            count = 0;
        }
    }

    printf(" 01111110\n");
}

int main() {
    char data[100], bits[200];

    printf("Enter data for Character Count and Stuffing: ");
    scanf("%s", data);

    printf("Enter bit stream for Bit Stuffing: ");
    scanf("%s", bits);

    charCount(data);
    charStuffing(data);
    bitStuffing(bits);

    return 0;
}

