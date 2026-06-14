#include "dsp_test.h"

void dsp_interpolation_test(void)
{
    printf("\r\n=== Interpolation Test ===\r\n");

    /* Linear interpolation */
    float32_t yData[11] = {0.0f, 10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f, 90.0f, 100.0f};

    arm_linear_interp_instance_f32 linInst;
    linInst.nValues  = 11;
    linInst.x1       = 0.0f;
    linInst.xSpacing = 1.0f;
    linInst.pYData   = yData;

    float32_t y1 = arm_linear_interp_f32(&linInst, 2.5f);
    float32_t y2 = arm_linear_interp_f32(&linInst, 5.5f);
    printf("Linear interp at x=2.5 = %.4f\r\n", y1);
    printf("Linear interp at x=5.5 = %.4f\r\n", y2);

    /* Bilinear interpolation */
    float32_t pData[9] = {0.0f, 1.0f, 2.0f,
                          3.0f, 4.0f, 5.0f,
                          6.0f, 7.0f, 8.0f};

    arm_bilinear_interp_instance_f32 bilinInst;
    bilinInst.numRows = 3;
    bilinInst.numCols = 3;
    bilinInst.pData   = pData;

    float32_t z = arm_bilinear_interp_f32(&bilinInst, 0.5f, 0.5f);
    printf("Bilinear interp at (0.5,0.5) = %.4f\r\n", z);
}
