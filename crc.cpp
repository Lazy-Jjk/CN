#include <stdio.h>
#include <string.h>

// Function to calculate CRC bits and transmitted code
void crc(char *data, char *key) {
    int dl = strlen(data);
    int kl = strlen(key);
    char temp[100], remainder[100];

    // Append (key length - 1) zeros to data
    strcpy(temp, data);
    for (int i = 0; i < kl - 1; i++)
        strcat(temp, "0");

    strcpy(remainder, temp);

    // Perform binary division (XOR)
    for (int i = 0; i < dl; i++) {
        if (remainder[i] == '1') {
            for (int j = 0; j < kl; j++) {
                remainder[i + j] = (remainder[i + j] == key[j]) ? '0' : '1';
            }
        }
    }

    printf("\nCRC bits: %s", remainder + dl);
    printf("\nTransmitted Code: %s%s\n", data, remainder + dl);
}

int main() {
    char data[50], key[50];

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter key (divisor): ");
    scanf("%s", key);

    crc(data, key);

    return 0;
}

