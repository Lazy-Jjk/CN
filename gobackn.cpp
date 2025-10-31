#include <stdio.h>

int main() {
    int n, w, i = 1, ack = 0, lost;

    printf("Enter total frames & window size: ");
    scanf("%d%d", &n, &w);

    while (ack < n) {
        printf("\nSending frames %d to %d\n",
               i, (i + w - 1 < n) ? i + w - 1 : n);

        printf("Enter last frame received correctly (0 if all OK): ");
        scanf("%d", &lost);

        if (lost == 0) {
            ack += w;
            i = ack + 1;
            printf("All %d frames received\n", w);
        } else {
            printf("Frame %d lost! Retransmitting from %d\n", lost, lost);
            ack = lost - 1;
            i = lost;
        }
    }

    printf("\nAll frames sent successfully!\n");
    return 0;
}
