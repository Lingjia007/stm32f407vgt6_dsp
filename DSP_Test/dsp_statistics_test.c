#include "dsp_test.h"

void dsp_statistics_test(void)
{
    printf("\r\n=== Statistics Test ===\r\n");

    float32_t data1[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    float32_t data2[] = {1.0f, 5.0f, 3.0f, 2.0f, 4.0f};
    uint32_t len = 5;
    float32_t result;
    uint32_t index;

    arm_mean_f32(data1, len, &result);
    printf("mean = %.4f\r\n", result);

    arm_var_f32(data1, len, &result);
    printf("var = %.4f\r\n", result);

    arm_std_f32(data1, len, &result);
    printf("std = %.4f\r\n", result);

    arm_max_f32(data2, len, &result, &index);
    printf("max = %.4f (index %lu)\r\n", result, (unsigned long)index);

    arm_min_f32(data2, len, &result, &index);
    printf("min = %.4f (index %lu)\r\n", result, (unsigned long)index);

    arm_power_f32(data1, len, &result);
    printf("power = %.4f\r\n", result);

    arm_rms_f32(data1, len, &result);
    printf("rms = %.4f\r\n", result);
}
