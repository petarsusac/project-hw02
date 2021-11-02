#include <stdio.h>
#include "cmplx.h"

int main() {
    int N = 4;
    cmplx_t signal[4] = {{1, 0}, {1, 0}, {0, 0}, {0, 0}};
    cmplx_t spectrum[4];

    printf("Testing function cmplx_dft()\n");
    printf("Input signal: ");
    for(int i = 0; i < N; i++) {
        printf("%.2f+%.2fj ", signal[i][0], signal[i][1]);
    }
    printf("\n");

    cmplx_dft(signal, spectrum, N);
    
    printf("DFT transform: ");
    for(int i = 0; i < N; i++) {
        printf("%.2f+%.2fj ", spectrum[i][0], spectrum[i][1]);
    }
    printf("\n");

    return 0;
}