/*
 * File: moon_riders.c
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

#include "moon_riders.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define moon_riders_IN_Hazard_Blinking ((uint8_T)1U)
#define moon_riders_IN_Idle            ((uint8_T)2U)
#define moon_riders_IN_Left_Blinking   ((uint8_T)3U)
#define moon_riders_IN_Right_Blinking  ((uint8_T)4U)

/* Block states (default storage) */
DW_moon_riders_T moon_riders_DW;

/* External inputs (root inport signals with default storage) */
ExtU_moon_riders_T moon_riders_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_moon_riders_T moon_riders_Y;

/* Real-time model */
static RT_MODEL_moon_riders_T moon_riders_M_;
RT_MODEL_moon_riders_T *const moon_riders_M = &moon_riders_M_;

/* Model step function */
void moon_riders_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/LEFT_BUTTON'
   *  Inport: '<Root>/RIGHT_BUTTON  '
   */
  if (moon_riders_DW.is_active_c3_moon_riders == 0U) {
    moon_riders_DW.is_active_c3_moon_riders = 1U;
    moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Idle;

    /* Outport: '<Root>/LEFT_LED' */
    moon_riders_Y.LEFT_LED = 0.0;

    /* Outport: '<Root>/RIGHT_LED' */
    moon_riders_Y.RIGHT_LED = 0.0;
  } else {
    switch (moon_riders_DW.is_c3_moon_riders) {
     case moon_riders_IN_Hazard_Blinking:
      /* Outport: '<Root>/LEFT_LED' */
      moon_riders_Y.LEFT_LED = 1.0;

      /* Outport: '<Root>/RIGHT_LED' */
      moon_riders_Y.RIGHT_LED = 1.0;
      if ((moon_riders_U.LEFT_BUTTON == 1.0) || (moon_riders_U.RIGHT_BUTTON ==
           1.0)) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Idle;

        /* Outport: '<Root>/LEFT_LED' */
        moon_riders_Y.LEFT_LED = 0.0;

        /* Outport: '<Root>/RIGHT_LED' */
        moon_riders_Y.RIGHT_LED = 0.0;
      }
      break;

     case moon_riders_IN_Idle:
      /* Outport: '<Root>/LEFT_LED' */
      moon_riders_Y.LEFT_LED = 0.0;

      /* Outport: '<Root>/RIGHT_LED' */
      moon_riders_Y.RIGHT_LED = 0.0;
      if ((moon_riders_U.LEFT_BUTTON == 1.0) && (moon_riders_U.RIGHT_BUTTON ==
           1.0)) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Hazard_Blinking;

        /* Outport: '<Root>/LEFT_LED' */
        moon_riders_Y.LEFT_LED = 1.0;

        /* Outport: '<Root>/RIGHT_LED' */
        moon_riders_Y.RIGHT_LED = 1.0;
      } else if (moon_riders_U.LEFT_BUTTON == 1.0) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Left_Blinking;

        /* Outport: '<Root>/LEFT_LED' */
        moon_riders_Y.LEFT_LED = 1.0;
      } else if (moon_riders_U.RIGHT_BUTTON == 1.0) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Right_Blinking;

        /* Outport: '<Root>/RIGHT_LED' */
        moon_riders_Y.RIGHT_LED = 1.0;
      }
      break;

     case moon_riders_IN_Left_Blinking:
      /* Outport: '<Root>/LEFT_LED' */
      moon_riders_Y.LEFT_LED = 1.0;

      /* Outport: '<Root>/RIGHT_LED' */
      moon_riders_Y.RIGHT_LED = 0.0;
      if (moon_riders_U.RIGHT_BUTTON == 1.0) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Right_Blinking;

        /* Outport: '<Root>/LEFT_LED' */
        moon_riders_Y.LEFT_LED = 0.0;

        /* Outport: '<Root>/RIGHT_LED' */
        moon_riders_Y.RIGHT_LED = 1.0;
      } else if (moon_riders_U.LEFT_BUTTON == 1.0) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Idle;

        /* Outport: '<Root>/LEFT_LED' */
        moon_riders_Y.LEFT_LED = 0.0;
      }
      break;

     default:
      /* Outport: '<Root>/LEFT_LED' */
      /* case IN_Right_Blinking: */
      moon_riders_Y.LEFT_LED = 0.0;

      /* Outport: '<Root>/RIGHT_LED' */
      moon_riders_Y.RIGHT_LED = 1.0;
      if (moon_riders_U.LEFT_BUTTON == 1.0) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Left_Blinking;

        /* Outport: '<Root>/LEFT_LED' */
        moon_riders_Y.LEFT_LED = 1.0;

        /* Outport: '<Root>/RIGHT_LED' */
        moon_riders_Y.RIGHT_LED = 0.0;
      } else if (moon_riders_U.RIGHT_BUTTON == 1.0) {
        moon_riders_DW.is_c3_moon_riders = moon_riders_IN_Idle;

        /* Outport: '<Root>/RIGHT_LED' */
        moon_riders_Y.RIGHT_LED = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void moon_riders_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void moon_riders_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
