/*
 * scara_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "scara".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Nov 25 10:18:38 2021
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "scara.h"
#include "scara_private.h"

/* Block parameters (auto storage) */
P_scara_T scara_P = {
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S25>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S24>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S17>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Gain7'
                                        */
  -0.3,                                /* Expression: -0.3
                                        * Referenced by: '<S2>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S18>/Saturation'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S2>/Gain6'
                                        */
  -0.3,                                /* Expression: -0.3
                                        * Referenced by: '<S2>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch5'
                                        */
  100.0,                               /* Expression: const
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  120.0,                               /* Expression: const
                                        * Referenced by: '<S22>/Constant'
                                        */
  1140.0,                              /* Expression: const
                                        * Referenced by: '<S23>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch8'
                                        */
  -0.005625,                           /* Expression: (-2*180)/(500*128)
                                        * Referenced by: '<S2>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S16>/Switch'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S2>/Gain1'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -0.005625,                           /* Expression: (-2*180)/(500*128)
                                        * Referenced by: '<S2>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S15>/Switch'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S2>/Gain3'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  0.05,                                /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S2>/Rate Limiter'
                                        */
  -0.05,                               /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S2>/Rate Limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Rate Limiter'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S2>/Gain4'
                                        */
  0.05,                                /* Computed Parameter: RateLimiter1_RisingLim
                                        * Referenced by: '<S2>/Rate Limiter1'
                                        */
  -0.05,                               /* Computed Parameter: RateLimiter1_FallingLim
                                        * Referenced by: '<S2>/Rate Limiter1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Rate Limiter1'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S2>/Gain5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Data Store Memory9'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_m
                                        * Referenced by: '<S32>/Memory'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S32>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Computed Parameter: Memory_X0_e
                                        * Referenced by: '<S28>/Memory'
                                        */

  /*  Computed Parameter: Logic_table_o
   * Referenced by: '<S28>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S29>/Constant'
                                        */
  0,                                   /* Computed Parameter: DelayInput1_InitialCondition
                                        * Referenced by: '<S27>/Delay Input1'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_m3
                                        * Referenced by: '<S33>/Constant'
                                        */
  0                                    /* Computed Parameter: DelayInput1_InitialCondition_j
                                        * Referenced by: '<S31>/Delay Input1'
                                        */
};
