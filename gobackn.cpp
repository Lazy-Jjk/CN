#include <stdio.h>

int main() {
    int n, w;

    // Input: number of frames and window size
    printf("Enter no. of frames & window size: ");
    scanf("%d%d", &n, &w);

    // Loop to send frames
    for (int i = 1; i <= n; i++) {
        printf("Frame %d sent\n", i);

        // When the window is full or last frame is sent
        if (i % w == 0 || i == n) {
            int x;
            printf("Enter (-1) if all ACKs received, or enter lost frame number: ");
            scanf("%d", &x);

            if (x == -1) {
                printf("ACK for frames up to %d received\n", i);
            } else {
                printf("Retransmitting from frame %d...\n", x);
                i = x - 1;  // resend from the lost frame
            }
        }
    }

    return 0;
}

