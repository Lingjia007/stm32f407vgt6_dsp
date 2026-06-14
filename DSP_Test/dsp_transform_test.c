#include "dsp_test.h"

void dsp_transform_test(void)
{
    printf("\r\n=== Transform Test ===\r\n");

    float32_t fftInput[256];
    float32_t fftOutput[256];
    float32_t mag[10];

    /* Build signal: 10*sin(2*pi*5*n/256) + 5*sin(2*pi*20*n/256) */
    for (int n = 0; n < 256; n++)
    {
        fftInput[n] = 10.0f * sinf(2.0f * PI * 5.0f * n / 256.0f)
                     + 5.0f  * sinf(2.0f * PI * 20.0f * n / 256.0f);
    }

    /* Perform FFT */
    arm_rfft_fast_instance_f32 fftInstance;
    arm_rfft_fast_init_f32(&fftInstance, 256);
    arm_rfft_fast_f32(&fftInstance, fftInput, fftOutput, 0);

    /* Compute magnitude of first 10 bins (each bin = real^2 + imag^2, sqrt) */
    for (int i = 0; i < 10; i++)
    {
        float32_t real = fftOutput[2 * i];
        float32_t imag = fftOutput[2 * i + 1];
        mag[i] = sqrtf(real * real + imag * imag);
    }

    print_array_f32("FFT magnitude (bins 0-9)", mag, 10);
}
