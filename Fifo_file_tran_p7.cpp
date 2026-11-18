Server:--
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main() {
    int r, w, n;
    char f[100], b[1024];
    FILE *fp;
    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);
    r = open("fifo1", O_RDONLY);
    w = open("fifo2", O_WRONLY);
    read(r, f, 100);
    printf("Requested : %s\n", f);
    fp = fopen(f, "rb");
    while ((n = fread(b, 1, 1024, fp)) > 0)
        write(w, b, n);
    printf("File Sent\n");
}
Client :----
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main() {
    int r, w, n;
    char f[100], b[1024];
    FILE *fp;
    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);
    w = open("fifo1", O_WRONLY);
    r = open("fifo2", O_RDONLY);
    printf("Enter File : ");
    scanf("%s", f);
    write(w, f, strlen(f) + 1);
    fp = fopen("received.txt", "wb");
    while ((n = read(r, b, 1024)) > 0)
        fwrite(b, 1, n, fp);
    printf("File Received\n");
}
