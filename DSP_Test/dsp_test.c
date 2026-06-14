#include "dsp_test.h"

void print_array_f32(const char *name, const float32_t *pData, uint32_t len)
{
    printf("%s: [", name);
    for (uint32_t i = 0; i < len; i++)
    {
        printf("%.4f", pData[i]);
        if (i < len - 1) printf(", ");
    }
    printf("]\r\n");
}

void print_matrix_f32(const char *name, const arm_matrix_instance_f32 *pMat)
{
    uint16_t rows = pMat->numRows;
    uint16_t cols = pMat->numCols;
    float32_t *pData = pMat->pData;

    printf("\r\n--- %s (%dx%d) ---\r\n", name, rows, cols);
    for (uint16_t i = 0; i < rows; i++)
    {
        for (uint16_t j = 0; j < cols; j++)
        {
            printf("%10.4f", pData[i * cols + j]);
            if (j < cols - 1) printf(", ");
        }
        printf("\r\n");
    }
}

void dsp_test_all(void)
{
    printf("\r\n========================================\r\n");
    printf("    CMSIS-DSP Full Module Test\r\n");
    printf("========================================\r\n");

    dsp_basic_math_test();
    dsp_complex_math_test();
    dsp_controller_test();
    dsp_fast_math_test();
    dsp_filtering_test();
    dsp_matrix_test();
    dsp_statistics_test();
    dsp_support_test();
    dsp_transform_test();
    dsp_bayes_test();
    dsp_distance_test();
    dsp_interpolation_test();
    dsp_quaternion_test();
    dsp_svm_test();

    printf("\r\n========================================\r\n");
    printf("    All DSP Tests Complete!\r\n");
    printf("========================================\r\n\r\n");
}
