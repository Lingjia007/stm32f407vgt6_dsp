#include "dsp_test.h"

void dsp_quaternion_test(void)
{
    printf("\r\n=== Quaternion Test ===\r\n");

    float32_t q[4], out[4];

    /* Normalize [1,1,1,1] */
    float32_t qIn1[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    arm_quaternion_normalize_f32(qIn1, out, 1);
    print_array_f32("Normalize [1,1,1,1]", out, 4);

    /* Conjugate of [1,2,3,4] */
    float32_t qIn2[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    arm_quaternion_conjugate_f32(qIn2, out, 1);
    print_array_f32("Conjugate [1,2,3,4]", out, 4);

    /* Norm of [1,2,3,4] */
    float32_t norm;
    arm_quaternion_norm_f32(qIn2, &norm, 1);
    printf("Norm [1,2,3,4] = %.4f\r\n", norm);

    /* Product of [1,0,0,0] (identity) and [0,1,0,0] */
    float32_t qa[4] = {1.0f, 0.0f, 0.0f, 0.0f};
    float32_t qb[4] = {0.0f, 1.0f, 0.0f, 0.0f};
    arm_quaternion_product_f32(qa, qb, out, 1);
    print_array_f32("Product [1,0,0,0]*[0,1,0,0]", out, 4);
}
