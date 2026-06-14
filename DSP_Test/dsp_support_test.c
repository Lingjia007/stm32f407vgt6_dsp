#include "dsp_test.h"

void dsp_support_test(void)
{
    printf("\r\n=== Support Test ===\r\n");

    /* arm_copy_f32 */
    float32_t src_copy[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float32_t dst_copy[4];
    arm_copy_f32(src_copy, dst_copy, 4);
    print_array_f32("copy", dst_copy, 4);

    /* arm_fill_f32 */
    float32_t dst_fill[5];
    arm_fill_f32(3.14f, dst_fill, 5);
    print_array_f32("fill(3.14)", dst_fill, 5);

    /* arm_float_to_q31 */
    float32_t src_f2q[4] = {0.5f, -0.5f, 1.0f, 0.0f};
    q31_t dst_q31[4];
    arm_float_to_q31(src_f2q, dst_q31, 4);
    printf("float_to_q31: [0x%08X, 0x%08X, 0x%08X, 0x%08X]\r\n",
           (unsigned int)dst_q31[0], (unsigned int)dst_q31[1],
           (unsigned int)dst_q31[2], (unsigned int)dst_q31[3]);

    /* arm_q31_to_float */
    q31_t src_q2f[2] = {0x40000000, 0xC0000000};
    float32_t dst_f32[2];
    arm_q31_to_float(src_q2f, dst_f32, 2);
    print_array_f32("q31_to_float", dst_f32, 2);

    /* arm_sort_f32 (bubble sort) */
    float32_t src_sort[5] = {5.0f, 1.0f, 4.0f, 2.0f, 3.0f};
    float32_t dst_sort[5];
    arm_sort_instance_f32 sort_inst;
    arm_sort_init_f32(&sort_inst, ARM_SORT_BUBBLE, ARM_SORT_ASCENDING);
    arm_sort_f32(&sort_inst, src_sort, dst_sort, 5);
    print_array_f32("sort(bubble)", dst_sort, 5);
}
