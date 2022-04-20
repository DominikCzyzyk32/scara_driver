/*
 * scara.c
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

#include "scara_trc_ptr.h"
#include "scara.h"
#include "scara_private.h"

/* Block signals (auto storage) */
B_scara_T scara_B;

/* Block states (auto storage) */
DW_scara_T scara_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_scara_T scara_PrevZCX;

/* Real-time model */
RT_MODEL_scara_T scara_M_;
RT_MODEL_scara_T *const scara_M = &scara_M_;
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
static void scara_output(void)
{
  int32_T rowIdx;
  boolean_T zcEvent;
  real_T u0;
  real_T u1;
  real_T u2;

  /* DataStoreRead: '<S2>/Data Store Read2' */
  scara_B.DataStoreRead2 = scara_DW.Przycisk_bazowanie;

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  scara_B.DataTypeConversion = (scara_B.DataStoreRead2 != 0.0);

  /* S-Function (rti_commonblock): '<S30>/S-Function' */
  /* This comment workarounds a code generation problem */

  /* DataTypeConversion: '<S21>/Data Type Conversion1' */
  scara_B.DataTypeConversion1 = scara_B.SFunction;

  /* Logic: '<S21>/Logical Operator' */
  scara_B.LogicalOperator = !scara_B.DataTypeConversion1;

  /* Memory: '<S32>/Memory' */
  scara_B.Memory_e = scara_DW.Memory_PreviousInput_dm;

  /* CombinatorialLogic: '<S32>/Logic' */
  zcEvent = scara_B.DataTypeConversion;
  rowIdx = zcEvent;
  zcEvent = scara_B.LogicalOperator;
  rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + zcEvent);
  zcEvent = scara_B.Memory_e;
  rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + zcEvent);
  scara_B.Logic[0U] = scara_P.Logic_table[(uint32_T)rowIdx];
  scara_B.Logic[1U] = scara_P.Logic_table[rowIdx + 8U];

  /* Logic: '<S20>/Logical Operator' */
  scara_B.LogicalOperator_m = !scara_B.Logic[0];

  /* DataStoreRead: '<S2>/Data Store Read3' */
  scara_B.DataStoreRead3 = scara_DW.Przycisk_bazowanie;

  /* DataTypeConversion: '<S20>/Data Type Conversion' */
  scara_B.DataTypeConversion_g = (scara_B.DataStoreRead3 != 0.0);

  /* S-Function (rti_commonblock): '<S26>/S-Function' */
  /* This comment workarounds a code generation problem */

  /* DataTypeConversion: '<S20>/Data Type Conversion1' */
  scara_B.DataTypeConversion1_b = scara_B.SFunction_p;

  /* Logic: '<S20>/Logical Operator2' */
  scara_B.LogicalOperator2 = !scara_B.DataTypeConversion1_b;

  /* Memory: '<S28>/Memory' */
  scara_B.Memory_a = scara_DW.Memory_PreviousInput_b;

  /* CombinatorialLogic: '<S28>/Logic' */
  zcEvent = scara_B.DataTypeConversion_g;
  rowIdx = zcEvent;
  zcEvent = scara_B.LogicalOperator2;
  rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + zcEvent);
  zcEvent = scara_B.Memory_a;
  rowIdx = (int32_T)(((uint32_T)rowIdx << 1) + zcEvent);
  scara_B.Logic_b[0U] = scara_P.Logic_table_o[(uint32_T)rowIdx];
  scara_B.Logic_b[1U] = scara_P.Logic_table_o[rowIdx + 8U];

  /* Logic: '<S20>/Logical Operator1' */
  scara_B.LogicalOperator1 = (scara_B.LogicalOperator_m && scara_B.Logic_b[0]);

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  scara_B.Compare = ((int32_T)scara_B.LogicalOperator1 <= (int32_T)
                     scara_P.Constant_Value_f);

  /* UnitDelay: '<S27>/Delay Input1' */
  scara_B.Uk1 = scara_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S27>/FixPt Relational Operator' */
  scara_B.FixPtRelationalOperator = ((int32_T)scara_B.Compare > (int32_T)
    scara_B.Uk1);

  /* DataTypeConversion: '<S20>/Data Type Conversion2' */
  scara_B.DataTypeConversion2 = scara_B.FixPtRelationalOperator;

  /* Switch: '<S2>/Switch2' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  if (scara_B.DataTypeConversion2 > scara_P.Switch2_Threshold) {
    scara_B.Switch2 = scara_P.Constant2_Value;
  } else {
    /* DataStoreRead: '<S2>/Data Store Read4' */
    scara_B.DataStoreRead4 = scara_DW.wyzw_dol;
    scara_B.Switch2 = scara_B.DataStoreRead4;
  }

  /* End of Switch: '<S2>/Switch2' */

  /* DataStoreWrite: '<S2>/Data Store Write' */
  scara_DW.wyzw_dol = scara_B.Switch2;

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   */
  scara_B.Compare_n = ((int32_T)scara_B.Logic[0] <= (int32_T)
                       scara_P.Constant_Value_m3);

  /* UnitDelay: '<S31>/Delay Input1' */
  scara_B.Uk1_i = scara_DW.DelayInput1_DSTATE_l;

  /* RelationalOperator: '<S31>/FixPt Relational Operator' */
  scara_B.FixPtRelationalOperator_p = ((int32_T)scara_B.Compare_n > (int32_T)
    scara_B.Uk1_i);

  /* DataTypeConversion: '<S21>/Data Type Conversion2' */
  scara_B.DataTypeConversion2_j = scara_B.FixPtRelationalOperator_p;

  /* Switch: '<S2>/Switch5' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  if (scara_B.DataTypeConversion2_j > scara_P.Switch5_Threshold) {
    scara_B.Switch5 = scara_P.Constant4_Value;
  } else {
    /* DataStoreRead: '<S2>/Data Store Read5' */
    scara_B.DataStoreRead5 = scara_DW.wyzw_gora;
    scara_B.Switch5 = scara_B.DataStoreRead5;
  }

  /* End of Switch: '<S2>/Switch5' */

  /* DataStoreWrite: '<S2>/Data Store Write1' */
  scara_DW.wyzw_gora = scara_B.Switch5;

  /* DataStoreRead: '<S2>/Data Store Read8' */
  scara_B.DataStoreRead8 = scara_DW.predkosc;

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  scara_B.Compare_d = (scara_B.DataStoreRead8 <= scara_P.Constant_Value_h);

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   */
  scara_B.Compare_o = (scara_B.DataStoreRead8 >= scara_P.Constant_Value_m);

  /* Logic: '<S2>/Logical Operator' */
  scara_B.LogicalOperator_d = (scara_B.Compare_d && scara_B.Compare_o);

  /* Memory: '<S2>/Memory' */
  scara_B.Memory = scara_DW.Memory_PreviousInput;

  /* Switch: '<S2>/Switch3' */
  if (scara_B.LogicalOperator_d) {
    scara_B.Switch3 = scara_B.DataStoreRead8;
  } else {
    scara_B.Switch3 = scara_B.Memory;
  }

  /* End of Switch: '<S2>/Switch3' */

  /* DataStoreWrite: '<S2>/Data Store Write2' */
  scara_DW.predkosc = scara_B.Switch3;

  /* Fcn: '<S19>/Fcn' */
  u2 = 0.0;
  u1 = rt_powd_snf(u2, 2.0);
  u2 = 0.0;
  u2 = rt_powd_snf(u2, 2.0);
  u1 += u2;
  if (u1 < 0.0) {
    u1 = -sqrt(-u1);
  } else {
    u1 = sqrt(u1);
  }

  scara_B.Fcn = u1;

  /* End of Fcn: '<S19>/Fcn' */

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   */
  scara_B.Compare_b = (scara_B.Fcn > scara_P.Constant_Value_e);

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   */
  scara_B.Compare_j = (scara_B.Fcn < scara_P.Constant_Value_c);

  /* Logic: '<S19>/Logical Operator' */
  scara_B.LogicalOperator_g = (scara_B.Compare_b && scara_B.Compare_j);

  /* Memory: '<S19>/Memory1' */
  scara_B.Memory1 = scara_DW.Memory1_PreviousInput;

  /* Switch: '<S19>/Switch' */
  if (scara_B.LogicalOperator_g) {
    scara_B.x = 0.0;
  } else {
    scara_B.x = scara_B.Memory1;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Memory: '<S19>/Memory' */
  scara_B.Memory_i = scara_DW.Memory_PreviousInput_g;

  /* Switch: '<S19>/Switch1' */
  if (scara_B.LogicalOperator_g) {
    scara_B.y = 0.0;
  } else {
    scara_B.y = scara_B.Memory_i;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Fcn: '<S19>/cos gamma2 ' */
  u0 = scara_B.x;
  u2 = rt_powd_snf(u0, 2.0);
  u0 = scara_B.y;
  u0 = rt_powd_snf(u0, 2.0);
  scara_B.cosgamma2 = ((657000.0 - u2) - u0) / 642600.0;

  /* Fcn: '<S19>/gamma2 ' */
  u2 = scara_B.cosgamma2;
  u1 = rt_powd_snf(u2, 2.0);
  u1 = 1.0 - u1;
  if (u1 < 0.0) {
    u1 = -sqrt(-u1);
  } else {
    u1 = sqrt(u1);
  }

  scara_B.gamma2 = rt_atan2d_snf(u1, scara_B.cosgamma2);

  /* End of Fcn: '<S19>/gamma2 ' */

  /* DataStoreRead: '<S2>/Data Store Read17' */
  scara_B.DataStoreRead17 = scara_DW.wsp_kart;

  /* Switch: '<S2>/Switch9' */
  if (scara_B.DataStoreRead17 > scara_P.Switch9_Threshold) {
    /* Fcn: '<S19>/gamma1' */
    scara_B.gamma1 = rt_atan2d_snf(scara_B.y, scara_B.x) - rt_atan2d_snf(510.0 *
      sin(scara_B.gamma2), 630.0 - 510.0 * cos(scara_B.gamma2));

    /* Gain: '<S25>/Gain' */
    scara_B.Gain_j = scara_P.Gain_Gain * scara_B.gamma1;
    scara_B.Switch9 = scara_B.Gain_j;
  } else {
    /* DataStoreRead: '<S2>/Data Store Read14' */
    scara_B.DataStoreRead14 = scara_DW.wyzw_gora;
    scara_B.Switch9 = scara_B.DataStoreRead14;
  }

  /* End of Switch: '<S2>/Switch9' */

  /* DataStoreRead: '<S2>/Data Store Read11' */
  scara_B.DataStoreRead11 = scara_DW.wyzwol;

  /* DataStoreRead: '<S2>/Data Store Read12' */
  scara_B.DataStoreRead12 = scara_DW.wlacz_wyzwolenie;

  /* Switch: '<S2>/Switch7' */
  if (scara_B.DataStoreRead12 > scara_P.Switch7_Threshold) {
    /* Switch: '<S2>/Switch4' */
    if (scara_B.DataStoreRead11 > scara_P.Switch4_Threshold) {
      scara_B.Switch4 = scara_B.Switch9;
    } else {
      /* DataStoreRead: '<S2>/Data Store Read9' */
      scara_B.DataStoreRead9 = scara_DW.Poz_gora;
      scara_B.Switch4 = scara_B.DataStoreRead9;
    }

    /* End of Switch: '<S2>/Switch4' */
    scara_B.Switch7 = scara_B.Switch4;
  } else {
    scara_B.Switch7 = scara_B.Switch9;
  }

  /* End of Switch: '<S2>/Switch7' */

  /* DataStoreWrite: '<S2>/Data Store Write3' */
  scara_DW.Poz_gora = scara_B.Switch7;

  /* Switch: '<S2>/Switch10' */
  if (scara_B.DataStoreRead17 > scara_P.Switch10_Threshold) {
    /* Gain: '<S24>/Gain' */
    scara_B.Gain_i = scara_P.Gain_Gain_c * scara_B.gamma2;
    scara_B.Switch10 = scara_B.Gain_i;
  } else {
    /* DataStoreRead: '<S2>/Data Store Read13' */
    scara_B.DataStoreRead13 = scara_DW.wyzw_dol;
    scara_B.Switch10 = scara_B.DataStoreRead13;
  }

  /* End of Switch: '<S2>/Switch10' */

  /* Switch: '<S2>/Switch8' */
  if (scara_B.DataStoreRead12 > scara_P.Switch8_Threshold) {
    /* Switch: '<S2>/Switch6' */
    if (scara_B.DataStoreRead11 > scara_P.Switch6_Threshold) {
      scara_B.Switch6 = scara_B.Switch10;
    } else {
      /* DataStoreRead: '<S2>/Data Store Read10' */
      scara_B.DataStoreRead10 = scara_DW.Poz_dol;
      scara_B.Switch6 = scara_B.DataStoreRead10;
    }

    /* End of Switch: '<S2>/Switch6' */
    scara_B.Switch8 = scara_B.Switch6;
  } else {
    scara_B.Switch8 = scara_B.Switch10;
  }

  /* End of Switch: '<S2>/Switch8' */

  /* DataStoreWrite: '<S2>/Data Store Write4' */
  scara_DW.Poz_dol = scara_B.Switch8;

  /* S-Function (rti_commonblock): '<S10>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S2>/Gain' */
  scara_B.Gain = scara_P.Gain_Gain_j * scara_B.SFunction1;

  /* Memory: '<S16>/Memory' */
  scara_B.Memory_k = scara_DW.Memory_PreviousInput_d;

  /* DataStoreRead: '<S2>/Data Store Read' */
  scara_B.DataStoreRead = scara_DW.Poz_gora;

  /* Abs: '<S16>/Abs' */
  scara_B.Abs = fabs(scara_B.DataStoreRead);

  /* Switch: '<S16>/Switch' */
  if (scara_B.Abs > scara_P.Switch_Threshold) {
    scara_B.Switch = scara_B.Memory_k;
  } else {
    scara_B.Switch = scara_B.DataStoreRead;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Sum: '<S2>/Sum' */
  scara_B.Sum = scara_B.Switch - scara_B.Gain;

  /* Gain: '<S2>/Gain1' */
  scara_B.Gain1 = scara_P.Gain1_Gain * scara_B.Sum;

  /* Saturate: '<S2>/Saturation' */
  u0 = scara_B.Gain1;
  u1 = scara_P.Saturation_LowerSat_k;
  u2 = scara_P.Saturation_UpperSat_i;
  if (u0 > u2) {
    scara_B.Saturation = u2;
  } else if (u0 < u1) {
    scara_B.Saturation = u1;
  } else {
    scara_B.Saturation = u0;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Abs: '<S2>/Abs1' */
  scara_B.Abs1 = fabs(scara_B.Saturation);

  /* S-Function (rti_commonblock): '<S11>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* Gain: '<S2>/Gain2' */
  scara_B.Gain2 = scara_P.Gain2_Gain * scara_B.SFunction1_k;

  /* Memory: '<S15>/Memory' */
  scara_B.Memory_m = scara_DW.Memory_PreviousInput_l;

  /* DataStoreRead: '<S2>/Data Store Read1' */
  scara_B.DataStoreRead1 = scara_DW.Poz_dol;

  /* Abs: '<S15>/Abs' */
  scara_B.Abs_p = fabs(scara_B.DataStoreRead1);

  /* Switch: '<S15>/Switch' */
  if (scara_B.Abs_p > scara_P.Switch_Threshold_p) {
    scara_B.Switch_n = scara_B.Memory_m;
  } else {
    scara_B.Switch_n = scara_B.DataStoreRead1;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Sum: '<S2>/Sum1' */
  scara_B.Sum1 = scara_B.Switch_n - scara_B.Gain2;

  /* Gain: '<S2>/Gain3' */
  scara_B.Gain3 = scara_P.Gain3_Gain * scara_B.Sum1;

  /* Saturate: '<S2>/Saturation1' */
  u0 = scara_B.Gain3;
  u1 = scara_P.Saturation1_LowerSat;
  u2 = scara_P.Saturation1_UpperSat;
  if (u0 > u2) {
    scara_B.Saturation1 = u2;
  } else if (u0 < u1) {
    scara_B.Saturation1 = u1;
  } else {
    scara_B.Saturation1 = u0;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Abs: '<S2>/Abs' */
  scara_B.Abs_b = fabs(scara_B.Saturation1);

  /* MinMax: '<S2>/Max' */
  u0 = scara_B.Abs1;
  u1 = scara_B.Abs_b;
  if ((u0 >= u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  scara_B.Max = u1;

  /* End of MinMax: '<S2>/Max' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (scara_B.Logic[0]) {
    scara_B.Switch_g = scara_P.Constant_Value;
  } else {
    /* Product: '<S18>/Divide' */
    scara_B.Divide = scara_B.Abs1 / scara_B.Max;

    /* Saturate: '<S18>/Saturation' */
    u0 = scara_B.Divide;
    u1 = scara_P.Saturation_LowerSat_h;
    u2 = scara_P.Saturation_UpperSat_h;
    if (u0 > u2) {
      scara_B.Saturation_l = u2;
    } else if (u0 < u1) {
      scara_B.Saturation_l = u1;
    } else {
      scara_B.Saturation_l = u0;
    }

    /* End of Saturate: '<S18>/Saturation' */

    /* DataStoreRead: '<S2>/Data Store Read6' */
    scara_B.DataStoreRead6 = scara_DW.predkosc;

    /* Gain: '<S2>/Gain6' */
    scara_B.Gain6 = scara_P.Gain6_Gain * scara_B.DataStoreRead6;

    /* Product: '<S2>/Product3' */
    scara_B.Product3 = scara_B.Saturation * scara_B.Gain6;

    /* Product: '<S2>/Product4' */
    scara_B.Product4 = scara_B.Product3 * scara_B.Saturation_l;
    scara_B.Switch_g = scara_B.Product4;
  }

  /* End of Switch: '<S2>/Switch' */

  /* RateLimiter: '<S2>/Rate Limiter' */
  u1 = scara_B.Switch_g - scara_DW.PrevY;
  if (u1 > scara_P.RateLimiter_RisingLim) {
    scara_B.RateLimiter = scara_DW.PrevY + scara_P.RateLimiter_RisingLim;
  } else if (u1 < scara_P.RateLimiter_FallingLim) {
    scara_B.RateLimiter = scara_DW.PrevY + scara_P.RateLimiter_FallingLim;
  } else {
    scara_B.RateLimiter = scara_B.Switch_g;
  }

  scara_DW.PrevY = scara_B.RateLimiter;

  /* End of RateLimiter: '<S2>/Rate Limiter' */

  /* Gain: '<S2>/Gain4' */
  scara_B.Gain4 = scara_P.Gain4_Gain * scara_B.RateLimiter;

  /* S-Function (rti_commonblock): '<S8>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:DAC */
  ds1104_dac_write(1, scara_B.Gain4);

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  if (scara_B.LogicalOperator1) {
    scara_B.Switch1 = scara_P.Constant1_Value;
  } else {
    /* Product: '<S17>/Divide' */
    scara_B.Divide_g = scara_B.Abs_b / scara_B.Max;

    /* Saturate: '<S17>/Saturation' */
    u0 = scara_B.Divide_g;
    u1 = scara_P.Saturation_LowerSat;
    u2 = scara_P.Saturation_UpperSat;
    if (u0 > u2) {
      scara_B.Saturation_i = u2;
    } else if (u0 < u1) {
      scara_B.Saturation_i = u1;
    } else {
      scara_B.Saturation_i = u0;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* DataStoreRead: '<S2>/Data Store Read7' */
    scara_B.DataStoreRead7 = scara_DW.predkosc;

    /* Gain: '<S2>/Gain7' */
    scara_B.Gain7 = scara_P.Gain7_Gain * scara_B.DataStoreRead7;

    /* Product: '<S2>/Product1' */
    scara_B.Product1 = scara_B.Saturation1 * scara_B.Gain7;

    /* Product: '<S2>/Product2' */
    scara_B.Product2 = scara_B.Product1 * scara_B.Saturation_i;
    scara_B.Switch1 = scara_B.Product2;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* RateLimiter: '<S2>/Rate Limiter1' */
  u1 = scara_B.Switch1 - scara_DW.PrevY_c;
  if (u1 > scara_P.RateLimiter1_RisingLim) {
    scara_B.RateLimiter1 = scara_DW.PrevY_c + scara_P.RateLimiter1_RisingLim;
  } else if (u1 < scara_P.RateLimiter1_FallingLim) {
    scara_B.RateLimiter1 = scara_DW.PrevY_c + scara_P.RateLimiter1_FallingLim;
  } else {
    scara_B.RateLimiter1 = scara_B.Switch1;
  }

  scara_DW.PrevY_c = scara_B.RateLimiter1;

  /* End of RateLimiter: '<S2>/Rate Limiter1' */

  /* Gain: '<S2>/Gain5' */
  scara_B.Gain5 = scara_P.Gain5_Gain * scara_B.RateLimiter1;

  /* S-Function (rti_commonblock): '<S9>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:DAC */
  ds1104_dac_write(2, scara_B.Gain5);

  /* Logic: '<S2>/NOT1' */
  scara_B.NOT1 = !(scara_B.DataTypeConversion2_j != 0.0);

  /* Outputs for Triggered SubSystem: '<S2>/DS1104ENC_SET_POS_C1' incorporates:
   *  TriggerPort: '<S13>/Trigger'
   */
  zcEvent = (scara_B.NOT1 && (scara_PrevZCX.DS1104ENC_SET_POS_C1_Trig_ZCE !=
              POS_ZCSIG));
  if (zcEvent) {
    /* S-Function (rti_commonblock): '<S13>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 Unit:ENC_SET */
    ds1104_inc_position_write(1, 0, DS1104_INC_LINE_SUBDIV_4);
  }

  scara_PrevZCX.DS1104ENC_SET_POS_C1_Trig_ZCE = scara_B.NOT1;

  /* End of Outputs for SubSystem: '<S2>/DS1104ENC_SET_POS_C1' */

  /* Logic: '<S2>/NOT' */
  scara_B.NOT = !(scara_B.DataTypeConversion2 != 0.0);

  /* Outputs for Triggered SubSystem: '<S2>/DS1104ENC_SET_POS_C2' incorporates:
   *  TriggerPort: '<S14>/Trigger'
   */
  zcEvent = (scara_B.NOT && (scara_PrevZCX.DS1104ENC_SET_POS_C2_Trig_ZCE !=
              POS_ZCSIG));
  if (zcEvent) {
    /* S-Function (rti_commonblock): '<S14>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 Unit:ENC_SET */
    ds1104_inc_position_write(2, 0, DS1104_INC_LINE_SUBDIV_4);
  }

  scara_PrevZCX.DS1104ENC_SET_POS_C2_Trig_ZCE = scara_B.NOT;

  /* End of Outputs for SubSystem: '<S2>/DS1104ENC_SET_POS_C2' */

  /* S-Function (rti_commonblock): '<S10>/S-Function2' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S11>/S-Function2' */
  /* This comment workarounds a code generation problem */

  /* DataStoreRead: '<S2>/Data Store Read15' */
  scara_B.DataStoreRead15 = scara_DW.poz_x;

  /* DataStoreRead: '<S2>/Data Store Read16' */
  scara_B.DataStoreRead16 = scara_DW.poz_y;

  /* S-Function (rti_commonblock): '<S12>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* S-Function (rti_commonblock): '<S12>/S-Function2' */
  /* This comment workarounds a code generation problem */
}

/* Model update function */
static void scara_update(void)
{
  /* Update for Memory: '<S32>/Memory' */
  scara_DW.Memory_PreviousInput_dm = scara_B.Logic[0];

  /* Update for Memory: '<S28>/Memory' */
  scara_DW.Memory_PreviousInput_b = scara_B.Logic_b[0];

  /* Update for UnitDelay: '<S27>/Delay Input1' */
  scara_DW.DelayInput1_DSTATE = scara_B.Compare;

  /* Update for UnitDelay: '<S31>/Delay Input1' */
  scara_DW.DelayInput1_DSTATE_l = scara_B.Compare_n;

  /* Update for Memory: '<S2>/Memory' */
  scara_DW.Memory_PreviousInput = scara_B.Switch3;

  /* Update for Memory: '<S19>/Memory1' */
  scara_DW.Memory1_PreviousInput = scara_B.x;

  /* Update for Memory: '<S19>/Memory' */
  scara_DW.Memory_PreviousInput_g = scara_B.y;

  /* Update for Memory: '<S16>/Memory' */
  scara_DW.Memory_PreviousInput_d = scara_B.Switch;

  /* Update for Memory: '<S15>/Memory' */
  scara_DW.Memory_PreviousInput_l = scara_B.Switch_n;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++scara_M->Timing.clockTick0)) {
    ++scara_M->Timing.clockTickH0;
  }

  scara_M->Timing.t[0] = scara_M->Timing.clockTick0 * scara_M->Timing.stepSize0
    + scara_M->Timing.clockTickH0 * scara_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void scara_initialize(void)
{
  /* Start for DataStoreMemory: '<S2>/Data Store Memory' */
  scara_DW.Poz_gora = scara_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory1' */
  scara_DW.Poz_dol = scara_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory10' */
  scara_DW.wsp_kart = scara_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory2' */
  scara_DW.Przycisk_bazowanie = scara_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory3' */
  scara_DW.predkosc = scara_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory4' */
  scara_DW.wyzw_gora = scara_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory5' */
  scara_DW.wyzw_dol = scara_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory6' */
  scara_DW.wyzwol = scara_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory7' */
  scara_DW.wlacz_wyzwolenie = scara_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory8' */
  scara_DW.poz_x = scara_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<S2>/Data Store Memory9' */
  scara_DW.poz_y = scara_P.DataStoreMemory9_InitialValue;
  scara_PrevZCX.DS1104ENC_SET_POS_C1_Trig_ZCE = POS_ZCSIG;
  scara_PrevZCX.DS1104ENC_SET_POS_C2_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Memory: '<S32>/Memory' */
  scara_DW.Memory_PreviousInput_dm = scara_P.Memory_X0_m;

  /* InitializeConditions for Memory: '<S28>/Memory' */
  scara_DW.Memory_PreviousInput_b = scara_P.Memory_X0_e;

  /* InitializeConditions for UnitDelay: '<S27>/Delay Input1' */
  scara_DW.DelayInput1_DSTATE = scara_P.DelayInput1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S31>/Delay Input1' */
  scara_DW.DelayInput1_DSTATE_l = scara_P.DelayInput1_InitialCondition_j;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  scara_DW.Memory_PreviousInput = scara_P.Memory_X0;

  /* InitializeConditions for Memory: '<S19>/Memory1' */
  scara_DW.Memory1_PreviousInput = scara_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S19>/Memory' */
  scara_DW.Memory_PreviousInput_g = scara_P.Memory_X0_d;

  /* InitializeConditions for Memory: '<S16>/Memory' */
  scara_DW.Memory_PreviousInput_d = scara_P.Memory_X0_dm;

  /* InitializeConditions for Memory: '<S15>/Memory' */
  scara_DW.Memory_PreviousInput_l = scara_P.Memory_X0_f;

  /* InitializeConditions for RateLimiter: '<S2>/Rate Limiter' */
  scara_DW.PrevY = scara_P.RateLimiter_IC;

  /* InitializeConditions for RateLimiter: '<S2>/Rate Limiter1' */
  scara_DW.PrevY_c = scara_P.RateLimiter1_IC;
}

/* Model terminate function */
static void scara_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  scara_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  scara_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  scara_initialize();
}

void MdlTerminate(void)
{
  scara_terminate();
}

/* Registration function */
RT_MODEL_scara_T *scara(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)scara_M, 0,
                sizeof(RT_MODEL_scara_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = scara_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    scara_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    scara_M->Timing.sampleTimes = (&scara_M->Timing.sampleTimesArray[0]);
    scara_M->Timing.offsetTimes = (&scara_M->Timing.offsetTimesArray[0]);

    /* task periods */
    scara_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    scara_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(scara_M, &scara_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = scara_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    scara_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(scara_M, -1);
  scara_M->Timing.stepSize0 = 0.001;
  scara_M->solverInfoPtr = (&scara_M->solverInfo);
  scara_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&scara_M->solverInfo, 0.001);
  rtsiSetSolverMode(&scara_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  scara_M->ModelData.blockIO = ((void *) &scara_B);
  (void) memset(((void *) &scara_B), 0,
                sizeof(B_scara_T));

  /* parameters */
  scara_M->ModelData.defaultParam = ((real_T *)&scara_P);

  /* states (dwork) */
  scara_M->ModelData.dwork = ((void *) &scara_DW);
  (void) memset((void *)&scara_DW, 0,
                sizeof(DW_scara_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    scara_rti_init_trc_pointers();
  }

  /* Initialize Sizes */
  scara_M->Sizes.numContStates = (0);  /* Number of continuous states */
  scara_M->Sizes.numY = (0);           /* Number of model outputs */
  scara_M->Sizes.numU = (0);           /* Number of model inputs */
  scara_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  scara_M->Sizes.numSampTimes = (1);   /* Number of sample times */
  scara_M->Sizes.numBlocks = (155);    /* Number of blocks */
  scara_M->Sizes.numBlockIO = (105);   /* Number of block outputs */
  scara_M->Sizes.numBlockPrms = (96);  /* Sum of parameter "widths" */
  return scara_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
