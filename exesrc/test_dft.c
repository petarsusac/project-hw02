#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include "cmplx.h"
#include "io.h"

#define _USE_MATH_DEFINES

int float_u_int(float *vrijednost) {
    void *a = (void *) vrijednost;
    int vrijednost_ieee = *((int *) a);
    return vrijednost_ieee;
}

int main() {
    int N = 10;
    double t = 0;
    cmplx_t samples[N];
    const char filepath[] = "./file.a";

    printf("Testing test_dft:\n");
    printf("Uzorci signala:\n");

    for(int i = 0; i < N; i++) {
        samples[i][0] = sin(2 * M_PI * 50 * t);
        samples[i][1] = 0;
        t += 1.0 / 200.0; // 200 Hz sampling frequency

        printf("%d: %.2f + %.2fj\n", i, samples[i][0], samples[i][1]);
    }

    cmplx_t output[N];
    cmplx_dft(samples, output, N);

    printf("DFT signala:\n");
    for (int i = 0; i < N; i++) {
        printf("%d: %.2f + %.2fj\n", i, output[i][0], output[i][1]);
    }
    

    int fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    for(int i = 0; i < N; i++) {
        write_word(fd, float_u_int(&output[i][0]));
        write_word(fd, float_u_int(&output[i][1]));
    }
    close(fd);

    return 0;
}