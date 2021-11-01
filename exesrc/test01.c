#include <stdio.h>
#include "cmplx.h"

int main() {
    cmplx_t a = {1, 2};
    cmplx_t b = {2, 3};
    cmplx_t c;
    printf("Testing function cmplx_div(%f+%fj, %f+%fj)\n", a[0], a[1], b[0], b[1]);
    cmplx_div(a, b, c);
    printf("Output: %f+%fj\n", c[0], c[1]);
    return 0;
}