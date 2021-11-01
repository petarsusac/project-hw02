#include <stdio.h>
#include "cmplx.h"

int main() {
    double mag = 5;
    double phs = 3.14 / 4;
    printf("Testing function cmplx_real(%lf/_%f)\n", mag, phs);
    printf("Output: %lf\n", cmplx_real(mag, phs));
    return 0;
}