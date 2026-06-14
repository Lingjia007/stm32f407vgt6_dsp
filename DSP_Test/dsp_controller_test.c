#include "dsp_test.h"

void dsp_controller_test(void)
{
    printf("\r\n=== Controller Test ===\r\n");

    /* arm_pid_init_f32 / arm_pid_reset_f32 */
    arm_pid_instance_f32 pid;
    pid.Kp = 1.0f;
    pid.Ki = 0.5f;
    pid.Kd = 0.1f;

    arm_pid_init_f32(&pid, 1);
    float32_t error = 2.0f;
    float32_t output = arm_pid_f32(&pid, error);
    printf("PID output (Kp=1.0, Ki=0.5, Kd=0.1, error=2.0): %.4f\r\n", output);

    arm_pid_reset_f32(&pid);
    printf("PID reset done\r\n");

    /* arm_sin_cos_f32 */
    float32_t sin_val, cos_val;
    arm_sin_cos_f32(0.7853981634f, &sin_val, &cos_val);
    printf("sin_cos(pi/4): sin=%.4f, cos=%.4f\r\n", sin_val, cos_val);
}
