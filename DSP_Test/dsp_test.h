#ifndef __DSP_TEST_H
#define __DSP_TEST_H

#include "arm_math.h"
#include <stdio.h>

/* 通用打印函数 */
void print_array_f32(const char *name, const float32_t *pData, uint32_t len);
void print_matrix_f32(const char *name, const arm_matrix_instance_f32 *pMat);

/* 各模块测试函数 */
void dsp_basic_math_test(void);
void dsp_complex_math_test(void);
void dsp_controller_test(void);
void dsp_fast_math_test(void);
void dsp_filtering_test(void);
void dsp_matrix_test(void);
void dsp_statistics_test(void);
void dsp_support_test(void);
void dsp_transform_test(void);
void dsp_bayes_test(void);
void dsp_distance_test(void);
void dsp_interpolation_test(void);
void dsp_quaternion_test(void);
void dsp_svm_test(void);

/* 总测试入口 */
void dsp_test_all(void);

#endif /* __DSP_TEST_H */
