#include <stdio.h>
#include "cmplx.h"

int main() {
    double mag = 5;
    double phs = 3.14 / 4;
    printf("Testing function cmplx_real(%.2lf/_%.2lf)\n", mag, phs);
    printf("Output: %.2lf\n", cmplx_real(mag, phs));
    return 0;
}