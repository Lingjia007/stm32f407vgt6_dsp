#include "dsp_test.h"

void dsp_complex_math_test(void)
{
    printf("\r\n=== Complex Math Test ===\r\n");

    float32_t dst[8];
    float32_t real_result, imag_result;

    /* arm_cmplx_mag_f32: [1+0j, 0+1j, 3+4j] */
    float32_t cmplx_in[6] = {1.0f, 0.0f, 0.0f, 1.0f, 3.0f, 4.0f};
    float32_t mag[3];
    arm_cmplx_mag_f32(cmplx_in, mag, 3);
    print_array_f32("cmplx_mag([1+0j,0+1j,3+4j])", mag, 3);

    /* arm_cmplx_conj_f32: [1+2j, 3+4j] */
    float32_t conj_in[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    arm_cmplx_conj_f32(conj_in, dst, 2);
    print_array_f32("cmplx_conj([1+2j,3+4j])", dst, 4);

    /* arm_cmplx_mult_cmplx_f32: (1+2j)*(3+4j) */
    float32_t mult_a[2] = {1.0f, 2.0f};
    float32_t mult_b[2] = {3.0f, 4.0f};
    float32_t mult_dst[2];
    arm_cmplx_mult_cmplx_f32(mult_a, mult_b, mult_dst, 1);
    print_array_f32("cmplx_mult((1+2j)*(3+4j))", mult_dst, 2);

    /* arm_cmplx_dot_prod_f32: [1+2j,3+4j] dot [5+6j,7+8j] */
    float32_t dot_a[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float32_t dot_b[4] = {5.0f, 6.0f, 7.0f, 8.0f};
    arm_cmplx_dot_prod_f32(dot_a, dot_b, 2, &real_result, &imag_result);
    printf("cmplx_dot_prod: real=%.4f, imag=%.4f\r\n", real_result, imag_result);
}
