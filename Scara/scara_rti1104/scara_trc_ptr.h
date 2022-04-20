  /*********************** dSPACE target specific file *************************

   Header file scara_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 7.4 (02-May-2015)
   Thu Nov 25 10:18:38 2021

   (c) Copyright 2021, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_scara_trc_ptr_h_
  #define RTI_HEADER_scara_trc_ptr_h_
  /* Include the model header file. */
  #include "scara.h"
  #include "scara_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_0_scara_real_T_0;
              EXTERN_C volatile  boolean_T *p_0_scara_boolean_T_1;
              EXTERN_C volatile  real_T *p_1_scara_real_T_0;
              EXTERN_C volatile  boolean_T *p_1_scara_boolean_T_1;
              EXTERN_C volatile  real_T *p_2_scara_real_T_0;
              EXTERN_C volatile  boolean_T *p_2_scara_boolean_T_1;

  /*
   *  Declare the general function for TRC pointer initialization
   */
  EXTERN_C void scara_rti_init_trc_pointers(void);
   #endif                       /* RTI_HEADER_scara_trc_ptr_h_ */
