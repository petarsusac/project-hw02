#include <math.h>
#include "cmplx.h"

#define _USE_MATH_DEFINES

// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = (a[0] * b[0] + a[1] * b[1]) / (b[0] * b[0] + b[1] * b[1]);
    c[1] = (a[1] * b[0] - a[0] * b[1]) / (b[0] * b[0] + b[1] * b[1]);
}

// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = a[0] * b[0] - a[1] * b[1];
    c[1] = a[0] * b[1] + a[1] * b[0];
}

// returns |a|
double cmplx_mag(cmplx_t a) {
    return sqrt(a[0] * a[0] + a[1] * a[1]);
}

// returns phase in radians of a 
double cmplx_phs(cmplx_t a) {
    return atan(a[1] / a[0]);
}

// returns real part of mag/_phs
double cmplx_real(double mag, double phs) {
    return mag * cos(phs);
}

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs) {
    return mag * sin(phs);
}

// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N) {
    for(int k = 0; k <= N - 1; k++) {
        output[k][0] = 0;
        output[k][1] = 0;
        for(int n = 0; n <= N - 1; n++) {
            cmplx_t res;
            cmplx_t z = {cmplx_real(1, -2 * M_PI / N * k * n), cmplx_imag(1, -2 * M_PI / N * k * n)};
            cmplx_mul(input[n], z, res);
            output[k][0] += res[0];
            output[k][1] += res[1];
        }
    }
}

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N) {
    for(int n = 0; n <= N - 1; n++) {
        output[n][0] = 0;
        output[n][1] = 0;
        for(int k = 0; k <= N - 1; k++) {
            cmplx_t res;
            cmplx_t z = {cmplx_real(1, 2 * M_PI / N * k * n), cmplx_imag(1, 2 * M_PI / N * k * n)};
            cmplx_mul(input[k], z, res);
            output[n][0] += (double) 1 / N * res[0];
            output[n][1] += (double) 1 / N * res[1];
        }
    }
}