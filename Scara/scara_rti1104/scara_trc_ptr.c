/***************************************************************************

   Source file scara_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 7.4 (02-May-2015)
   Thu Nov 25 10:18:38 2021

   (c) Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "scara_trc_ptr.h"
#include "scara.h"
#include "scara_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_scara_real_T_0 = NULL;
volatile boolean_T *p_0_scara_boolean_T_1 = NULL;
volatile real_T *p_1_scara_real_T_0 = NULL;
volatile boolean_T *p_1_scara_boolean_T_1 = NULL;
volatile real_T *p_2_scara_real_T_0 = NULL;
volatile boolean_T *p_2_scara_boolean_T_1 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_scara_real_T_0 = &scara_B.DataStoreRead2;
  p_0_scara_boolean_T_1 = &scara_B.DataTypeConversion;
  p_1_scara_real_T_0 = &scara_P.Gain_Gain;
  p_1_scara_boolean_T_1 = &scara_P.Memory_X0_m;
  p_2_scara_real_T_0 = &scara_DW.Memory_PreviousInput;
  p_2_scara_boolean_T_1 = &scara_DW.DelayInput1_DSTATE;
}

void scara_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
