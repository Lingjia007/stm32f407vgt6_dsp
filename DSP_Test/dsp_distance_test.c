#include "dsp_test.h"

void dsp_distance_test(void)
{
    printf("\r\n=== Distance Test ===\r\n");

    float32_t a[3] = {1.0f, 2.0f, 3.0f};
    float32_t b[3] = {4.0f, 5.0f, 6.0f};
    float32_t c[3] = {1.0f, 0.0f, 0.0f};
    float32_t d[3] = {0.0f, 1.0f, 0.0f};

    float32_t dist;

    dist = arm_euclidean_distance_f32(a, b, 3);
    printf("arm_euclidean_distance_f32 = %.4f\r\n", dist);

    dist = arm_cosine_distance_f32(c, d, 3);
    printf("arm_cosine_distance_f32 = %.4f\r\n", dist);

    dist = arm_cityblock_distance_f32(a, b, 3);
    printf("arm_cityblock_distance_f32 = %.4f\r\n", dist);

    dist = arm_chebyshev_distance_f32(a, b, 3);
    printf("arm_chebyshev_distance_f32 = %.4f\r\n", dist);
}
