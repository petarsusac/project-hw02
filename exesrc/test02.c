#include <stdio.h>
#include "cmplx.h"

int main() {
    cmplx_t a = {1, 2};
    cmplx_t b = {2, 3};
    cmplx_t c;
    printf("Testing function cmplx_mul(%.2f+%.2fj, %.2f+%.2fj)\n", a[0], a[1], b[0], b[1]);
    cmplx_mul(a, b, c);
    printf("Output: %.2f+%.2fj\n", c[0], c[1]);
    return 0;
}