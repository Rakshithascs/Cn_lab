Server:----
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main() {
    int r, w, n;
    char f[100], b[1024];
    FILE *fp;
    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);
    printf("Waiting for client...\n");
    r = open("fifo1", O_RDONLY);
    read(r, f, 100);
    printf("Requested: %s\n", f);
    fp = fopen(f, "rb");
    w = open("fifo2", O_WRONLY);
    while ((n = fread(b, 1, 1024, fp)) > 0)
        write(w, b, n);
    printf("File Sent\n");
}

Client:---
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
int main() {
    int w, r, n;
    char f[100], b[1024];
    FILE *fp;
    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);
    printf("Enter filename: ");
    scanf("%s", f);
    w = open("fifo1", O_WRONLY);
    write(w, f, strlen(f) + 1);
    r = open("fifo2", O_RDONLY);
    fp = fopen("received.txt", "wb");
    while ((n = read(r, b, 1024)) > 0)
        fwrite(b, 1, n, fp);
    printf("File Received\n");
}
