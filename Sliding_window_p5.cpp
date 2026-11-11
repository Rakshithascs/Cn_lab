#include <stdio.h>
int main() {
    int n, w, i, ack;
    printf("Enter total frames: ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d", &w);
    for (i = 1; i <= n; i++) {
        printf("Frame %d Sent\n", i);
        if (i % w == 0 || i == n) {
            printf("Waiting for ACK...\n");
            printf("Enter ACK for frame %d: ", i);
            scanf("%d", &ack);
            if (ack == i)
                printf("ACK %d Received, Window Slides\n\n", ack);
            else {
                printf("ACK %d Lost, Resending from %d\n\n", ack, ack + 1);
                i = ack;
            }
        }
    }
    printf("All Frames Sent Successfully\n");
    return 0;
}
