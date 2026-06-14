#include "dsp_test.h"

void dsp_basic_math_test(void)
{
    printf("\r\n=== Basic Math Test ===\r\n");

    float32_t a[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float32_t b[4] = {5.0f, 6.0f, 7.0f, 8.0f};
    float32_t dst[4];
    float32_t result;

    /* arm_add_f32 */
    arm_add_f32(a, b, dst, 4);
    print_array_f32("add([1,2,3,4]+[5,6,7,8])", dst, 4);

    /* arm_sub_f32 */
    arm_sub_f32(b, a, dst, 4);
    print_array_f32("sub([5,6,7,8]-[1,2,3,4])", dst, 4);

    /* arm_mult_f32 */
    arm_mult_f32(a, b, dst, 4);
    print_array_f32("mult([1,2,3,4]*[5,6,7,8])", dst, 4);

    /* arm_abs_f32 */
    float32_t c[4] = {-1.5f, -2.5f, 3.0f, -4.0f};
    arm_abs_f32(c, dst, 4);
    print_array_f32("abs([-1.5,-2.5,3.0,-4.0])", dst, 4);

    /* arm_scale_f32 */
    arm_scale_f32(a, 2.0f, dst, 4);
    print_array_f32("scale([1,2,3,4]*2.0)", dst, 4);

    /* arm_dot_prod_f32 */
    arm_dot_prod_f32(a, b, 4, &result);
    printf("dot([1,2,3,4],[5,6,7,8]): %.4f\r\n", result);

    /* arm_negate_f32 */
    float32_t d[4] = {1.0f, -2.0f, 3.0f, -4.0f};
    arm_negate_f32(d, dst, 4);
    print_array_f32("negate([1,-2,3,-4])", dst, 4);

    /* arm_offset_f32 */
    arm_offset_f32(a, 5.0f, dst, 4);
    print_array_f32("offset([1,2,3,4]+5.0)", dst, 4);
}
