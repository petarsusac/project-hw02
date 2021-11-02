#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include "cmplx.h"
#include "io.h"

#define _USE_MATH_DEFINES

float int_u_float(int *vrijednost_ieee) {
    void *a = (void *) vrijednost_ieee;
    float vrijednost = *((float *) a);
    return vrijednost;
}

int main() {
    int N = 10;
    cmplx_t input[N];
    const char filepath[] = "./file.a";

    printf("Testing test_idft:\n");
    printf("DFT signala:\n");

    int fd = open(filepath, O_RDONLY);
    for(int i = 0; i < N; i++) {
        int procitani;
        procitani = read_word(fd);
        input[i][0] = int_u_float(&procitani);
        procitani = read_word(fd);
        input[i][1] = int_u_float(&procitani);
        printf("%d: %.2f + %.2fj\n", i, input[i][0], input[i][1]);
    }
    close(fd);

    cmplx_t output[N];
    cmplx_idft(input, output, N);

    printf("Uzorci signala:\n");
    for(int i = 0; i < N; i++) {
        printf("%d: %.2f + %.2fj\n", i, output[i][0], output[i][1]);
    }

    unlink(filepath);

    return 0;
}