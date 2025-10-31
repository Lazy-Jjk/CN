#include <stdio.h>

int main() {
    int cap, rate, n, i, p[10];

    printf("Enter bucket capacity, output rate, no. of packets: ");
    scanf("%d%d%d", &cap, &rate, &n);

    printf("Enter packet sizes:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    int rem = 0;

    for (i = 0; i < n; i++) {
        int tot = rem + p[i];

        if (tot > cap) {
            printf("Packet %d dropped\n", i + 1);
            rem = cap;
        } else {
            rem = tot;
        }

        printf("Sent %d, Remaining %d\n",
               (rem > rate) ? rate : rem,
               (rem > rate) ? rem - rate : 0);

        rem = (rem > rate) ? rem - rate : 0;
    }

    return 0;
}
