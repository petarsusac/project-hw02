#include <stdio.h>
#include "cmplx.h"

int main() {
    int N = 4;
    cmplx_t spectrum[4] = {{2, 0}, {1, -1}, {0, 0}, {1, 1}};
    cmplx_t signal[4];

    printf("Testing function cmplx_idft()\n");
    printf("DFT transform: ");
    for(int i = 0; i < N; i++) {
        printf("%.2f+%.2fj ", spectrum[i][0], spectrum[i][1]);
    }
    printf("\n");

    cmplx_idft(spectrum, signal, N);
    
    printf("Signal: ");
    for(int i = 0; i < N; i++) {
        printf("%.2f+%.2fj ", signal[i][0], signal[i][1]);
    }
    printf("\n");

    return 0;
}