#include <stdio.h>
#include "cmplx.h"

int main() {
    cmplx_t a = {1, 2};
    printf("Testing function cmplx_phs(%.2f+%.2fj)\n", a[0], a[1]);
    printf("Output: %.2lf\n", cmplx_phs(a));
    return 0;
}