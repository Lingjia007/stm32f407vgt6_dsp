#include "dsp_test.h"

void dsp_matrix_test(void)
{
    printf("\r\n=== Matrix Test ===\r\n");

    float32_t a_data[9] = {1,2,3, 4,5,6, 7,8,9};
    float32_t b_data[9] = {9,8,7, 6,5,4, 3,2,1};
    float32_t p_data[9] = {2,1,0, 1,3,1, 0,1,2};

    float32_t out_data[9];
    float32_t inv_data[9];
    float32_t vec_out[3];

    arm_matrix_instance_f32 A, B, P, Out, Inv;
    arm_mat_init_f32(&A, 3, 3, a_data);
    arm_mat_init_f32(&B, 3, 3, b_data);
    arm_mat_init_f32(&P, 3, 3, p_data);
    arm_mat_init_f32(&Out, 3, 3, out_data);
    arm_mat_init_f32(&Inv, 3, 3, inv_data);

    /* A + B */
    arm_mat_add_f32(&A, &B, &Out);
    print_matrix_f32("A + B", &Out);

    /* A - B */
    arm_mat_sub_f32(&A, &B, &Out);
    print_matrix_f32("A - B", &Out);

    /* A * B */
    arm_mat_mult_f32(&A, &B, &Out);
    print_matrix_f32("A * B", &Out);

    /* A^T */
    arm_mat_trans_f32(&A, &Out);
    print_matrix_f32("A^T", &Out);

    /* A * 2.0 */
    arm_mat_scale_f32(&A, 2.0f, &Out);
    print_matrix_f32("A * 2.0", &Out);

    /* inv(P) */
    arm_status status = arm_mat_inverse_f32(&P, &Inv);
    if (status == ARM_MATH_SUCCESS)
        print_matrix_f32("inv(P)", &Inv);
    else
        printf("inv(P): singular matrix\r\n");

    /* A * [1;1;1] */
    float32_t vec[3] = {1.0f, 1.0f, 1.0f};
    arm_mat_vec_mult_f32(&A, vec, vec_out);
    print_array_f32("A * [1;1;1]", vec_out, 3);
}
