#include <unistd.h>

int read_word(int fd) {
    int buf;
    read(fd, (void *) &buf, 4);
    return buf;
}

short read_half(int fd) {
    short buf;
    read(fd, (void *) &buf, 2);
    return buf;
}

void write_word(int fd, int word) {
    write(fd, (const void *) &word, 4);
}

void write_half(int fd, short word) {
    write(fd, (const void *) &word, 2);
}