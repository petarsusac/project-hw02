#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "io.h"

int main() {
    const char filepath[] = "./file.b";
    int word = 1234;
    printf("Testing functions write_word(), read_word()\n");
    int fd = open(filepath, O_RDWR | O_CREAT | O_TRUNC);
    write_word(fd, word);
    lseek(fd, 0, SEEK_SET);
    int read = read_word(fd);
    printf("Word written: %d, word read: %d\n", word, read);
    close(fd);
    unlink(filepath);
    return 0;
}