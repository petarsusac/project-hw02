#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "io.h"

int main() {
    const char filepath[] = "./file.b";
    int halfword = 1234;
    printf("Testing functions write_half(), read_half()\n");
    int fd = open(filepath, O_RDWR | O_CREAT | O_TRUNC);
    write_half(fd, halfword);
    lseek(fd, 0, SEEK_SET);
    int read = read_half(fd);
    printf("Half-word written: %d, half-word read: %d\n", halfword, read);
    close(fd);
    unlink(filepath);
    return 0;
}