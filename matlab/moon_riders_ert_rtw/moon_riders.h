/*
 * File: moon_riders.h
 *
 * Code generated for Simulink model 'moon_riders'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Mar 25 10:49:10 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_moon_riders_h_
#define RTW_HEADER_moon_riders_h_
#ifndef moon_riders_COMMON_INCLUDES_
#define moon_riders_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* moon_riders_COMMON_INCLUDES_ */

#include "moon_riders_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_moon_riders;    /* '<Root>/Chart' */
  uint8_T is_c3_moon_riders;           /* '<Root>/Chart' */
} DW_moon_riders_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T LEFT_BUTTON;                  /* '<Root>/LEFT_BUTTON' */
  real_T RIGHT_BUTTON;                 /* '<Root>/RIGHT_BUTTON  ' */
} ExtU_moon_riders_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T LEFT_LED;                     /* '<Root>/LEFT_LED' */
  real_T RIGHT_LED;                    /* '<Root>/RIGHT_LED' */
} ExtY_moon_riders_T;

/* Real-time Model Data Structure */
struct tag_RTM_moon_riders_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_moon_riders_T moon_riders_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_moon_riders_T moon_riders_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_moon_riders_T moon_riders_Y;

/* Model entry point functions */
extern void moon_riders_initialize(void);
extern void moon_riders_step(void);
extern void moon_riders_terminate(void);

/* Real-time Model object */
extern RT_MODEL_moon_riders_T *const moon_riders_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'moon_riders'
 * '<S1>'   : 'moon_riders/Chart'
 */
#endif                                 /* RTW_HEADER_moon_riders_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
