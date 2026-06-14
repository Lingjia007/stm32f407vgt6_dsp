#include "dsp_test.h"

void dsp_svm_test(void)
{
    printf("\r\n=== SVM Test ===\r\n");

    float32_t dualCoefficients[2] = {0.5f, -0.3f};
    float32_t supportVectors[4]  = {1.0f, 1.0f, -1.0f, -1.0f};
    int32_t   classes[2]         = {0, 1};

    arm_svm_linear_instance_f32 S;
    arm_svm_linear_init_f32(&S,
        2,                  /* nbOfSupportVectors */
        2,                  /* vectorDimension */
        0.1f,               /* intercept */
        dualCoefficients,
        supportVectors,
        classes);

    int32_t result;

    /* Predict for [0.5, 0.5] */
    float32_t in1[2] = {0.5f, 0.5f};
    arm_svm_linear_predict_f32(&S, in1, &result);
    printf("Input [0.5, 0.5] -> class %d\r\n", result);

    /* Predict for [-0.5, -0.5] */
    float32_t in2[2] = {-0.5f, -0.5f};
    arm_svm_linear_predict_f32(&S, in2, &result);
    printf("Input [-0.5, -0.5] -> class %d\r\n", result);
}
