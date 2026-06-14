#include "dsp_test.h"

void dsp_fast_math_test(void)
{
    printf("\r\n=== Fast Math Test ===\r\n");

    /* sin / cos */
    const float32_t angles[] = {0.0f, 0.5236f, 0.7854f, 1.0472f, 1.5708f};
    const char *angle_names[] = {"0", "pi/6", "pi/4", "pi/3", "pi/2"};
    for (int i = 0; i < 5; i++)
    {
        printf("sin(%s) = %.4f, cos(%s) = %.4f\r\n",
               angle_names[i], arm_sin_f32(angles[i]),
               angle_names[i], arm_cos_f32(angles[i]));
    }

    /* arm_sqrt_q15: input 16384 (0.5 in q15), result ~0.707 in q15 */
    q15_t sqrt_in = 16384;
    q15_t sqrt_out;
    arm_sqrt_q15(sqrt_in, &sqrt_out);
    printf("arm_sqrt_q15(16384) = %d (~%.4f in q15)\r\n", sqrt_out, (float)sqrt_out / 32768.0f);

    /* arm_vlog_f32 */
    float32_t log_in[] = {1.0f, 2.718f, 7.389f};
    float32_t log_out[3];
    arm_vlog_f32(log_in, log_out, 3);
    print_array_f32("vlog([1, 2.718, 7.389])", log_out, 3);

    /* arm_vexp_f32 */
    float32_t exp_in[] = {0.0f, 1.0f, 2.0f};
    float32_t exp_out[3];
    arm_vexp_f32(exp_in, exp_out, 3);
    print_array_f32("vexp([0, 1, 2])", exp_out, 3);
}
