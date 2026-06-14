#include "dsp_test.h"

void dsp_filtering_test(void)
{
    printf("\r\n=== Filtering Test ===\r\n");

    /* FIR low-pass filter: 5 taps, blockSize = 10 */
    uint32_t numTaps = 5;
    uint32_t blockSize = 10;

    float32_t fir_coeffs[] = {0.1f, 0.2f, 0.4f, 0.2f, 0.1f};
    float32_t fir_input[]  = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    float32_t fir_output[10];
    float32_t fir_state[5 + 10 - 1]; /* numTaps + blockSize - 1 */

    arm_fir_instance_f32 fir_inst;
    arm_fir_init_f32(&fir_inst, numTaps, fir_coeffs, fir_state, blockSize);
    arm_fir_f32(&fir_inst, fir_input, fir_output, blockSize);

    print_array_f32("FIR impulse response", fir_output, blockSize);
}
