#include <stdio.h>
#include "cmplx.h"

int main() {
    cmplx_t a = {1, 2};
    printf("Testing function cmplx_mag(%f+%fj)\n", a[0], a[1]);
    printf("Output: %lf\n", cmplx_mag(a));
    return 0;
}