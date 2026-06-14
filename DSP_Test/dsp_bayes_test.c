#include "dsp_test.h"

void dsp_bayes_test(void)
{
    printf("\r\n=== Bayes Test ===\r\n");

    /* 2-class, 2-dimension Gaussian Naive Bayes */
    float32_t theta[4] = {0.0f, 0.0f, 3.0f, 3.0f};   /* Class0: [0,0], Class1: [3,3] */
    float32_t sigma[4] = {1.0f, 1.0f, 1.0f, 1.0f};   /* Class0: [1,1], Class1: [1,1] */
    float32_t classPriors[2] = {0.5f, 0.5f};

    arm_gaussian_naive_bayes_instance_f32 S;
    S.vectorDimension = 2;
    S.numberOfClasses = 2;
    S.theta = theta;
    S.sigma = sigma;
    S.classPriors = classPriors;
    S.epsilon = 1e-4f;

    float32_t probs[2];
    float32_t bufferB[2];

    /* Predict for [1,1] */
    float32_t in1[2] = {1.0f, 1.0f};
    uint32_t cls1 = arm_gaussian_naive_bayes_predict_f32(&S, in1, probs, bufferB);
    printf("Input [1,1] -> class %u, probs: [%.4f, %.4f]\r\n", cls1, probs[0], probs[1]);

    /* Predict for [4,4] */
    float32_t in2[2] = {4.0f, 4.0f};
    uint32_t cls2 = arm_gaussian_naive_bayes_predict_f32(&S, in2, probs, bufferB);
    printf("Input [4,4] -> class %u, probs: [%.4f, %.4f]\r\n", cls2, probs[0], probs[1]);
}
