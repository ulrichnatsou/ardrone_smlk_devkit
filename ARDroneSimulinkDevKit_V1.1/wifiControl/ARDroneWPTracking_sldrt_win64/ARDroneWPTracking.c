/*
 * ARDroneWPTracking.c
 *
 * Code generation for model "ARDroneWPTracking".
 *
 * Model version              : $Id: UAV_PIL.mdl 965 2013-03-21 01:08:53Z escobar $
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Mon Jan 27 00:10:40 2020
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ARDroneWPTracking.h"
#include "ARDroneWPTracking_private.h"
#include "ARDroneWPTracking_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  3.232235777E+9,
  5554.0,
};

/* options for Simulink Desktop Real-Time board 1 */
static double SLDRTBoardOptions1[] = {
  3.232235777E+9,
  5556.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 2;
const double SLDRTTimers[4] = {
  0.065, 0.0,
  0.65, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 2;
SLDRTBOARD SLDRTBoards[2] = {
  { "Standard_Devices/UDP_Protocol", 5554U, 2, SLDRTBoardOptions0 },

  { "Standard_Devices/UDP_Protocol", 5556U, 2, SLDRTBoardOptions1 },
};

/* Block signals (auto storage) */
B_ARDroneWPTracking_T ARDroneWPTracking_B;

/* Continuous states */
X_ARDroneWPTracking_T ARDroneWPTracking_X;

/* Block states (auto storage) */
DW_ARDroneWPTracking_T ARDroneWPTracking_DW;

/* Real-time model */
RT_MODEL_ARDroneWPTracking_T ARDroneWPTracking_M_;
RT_MODEL_ARDroneWPTracking_T *const ARDroneWPTracking_M = &ARDroneWPTracking_M_;

/* Forward declaration for local functions */
static void ARDroneWPTracking_dec2hex(const uint8_T d[4], char_T s_data[],
  int32_T s_size[2]);
static real_T ARDroneWPTracking_hex2dec(const char_T s_data[], const int32_T
  s_size[2]);
static void ARDroneWPTracking_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2]);
static int32_T ARDroneWPTracking_float2IEEE754(real_T fVal);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(ARDroneWPTracking_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(ARDroneWPTracking_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (ARDroneWPTracking_M->Timing.TaskCounters.TID[1] == 0) {
    ARDroneWPTracking_M->Timing.RateInteraction.TID1_2 =
      (ARDroneWPTracking_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    ARDroneWPTracking_M->Timing.perTaskSampleHits[5] =
      ARDroneWPTracking_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ARDroneWPTracking_M->Timing.TaskCounters.TID[2])++;
  if ((ARDroneWPTracking_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.65s, 0.0s] */
    ARDroneWPTracking_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ARDroneWPTracking_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static void ARDroneWPTracking_dec2hex(const uint8_T d[4], char_T s_data[],
  int32_T s_size[2])
{
  uint8_T di;
  uint8_T r;
  int32_T j;
  int32_T firstcol;
  boolean_T p;
  boolean_T exitg1;
  boolean_T exitg2;
  s_size[0] = 4;
  s_size[1] = 2;
  for (j = 0; j < 8; j++) {
    s_data[j] = '0';
  }

  di = d[0];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[(j - 1) << 2] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[1];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[1 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[2];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[2 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  di = d[3];
  j = 2;
  exitg1 = false;
  while ((!exitg1) && (j > 0)) {
    r = di;
    di = (uint8_T)((uint32_T)di >> 4);
    r = (uint8_T)((uint32_T)r - (di << 4));
    if (r > 9) {
      r = (uint8_T)(r + 7U);
    }

    s_data[3 + ((j - 1) << 2)] = (int8_T)(r + 48);
    if (di > 0) {
      j--;
    } else {
      exitg1 = true;
    }
  }

  firstcol = 2;
  j = 1;
  exitg1 = false;
  while ((!exitg1) && (j <= 1)) {
    p = false;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j <= 3)) {
      if (s_data[j] != '0') {
        p = true;
        exitg2 = true;
      } else {
        j++;
      }
    }

    if (p) {
      firstcol = 1;
      exitg1 = true;
    } else {
      j = 2;
    }
  }

  if (firstcol > 1) {
    s_data[0] = s_data[4];
    s_data[1] = s_data[5];
    s_data[2] = s_data[6];
    s_data[3] = s_data[7];
    s_size[0] = 4;
    s_size[1] = 1;
  }
}

/* Function for MATLAB Function: '<S1>/ARDrone data decoding' */
static real_T ARDroneWPTracking_hex2dec(const char_T s_data[], const int32_T
  s_size[2])
{
  real_T x;
  real_T p16;
  int32_T j;
  int32_T b;
  int32_T b_j;
  x = 0.0;
  p16 = 1.0;
  b = (int32_T)(((-1.0 - (real_T)s_size[1]) + 1.0) / -1.0);
  for (b_j = 1; b_j - 1 < b; b_j++) {
    j = s_size[1] - b_j;
    if (s_data[s_size[0] * j] != ' ') {
      j = (uint8_T)s_data[s_size[0] * j];
      if ((j != 0) && (j != 48)) {
        if (!(j <= 57)) {
          if (j > 70) {
            j -= 39;
          } else {
            j -= 7;
          }
        }

        x += ((real_T)j - 48.0) * p16;
      }

      p16 *= 16.0;
    }
  }

  return x;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

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
        y = 1.0;
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

/* Function for MATLAB Function: '<S8>/Drone state request' */
static void ARDroneWPTracking_getString(real_T a, char_T strOut_data[], int32_T
  strOut_size[2])
{
  int32_T d;
  uint8_T digit_data[11];
  int32_T k;
  real_T r;
  int32_T digit_size_idx_1;

  /* '<S10>:1:138' */
  d = 0;
  if ((a >= 10.0) && (a < 100.0)) {
    /* '<S10>:1:144' */
    /* '<S10>:1:145' */
    d = 1;
  }

  if ((a >= 100.0) && (a < 1000.0)) {
    /* '<S10>:1:148' */
    /* '<S10>:1:149' */
    d = 2;
  }

  if ((a >= 1000.0) && (a < 10000.0)) {
    /* '<S10>:1:152' */
    /* '<S10>:1:153' */
    d = 3;
  }

  if ((a >= 10000.0) && (a < 100000.0)) {
    /* '<S10>:1:156' */
    /* '<S10>:1:157' */
    d = 4;
  }

  if ((a >= 100000.0) && (a < 1.0E+6)) {
    /* '<S10>:1:160' */
    /* '<S10>:1:161' */
    d = 5;
  }

  if ((a >= 1.0E+6) && (a < 1.0E+7)) {
    /* '<S10>:1:164' */
    /* '<S10>:1:165' */
    d = 6;
  }

  if ((a >= 1.0E+7) && (a < 1.0E+8)) {
    /* '<S10>:1:168' */
    /* '<S10>:1:169' */
    d = 7;
  }

  if ((a >= 1.0E+8) && (a < 1.0E+9)) {
    /* '<S10>:1:172' */
    /* '<S10>:1:173' */
    d = 8;
  }

  if ((a >= 1.0E+9) && (a < 1.0E+10)) {
    /* '<S10>:1:176' */
    /* '<S10>:1:177' */
    d = 9;
  }

  if (a >= 1.0E+10) {
    /* '<S10>:1:180' */
    /* '<S10>:1:181' */
    d = 10;
  }

  /* '<S10>:1:186' */
  digit_size_idx_1 = d + 1;
  if (0 <= d) {
    memset(&digit_data[0], 0, (d + 1) * sizeof(uint8_T));
  }

  /* '<S10>:1:189' */
  for (k = 0; k <= d; k++) {
    /* '<S10>:1:189' */
    /* '<S10>:1:191' */
    if (!rtIsInf(a)) {
      if (a == 0.0) {
        r = 0.0;
      } else {
        r = fmod(a, rt_powd_snf(10.0, 1.0 + (real_T)k));
        if (r == 0.0) {
          r = 0.0;
        }
      }
    } else {
      r = (rtNaN);
    }

    /* '<S10>:1:194' */
    r = r / rt_powd_snf(10.0, (1.0 + (real_T)k) - 1.0) + 48.0;
    if (r < 0.0) {
      r = ceil(r);
    } else {
      r = floor(r);
    }

    if (rtIsNaN(r)) {
      r = 0.0;
    } else {
      r = fmod(r, 256.0);
    }

    digit_data[d - k] = (uint8_T)(r < 0.0 ? (int32_T)(int8_T)-(int8_T)(uint8_T)
      -r : (int32_T)(int8_T)(uint8_T)r);
  }

  /* '<S10>:1:199' */
  strOut_size[0] = 1;
  strOut_size[1] = digit_size_idx_1;
  for (d = 0; d < digit_size_idx_1; d++) {
    strOut_data[d] = (int8_T)digit_data[d];
  }
}

/* Function for MATLAB Function: '<S8>/Drone state request' */
static int32_T ARDroneWPTracking_float2IEEE754(real_T fVal)
{
  int32_T iVal;
  char_T binData[32];
  char_T binData2[32];
  int32_T bit;
  real_T b_iVal;
  uint8_T y[4];
  real32_T x;
  int32_T b_k;

  /* '<S10>:1:209' */
  /* '<S10>:1:207' */
  x = (real32_T)fVal;
  memcpy((void *)&y[0], (void *)&x, (uint32_T)((size_t)4 * sizeof(uint8_T)));
  for (b_k = 0; b_k < 32; b_k++) {
    binData[b_k] = '0';
  }

  for (b_k = 0; b_k < 4; b_k++) {
    for (bit = 0; bit < 8; bit++) {
      if ((1 << bit & y[b_k]) != 0) {
        binData[b_k + ((7 - bit) << 2)] = '1';
      }
    }
  }

  /* '<S10>:1:209' */
  for (b_k = 0; b_k < 8; b_k++) {
    binData2[b_k] = binData[(b_k << 2) + 3];
    binData2[b_k + 8] = binData[(b_k << 2) + 2];
    binData2[b_k + 16] = binData[(b_k << 2) + 1];
    binData2[b_k + 24] = binData[b_k << 2];
  }

  /* '<S10>:1:210' */
  b_iVal = 0.0;

  /* '<S10>:1:211' */
  for (b_k = 0; b_k < 32; b_k++) {
    /* '<S10>:1:211' */
    if (binData2[31 - b_k] == '1') {
      /* '<S10>:1:213' */
      /* '<S10>:1:214' */
      bit = 1;
    } else {
      /* '<S10>:1:216' */
      bit = 0;
    }

    if (32 - b_k == 1) {
      /* '<S10>:1:219' */
      /* '<S10>:1:220' */
      b_iVal -= (real_T)bit * 2.147483648E+9;
    } else {
      /* '<S10>:1:222' */
      b_iVal += rt_powd_snf(2.0, 32.0 - (32.0 + -(real_T)b_k)) * (real_T)bit;
    }
  }

  /* '<S10>:1:227' */
  if (b_iVal < 2.147483648E+9) {
    if (b_iVal >= -2.147483648E+9) {
      iVal = (int32_T)b_iVal;
    } else {
      iVal = MIN_int32_T;
    }
  } else {
    iVal = MAX_int32_T;
  }

  return iVal;
}

/* Model output function for TID0 */
void ARDroneWPTracking_output0(void)   /* Sample time: [0.0s, 0.0s] */
{
  real_T bytesToRead;
  real_T bytesLeft;
  int32_T m;
  uint8_T data[496];
  char_T hex_data[8];
  char_T b_hex_data[8];
  real32_T res;
  real32_T b_res;
  real_T scale;
  real_T t;
  char_T cmd_data[148];
  char_T strCmd_data[11];
  int32_T aux;
  char_T strAux_data[12];
  static const char_T c[10] = { 'A', 'T', '*', 'C', 'O', 'N', 'F', 'I', 'G', '='
  };

  static const char_T d[30] = { ',', '\"', 'g', 'e', 'n', 'e', 'r', 'a', 'l',
    ':', 'n', 'a', 'v', 'd', 'a', 't', 'a', '_', 'd', 'e', 'm', 'o', '\"', ',',
    '\"', 'T', 'R', 'U', 'E', '\"' };

  static const char_T e[10] = { 'A', 'T', '*', 'C', 'O', 'M', 'W', 'D', 'G', '='
  };

  static const char_T f[7] = { 'A', 'T', '*', 'R', 'E', 'F', '=' };

  static const char_T g[10] = { ',', '2', '9', '0', '7', '1', '7', '9', '5', '2'
  };

  static const char_T h[30] = { '\"', 'c', 'o', 'n', 'r', 'o', 'l', ':', 'a',
    'l', 't', 'i', 't', 'u', 'd', 'e', '_', 'm', 'a', 'x', '\"', ',', '\"', '1',
    '0', '0', '0', '0', '0', '\"' };

  static const char_T i[9] = { 'A', 'T', '*', 'F', 'T', 'R', 'I', 'M', '=' };

  static const char_T j[10] = { ',', '2', '9', '0', '7', '1', '8', '2', '0', '8'
  };

  static const char_T k[10] = { ',', '2', '9', '0', '7', '1', '7', '6', '9', '6'
  };

  static const char_T l[8] = { 'A', 'T', '*', 'P', 'C', 'M', 'D', '=' };

  real32_T rtb_yawAngle;
  real32_T rtb_u;
  real32_T rtb_v;
  real32_T rtb_w;
  real_T rtb_hRef;
  int8_T rtb_status[32];
  int32_T i_0;
  int32_T loop_ub;
  uint8_T tmp_data[1024];
  int32_T loop_ub_0;
  int32_T loop_ub_1;
  char_T cmd_data_0[148];
  int32_T hex_size[2];
  int32_T hex_size_0[2];
  int32_T hex_size_1[2];
  int32_T hex_size_2[2];
  int32_T hex_size_3[2];
  int32_T hex_size_4[2];
  int32_T hex_size_5[2];
  int32_T hex_size_6[2];
  int32_T hex_size_7[2];
  int32_T strAux_size_idx_1;
  uint32_T x;
  real_T u0;
  real_T t_tmp;
  real_T u0_tmp;
  boolean_T guard1 = false;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(ARDroneWPTracking_M)) {
    /* set solver stop time */
    if (!(ARDroneWPTracking_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ARDroneWPTracking_M->solverInfo,
                            ((ARDroneWPTracking_M->Timing.clockTickH0 + 1) *
        ARDroneWPTracking_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ARDroneWPTracking_M->solverInfo,
                            ((ARDroneWPTracking_M->Timing.clockTick0 + 1) *
        ARDroneWPTracking_M->Timing.stepSize0 +
        ARDroneWPTracking_M->Timing.clockTickH0 *
        ARDroneWPTracking_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ARDroneWPTracking_M)) {
    ARDroneWPTracking_M->Timing.t[0] = rtsiGetT(&ARDroneWPTracking_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ARDroneWPTracking_M)) {
    /* S-Function (sldrtpi): '<S1>/Packet Input' */
    /* S-Function Block: <S1>/Packet Input */
    {
      uint8_T indata[500U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 500U,
        &ARDroneWPTracking_P.PacketInput_PacketID, (double*) indata, NULL);
      ARDroneWPTracking_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;

        {
          int_T i1;
          uint8_T *y0 = &ARDroneWPTracking_B.PacketInput_o1[0];
          for (i1=0; i1 < 500; i1++) {
            y0[i1] = *indp.p_uint8_T++;
          }
        }
      }
    }

    /* MATLAB Function: '<S1>/Data synchronization ' */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/Data synchronization ': '<S7>:1' */
    /* '<S7>:1:52' */
    for (i_0 = 0; i_0 < 500; i_0++) {
      ARDroneWPTracking_DW.buffer[(int32_T)(ARDroneWPTracking_DW.countBuffer +
        ((real_T)i_0 + 1.0)) - 1] = ARDroneWPTracking_B.PacketInput_o1[i_0];
    }

    /* '<S7>:1:54' */
    bytesToRead = ARDroneWPTracking_DW.countBuffer + 500.0;

    /* '<S7>:1:59' */
    aux = 0;
    exitg1 = false;
    while ((!exitg1) && (aux <= (int32_T)(ARDroneWPTracking_DW.countBuffer +
             500.0) - 1)) {
      /* '<S7>:1:59' */
      if ((ARDroneWPTracking_DW.countHeader == 4.0) &&
          (ARDroneWPTracking_DW.count < 496.0)) {
        /* '<S7>:1:60' */
        /* '<S7>:1:61' */
        bytesLeft = 496.0 - ARDroneWPTracking_DW.count;
        t_tmp = (1.0 + (real_T)aux) + (496.0 - ARDroneWPTracking_DW.count);
        if (1.0 + (real_T)aux > t_tmp - 1.0) {
          m = 1;
          loop_ub = 0;
        } else {
          m = aux + 1;
          loop_ub = (int32_T)(t_tmp - 1.0);
        }

        /* '<S7>:1:62' */
        i_0 = (int32_T)(ARDroneWPTracking_DW.count + 1.0) - 1;
        loop_ub -= m;
        for (loop_ub_0 = 0; loop_ub_0 <= loop_ub; loop_ub_0++) {
          ARDroneWPTracking_DW.frame[i_0 + loop_ub_0] =
            ARDroneWPTracking_DW.buffer[(m + loop_ub_0) - 1];
        }

        /* '<S7>:1:63' */
        ARDroneWPTracking_DW.count = 496.0;

        /* '<S7>:1:64' */
        ARDroneWPTracking_DW.countBuffer = (ARDroneWPTracking_DW.countBuffer +
          500.0) - bytesLeft;
        t = (1.0 + (real_T)aux) + bytesLeft;
        if (t > bytesToRead) {
          aux = 0;
          m = 0;
        } else {
          aux = (int32_T)t - 1;
          m = (int32_T)bytesToRead;
        }

        /* '<S7>:1:65' */
        loop_ub = m - aux;
        for (i_0 = 0; i_0 < loop_ub; i_0++) {
          tmp_data[i_0] = ARDroneWPTracking_DW.buffer[aux + i_0];
        }

        if (0 <= loop_ub - 1) {
          memcpy(&ARDroneWPTracking_DW.buffer[0], &tmp_data[0], loop_ub * sizeof
                 (uint8_T));
        }

        exitg1 = true;
      } else if ((ARDroneWPTracking_DW.countHeader == 3.0) &&
                 (ARDroneWPTracking_DW.buffer[aux] == 85)) {
        /* '<S7>:1:70' */
        /* '<S7>:1:72' */
        ARDroneWPTracking_DW.countHeader = 4.0;
        t = (ARDroneWPTracking_DW.countBuffer + 500.0) - (1.0 + (real_T)aux);
        if (t > 496.0) {
          /* '<S7>:1:74' */
          /* '<S7>:1:75' */
          ARDroneWPTracking_DW.count = 496.0;

          /* '<S7>:1:76' */
          for (i_0 = 0; i_0 < 496; i_0++) {
            ARDroneWPTracking_DW.frame[(int16_T)i_0] =
              ARDroneWPTracking_DW.buffer[(int32_T)((1.0 + (real_T)aux) +
              (real_T)(int16_T)(1 + i_0)) - 1];
          }

          /* '<S7>:1:77' */
          ARDroneWPTracking_DW.countBuffer = ((ARDroneWPTracking_DW.countBuffer
            + 500.0) - (1.0 + (real_T)aux)) - 496.0;
          if (((1.0 + (real_T)aux) + 496.0) + 1.0 > bytesToRead) {
            aux = 0;
            m = 0;
          } else {
            aux = (int32_T)(((1.0 + (real_T)aux) + 496.0) + 1.0) - 1;
            m = (int32_T)bytesToRead;
          }

          /* '<S7>:1:78' */
          loop_ub = m - aux;
          for (i_0 = 0; i_0 < loop_ub; i_0++) {
            tmp_data[i_0] = ARDroneWPTracking_DW.buffer[aux + i_0];
          }

          if (0 <= loop_ub - 1) {
            memcpy(&ARDroneWPTracking_DW.buffer[0], &tmp_data[0], loop_ub *
                   sizeof(uint8_T));
          }
        } else {
          /* '<S7>:1:81' */
          ARDroneWPTracking_DW.count = t;
          if (ARDroneWPTracking_DW.count > 0.0) {
            /* '<S7>:1:82' */
            if ((1.0 + (real_T)aux) + 1.0 > ARDroneWPTracking_DW.countBuffer +
                500.0) {
              aux = 1;
              m = 0;
            } else {
              aux = (int32_T)((1.0 + (real_T)aux) + 1.0);
              m = (int32_T)(ARDroneWPTracking_DW.countBuffer + 500.0);
            }

            /* '<S7>:1:83' */
            loop_ub = m - aux;
            for (i_0 = 0; i_0 <= loop_ub; i_0++) {
              ARDroneWPTracking_DW.frame[i_0] = ARDroneWPTracking_DW.buffer[(aux
                + i_0) - 1];
            }
          }

          /* '<S7>:1:85' */
          ARDroneWPTracking_DW.countBuffer = 0.0;
        }

        exitg1 = true;
      } else {
        if ((ARDroneWPTracking_DW.countHeader == 2.0) &&
            (ARDroneWPTracking_DW.buffer[aux] == 102)) {
          /* '<S7>:1:92' */
          /* '<S7>:1:93' */
          ARDroneWPTracking_DW.countHeader = 3.0;
        }

        if ((ARDroneWPTracking_DW.countHeader == 1.0) &&
            (ARDroneWPTracking_DW.buffer[aux] == 119)) {
          /* '<S7>:1:96' */
          /* '<S7>:1:97' */
          ARDroneWPTracking_DW.countHeader = 2.0;
        }

        if ((ARDroneWPTracking_DW.countHeader == 0.0) &&
            (ARDroneWPTracking_DW.buffer[aux] == 136)) {
          /* '<S7>:1:100' */
          /* '<S7>:1:101' */
          ARDroneWPTracking_DW.countHeader = 1.0;
        }

        aux++;
      }
    }

    if (ARDroneWPTracking_DW.count == 496.0) {
      /* '<S7>:1:106' */
      /* '<S7>:1:107' */
      /* '<S7>:1:108' */
      /* '<S7>:1:109' */
      /* '<S7>:1:110' */
      for (i_0 = 0; i_0 < 496; i_0++) {
        ARDroneWPTracking_DW.lastFrame[i_0] = ARDroneWPTracking_DW.frame[i_0];
        ARDroneWPTracking_DW.frame[i_0] = 0U;
      }

      /* '<S7>:1:111' */
      ARDroneWPTracking_DW.count = 0.0;

      /* '<S7>:1:112' */
      ARDroneWPTracking_DW.countHeader = 0.0;
    } else {
      /* '<S7>:1:115' */
      /* '<S7>:1:116' */
    }

    /* MATLAB Function: '<S1>/ARDrone data decoding' incorporates:
     *  MATLAB Function: '<S1>/Data synchronization '
     */
    memcpy(&data[0], &ARDroneWPTracking_DW.lastFrame[0], 496U * sizeof(uint8_T));

    /* MATLAB Function 'ARDrone Wi-Fi  Block/ARDrone data decoding': '<S6>:1' */
    /* '<S6>:1:23' */
    /* '<S6>:1:25' */
    /* '<S6>:1:27' */
    if (ARDroneWPTracking_DW.lastFrame[14] == 148) {
      /* '<S6>:1:30' */
      /* '<S6>:1:31' */
      memcpy(&ARDroneWPTracking_DW.dataPrev[0], &ARDroneWPTracking_DW.lastFrame
             [0], 496U * sizeof(uint8_T));
    } else {
      /* '<S6>:1:33' */
      memcpy(&data[0], &ARDroneWPTracking_DW.dataPrev[0], 496U * sizeof(uint8_T));
    }

    /* '<S6>:1:37' */
    /* '<S6>:1:74' */
    for (i_0 = 0; i_0 < 32; i_0++) {
      rtb_status[i_0] = 0;
    }

    /* '<S6>:1:75' */
    ARDroneWPTracking_dec2hex(&data[0], hex_data, hex_size);

    /* '<S6>:1:77' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    aux = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    /* '<S6>:1:78' */
    for (m = 0; m < aux; m++) {
      /* '<S6>:1:78' */
      if (b_hex_data[m] == 'F') {
        /* '<S6>:1:79' */
        /* '<S6>:1:80' */
        rtb_status[((1 + m) << 2) - 4] = 1;
        rtb_status[((1 + m) << 2) - 3] = 1;
        rtb_status[((1 + m) << 2) - 2] = 1;
        rtb_status[((1 + m) << 2) - 1] = 1;
      } else if (b_hex_data[m] == 'E') {
        /* '<S6>:1:81' */
        /* '<S6>:1:82' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == 'D') {
        /* '<S6>:1:83' */
        /* '<S6>:1:84' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == 'C') {
        /* '<S6>:1:85' */
        /* '<S6>:1:86' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == 'B') {
        /* '<S6>:1:87' */
        /* '<S6>:1:88' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == 'A') {
        /* '<S6>:1:89' */
        /* '<S6>:1:90' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '9') {
        /* '<S6>:1:91' */
        /* '<S6>:1:92' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '8') {
        /* '<S6>:1:93' */
        /* '<S6>:1:94' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 1;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '7') {
        /* '<S6>:1:95' */
        /* '<S6>:1:96' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '6') {
        /* '<S6>:1:97' */
        /* '<S6>:1:98' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '5') {
        /* '<S6>:1:99' */
        /* '<S6>:1:100' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '4') {
        /* '<S6>:1:101' */
        /* '<S6>:1:102' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 1;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '3') {
        /* '<S6>:1:103' */
        /* '<S6>:1:104' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 1;
      } else if (b_hex_data[m] == '2') {
        /* '<S6>:1:105' */
        /* '<S6>:1:106' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 1;
        rtb_status[3 + i_0] = 0;
      } else if (b_hex_data[m] == '1') {
        /* '<S6>:1:107' */
        /* '<S6>:1:108' */
        i_0 = ((1 + m) << 2) - 4;
        rtb_status[i_0] = 0;
        rtb_status[1 + i_0] = 0;
        rtb_status[2 + i_0] = 0;
        rtb_status[3 + i_0] = 1;
      } else {
        if (b_hex_data[m] == '0') {
          /* '<S6>:1:109' */
          /* '<S6>:1:110' */
          rtb_status[((1 + m) << 2) - 4] = 0;
          rtb_status[((1 + m) << 2) - 3] = 0;
          rtb_status[((1 + m) << 2) - 2] = 0;
          rtb_status[((1 + m) << 2) - 1] = 0;
        }
      }
    }

    /* '<S6>:1:38' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[20], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:67' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_7[0] = 1;
    hex_size_7[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    /* DataTypeConversion: '<S1>/Type Conversion' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneWPTracking_B.TypeConversion = ARDroneWPTracking_hex2dec(b_hex_data,
      hex_size_7);

    /* MATLAB Function: '<S1>/ARDrone data decoding' */
    /* '<S6>:1:39' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[24], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_6[0] = 1;
    hex_size_6[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    t = rt_roundd_snf(ARDroneWPTracking_hex2dec(b_hex_data, hex_size_6));
    if (t < 4.294967296E+9) {
      if (t >= 0.0) {
        x = (uint32_T)t;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&res, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S6>:1:40' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[28], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_5[0] = 1;
    hex_size_5[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    t = rt_roundd_snf(ARDroneWPTracking_hex2dec(b_hex_data, hex_size_5));
    if (t < 4.294967296E+9) {
      if (t >= 0.0) {
        x = (uint32_T)t;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&b_res, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S6>:1:41' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[32], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_4[0] = 1;
    hex_size_4[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    t = rt_roundd_snf(ARDroneWPTracking_hex2dec(b_hex_data, hex_size_4));
    if (t < 4.294967296E+9) {
      if (t >= 0.0) {
        x = (uint32_T)t;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_yawAngle, (void *)&x, (uint32_T)((size_t)1 * sizeof
            (real32_T)));

    /* '<S6>:1:42' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[36], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:67' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_3[0] = 1;
    hex_size_3[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    bytesLeft = ARDroneWPTracking_hex2dec(b_hex_data, hex_size_3) / 1000.0;

    /* '<S6>:1:43' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[40], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_2[0] = 1;
    hex_size_2[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    t = rt_roundd_snf(ARDroneWPTracking_hex2dec(b_hex_data, hex_size_2));
    if (t < 4.294967296E+9) {
      if (t >= 0.0) {
        x = (uint32_T)t;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_u, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S6>:1:44' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[44], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_1[0] = 1;
    hex_size_1[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    t = rt_roundd_snf(ARDroneWPTracking_hex2dec(b_hex_data, hex_size_1));
    if (t < 4.294967296E+9) {
      if (t >= 0.0) {
        x = (uint32_T)t;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_v, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));

    /* '<S6>:1:45' */
    /* '<S6>:1:64' */
    ARDroneWPTracking_dec2hex(&data[48], hex_data, hex_size);

    /* '<S6>:1:65' */
    /* '<S6>:1:69' */
    loop_ub = hex_size[1];
    m = hex_size[1];
    loop_ub_0 = hex_size[1];
    loop_ub_1 = hex_size[1];
    hex_size_0[0] = 1;
    hex_size_0[1] = ((hex_size[1] + hex_size[1]) + hex_size[1]) + hex_size[1];
    for (i_0 = 0; i_0 < loop_ub; i_0++) {
      b_hex_data[i_0] = hex_data[hex_size[0] * i_0 + 3];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      b_hex_data[i_0 + loop_ub] = hex_data[hex_size[0] * i_0 + 2];
    }

    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      b_hex_data[(i_0 + loop_ub) + m] = hex_data[hex_size[0] * i_0 + 1];
    }

    for (i_0 = 0; i_0 < loop_ub_1; i_0++) {
      b_hex_data[((i_0 + loop_ub) + m) + loop_ub_0] = hex_data[hex_size[0] * i_0];
    }

    t = rt_roundd_snf(ARDroneWPTracking_hex2dec(b_hex_data, hex_size_0));
    if (t < 4.294967296E+9) {
      if (t >= 0.0) {
        x = (uint32_T)t;
      } else {
        x = 0U;
      }
    } else {
      x = MAX_uint32_T;
    }

    memcpy((void *)&rtb_w, (void *)&x, (uint32_T)((size_t)1 * sizeof(real32_T)));
    if ((rtb_status[31] == 1) && (bytesLeft < 0.2)) {
      /* '<S6>:1:49' */
      /* '<S6>:1:50' */
      bytesLeft = ARDroneWPTracking_DW.hPrev;
    } else {
      if (rtb_status[31] == 1) {
        /* '<S6>:1:51' */
        /* '<S6>:1:52' */
        ARDroneWPTracking_DW.hPrev = bytesLeft;
      }
    }

    rtb_yawAngle /= 1000.0F;
    rtb_u /= 1000.0F;
    rtb_v /= 1000.0F;
    rtb_w /= 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion1' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneWPTracking_B.TypeConversion1 = b_res / 1000.0F;

    /* DataTypeConversion: '<S1>/Type Conversion2' incorporates:
     *  MATLAB Function: '<S1>/ARDrone data decoding'
     */
    ARDroneWPTracking_B.TypeConversion2 = res / 1000.0F;

    /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
     *  Constant: '<Root>/commands disabled'
     *  Constant: '<Root>/commands enabled'
     */
    if (ARDroneWPTracking_P.ManualSwitch2_CurrentSetting == 1) {
      bytesToRead = ARDroneWPTracking_P.commandsdisabled_Value;
    } else {
      bytesToRead = ARDroneWPTracking_P.commandsenabled_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' incorporates:
     *  DataTypeConversion: '<S1>/Type Conversion3'
     *  UnitDelay: '<S1>/Unit Delay to avoid algebraic loop'
     */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ': '<S9>:1' */
    /* '<S9>:1:6' */
    ARDroneWPTracking_B.yawOut = rtb_yawAngle;
    if ((ARDroneWPTracking_DW.UnitDelaytoavoidalgebraicloop_DSTATE == 1.0) &&
        (bytesToRead == 1.0)) {
      /* '<S9>:1:19' */
      /* '<S9>:1:20' */
      ARDroneWPTracking_B.yawOut = rtb_yawAngle - ARDroneWPTracking_DW.yaw0;

      /* '<S9>:1:21' */
      ARDroneWPTracking_DW.mode = 1.0;
    } else {
      if ((ARDroneWPTracking_DW.UnitDelaytoavoidalgebraicloop_DSTATE == 1.0) &&
          (ARDroneWPTracking_DW.mode == 0.0)) {
        /* '<S9>:1:22' */
        /* '<S9>:1:23' */
        ARDroneWPTracking_DW.yaw0 = rtb_yawAngle;
      }
    }

    /* '<S9>:1:27' */
    t = ARDroneWPTracking_B.yawOut;
    if ((!rtIsInf(ARDroneWPTracking_B.yawOut)) && (!rtIsNaN
         (ARDroneWPTracking_B.yawOut))) {
      if (ARDroneWPTracking_B.yawOut == 0.0) {
        ARDroneWPTracking_B.yawOut = 0.0;
      } else {
        ARDroneWPTracking_B.yawOut = fmod(ARDroneWPTracking_B.yawOut, 360.0);
        if (ARDroneWPTracking_B.yawOut == 0.0) {
          ARDroneWPTracking_B.yawOut = 0.0;
        } else {
          if (t < 0.0) {
            ARDroneWPTracking_B.yawOut += 360.0;
          }
        }
      }
    } else {
      ARDroneWPTracking_B.yawOut = (rtNaN);
    }

    if (ARDroneWPTracking_B.yawOut > 180.0) {
      /* '<S9>:1:28' */
      /* '<S9>:1:29' */
      ARDroneWPTracking_B.yawOut += -360.0;
    }

    /* End of MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
  }

  /* Clock: '<Root>/Clock1' */
  ARDroneWPTracking_B.Clock1 = ARDroneWPTracking_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ARDroneWPTracking_M)) {
    /* DataTypeConversion: '<S1>/Type Conversion4' */
    ARDroneWPTracking_B.TypeConversion4 = bytesLeft;

    /* Constant: '<S19>/Constant1' */
    ARDroneWPTracking_B.Constant1[0] = ARDroneWPTracking_P.Constant1_Value[0];
    ARDroneWPTracking_B.Constant1[1] = ARDroneWPTracking_P.Constant1_Value[1];
  }

  /* Integrator: '<S19>/Integrator' */
  if (ARDroneWPTracking_DW.Integrator_IWORK != 0) {
    ARDroneWPTracking_X.Integrator_CSTATE[0] = ARDroneWPTracking_B.Constant1[0];
    ARDroneWPTracking_X.Integrator_CSTATE[1] = ARDroneWPTracking_B.Constant1[1];
  }

  ARDroneWPTracking_B.Integrator[0] = ARDroneWPTracking_X.Integrator_CSTATE[0];
  ARDroneWPTracking_B.Integrator[1] = ARDroneWPTracking_X.Integrator_CSTATE[1];

  /* End of Integrator: '<S19>/Integrator' */
  if (rtmIsMajorTimeStep(ARDroneWPTracking_M)) {
    /* Gain: '<Root>/deg 2 rad' */
    ARDroneWPTracking_B.deg2rad[0] = ARDroneWPTracking_P.deg2rad_Gain *
      ARDroneWPTracking_B.TypeConversion1;
    ARDroneWPTracking_B.deg2rad[1] = ARDroneWPTracking_P.deg2rad_Gain *
      ARDroneWPTracking_B.TypeConversion2;
    ARDroneWPTracking_B.deg2rad[2] = ARDroneWPTracking_P.deg2rad_Gain *
      ARDroneWPTracking_B.yawOut;

    /* DataTypeConversion: '<S1>/Type Conversion5' */
    ARDroneWPTracking_B.TypeConversion5 = rtb_u;

    /* DataTypeConversion: '<S1>/Type Conversion6' */
    ARDroneWPTracking_B.TypeConversion6 = rtb_v;

    /* DataTypeConversion: '<S1>/Type Conversion7' */
    ARDroneWPTracking_B.TypeConversion7 = rtb_w;

    /* SignalConversion: '<S5>/TmpSignal ConversionAtTo WorkspaceInport1' */
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[0] =
      ARDroneWPTracking_B.deg2rad[0];
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[1] =
      ARDroneWPTracking_B.deg2rad[1];
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[2] =
      ARDroneWPTracking_B.deg2rad[2];
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[3] =
      ARDroneWPTracking_B.TypeConversion5;
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[4] =
      ARDroneWPTracking_B.TypeConversion6;
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[5] =
      ARDroneWPTracking_B.TypeConversion7;
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[6] =
      ARDroneWPTracking_B.Integrator[0];
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[7] =
      ARDroneWPTracking_B.Integrator[1];
    ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[8] =
      ARDroneWPTracking_B.TypeConversion4;

    /* Gain: '<S5>/deg 2 rad1' */
    ARDroneWPTracking_B.deg2rad1 = ARDroneWPTracking_P.deg2rad1_Gain *
      ARDroneWPTracking_B.deg2rad[2];

    /* MATLAB Function: '<S3>/Waypoint manager ' incorporates:
     *  Constant: '<S3>/Constant5'
     */
    /* MATLAB Function 'Guidance logic/Waypoint manager ': '<S18>:1' */
    /* '<S18>:1:7' */
    scale = 3.3121686421112381E-170;
    i_0 = ((int32_T)ARDroneWPTracking_DW.wpointer - 1) * 5;
    bytesLeft = fabs(ARDroneWPTracking_B.Integrator[0] -
                     ARDroneWPTracking_P.waypoints[i_0]);
    if (bytesLeft > 3.3121686421112381E-170) {
      rtb_hRef = 1.0;
      scale = bytesLeft;
    } else {
      t = bytesLeft / 3.3121686421112381E-170;
      rtb_hRef = t * t;
    }

    bytesLeft = fabs(ARDroneWPTracking_B.Integrator[1] -
                     ARDroneWPTracking_P.waypoints[i_0 + 1]);
    if (bytesLeft > scale) {
      t = scale / bytesLeft;
      rtb_hRef = rtb_hRef * t * t + 1.0;
      scale = bytesLeft;
    } else {
      t = bytesLeft / scale;
      rtb_hRef += t * t;
    }

    rtb_hRef = scale * sqrt(rtb_hRef);
    if ((rtb_hRef < 0.3) && (fabs(ARDroneWPTracking_B.TypeConversion4 -
          ARDroneWPTracking_P.waypoints[((int32_T)ARDroneWPTracking_DW.wpointer
           - 1) * 5 + 2]) < 0.3) && (fabs(ARDroneWPTracking_B.deg2rad[2] -
          ARDroneWPTracking_P.waypoints[((int32_T)ARDroneWPTracking_DW.wpointer
           - 1) * 5 + 3]) < 0.087266462599716474) &&
        (ARDroneWPTracking_DW.wpointer != 11.0)) {
      /* '<S18>:1:28' */
      /* '<S18>:1:29' */
      /* '<S18>:1:31' */
      if (ARDroneWPTracking_DW.t0 == 0.0) {
        /* '<S18>:1:33' */
        /* '<S18>:1:34' */
        ARDroneWPTracking_DW.t0 = ARDroneWPTracking_B.Clock1;
      } else {
        if ((ARDroneWPTracking_B.Clock1 - ARDroneWPTracking_DW.t0 >
             ARDroneWPTracking_P.waypoints[((int32_T)
              ARDroneWPTracking_DW.wpointer - 1) * 5 + 4]) &&
            (ARDroneWPTracking_DW.wpointer < 11.0)) {
          /* '<S18>:1:36' */
          /* '<S18>:1:38' */
          /* '<S18>:1:39' */
          ARDroneWPTracking_DW.wpointer++;

          /* '<S18>:1:40' */
          ARDroneWPTracking_DW.t0 = 0.0;
        }
      }
    }

    /* '<S18>:1:55' */
    i_0 = ((int32_T)ARDroneWPTracking_DW.wpointer - 1) * 5;
    rtb_hRef = ARDroneWPTracking_P.waypoints[i_0 + 2];

    /* '<S18>:1:56' */
    scale = ARDroneWPTracking_P.waypoints[i_0 + 3];

    /* '<S18>:1:57' */
    ARDroneWPTracking_B.XeRef = ARDroneWPTracking_P.waypoints[i_0];

    /* '<S18>:1:58' */
    ARDroneWPTracking_B.YeRef = ARDroneWPTracking_P.waypoints[i_0 + 1];

    /* End of MATLAB Function: '<S3>/Waypoint manager ' */
    /* '<S18>:1:59' */
  }

  /* Sum: '<S16>/Sum4' incorporates:
   *  MATLAB Function: '<S16>/Coordinate trnasformation  from inertial frame to body frame '
   */
  /* MATLAB Function 'Baseline Controller/Position controller/Coordinate trnasformation  from inertial frame to body frame ': '<S17>:1' */
  /* '<S17>:1:3' */
  /* '<S17>:1:4' */
  bytesLeft = ARDroneWPTracking_B.XeRef - ARDroneWPTracking_B.Integrator[0];
  t = ARDroneWPTracking_B.YeRef - ARDroneWPTracking_B.Integrator[1];

  /* MATLAB Function: '<S16>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
   *  MATLAB Function: '<S19>/Velocity from vehicle body frame  to inertial NED  frame'
   */
  t_tmp = cos(ARDroneWPTracking_B.deg2rad[2]);
  u0_tmp = sin(ARDroneWPTracking_B.deg2rad[2]);

  /* Gain: '<S15>/Gain1' incorporates:
   *  Gain: '<S16>/Gain3'
   *  MATLAB Function: '<S16>/Coordinate trnasformation  from inertial frame to body frame '
   *  Sum: '<S15>/Sum5'
   */
  u0 = ((-u0_tmp * bytesLeft + t_tmp * t) * ARDroneWPTracking_P.Gain3_Gain -
        ARDroneWPTracking_B.TypeConversion6) * ARDroneWPTracking_P.Gain1_Gain;

  /* Saturate: '<S1>/Saturation 1' */
  if (u0 > ARDroneWPTracking_P.Saturation1_UpperSat) {
    ARDroneWPTracking_B.Saturation1 = ARDroneWPTracking_P.Saturation1_UpperSat;
  } else if (u0 < ARDroneWPTracking_P.Saturation1_LowerSat) {
    ARDroneWPTracking_B.Saturation1 = ARDroneWPTracking_P.Saturation1_LowerSat;
  } else {
    ARDroneWPTracking_B.Saturation1 = u0;
  }

  /* End of Saturate: '<S1>/Saturation 1' */

  /* Gain: '<S12>/Gain' incorporates:
   *  Gain: '<S16>/Gain2'
   *  MATLAB Function: '<S16>/Coordinate trnasformation  from inertial frame to body frame '
   *  Sum: '<S12>/Sum2'
   */
  u0 = ((t_tmp * bytesLeft + u0_tmp * t) * ARDroneWPTracking_P.Gain2_Gain -
        ARDroneWPTracking_B.TypeConversion5) * ARDroneWPTracking_P.Gain_Gain;

  /* Saturate: '<S1>/Saturation 2' */
  if (u0 > ARDroneWPTracking_P.Saturation2_UpperSat) {
    ARDroneWPTracking_B.Saturation2 = ARDroneWPTracking_P.Saturation2_UpperSat;
  } else if (u0 < ARDroneWPTracking_P.Saturation2_LowerSat) {
    ARDroneWPTracking_B.Saturation2 = ARDroneWPTracking_P.Saturation2_LowerSat;
  } else {
    ARDroneWPTracking_B.Saturation2 = u0;
  }

  /* End of Saturate: '<S1>/Saturation 2' */
  if (rtmIsMajorTimeStep(ARDroneWPTracking_M)) {
    /* Gain: '<S13>/proportional control gain - yaw' incorporates:
     *  Sum: '<S13>/Sum1'
     */
    scale = (scale - ARDroneWPTracking_B.deg2rad[2]) *
      ARDroneWPTracking_P.proportionalcontrolgainyaw_Gain;

    /* Saturate: '<S1>/Saturation 3' */
    if (scale > ARDroneWPTracking_P.Saturation3_UpperSat) {
      scale = ARDroneWPTracking_P.Saturation3_UpperSat;
    } else {
      if (scale < ARDroneWPTracking_P.Saturation3_LowerSat) {
        scale = ARDroneWPTracking_P.Saturation3_LowerSat;
      }
    }

    /* End of Saturate: '<S1>/Saturation 3' */

    /* Gain: '<S14>/proportional control gain' incorporates:
     *  Sum: '<S14>/Sum3'
     */
    rtb_hRef = (rtb_hRef - ARDroneWPTracking_B.TypeConversion4) *
      ARDroneWPTracking_P.proportionalcontrolgain_Gain;

    /* Saturate: '<S1>/Saturation 4' */
    if (rtb_hRef > ARDroneWPTracking_P.Saturation4_UpperSat) {
      rtb_hRef = ARDroneWPTracking_P.Saturation4_UpperSat;
    } else {
      if (rtb_hRef < ARDroneWPTracking_P.Saturation4_LowerSat) {
        rtb_hRef = ARDroneWPTracking_P.Saturation4_LowerSat;
      }
    }

    /* End of Saturate: '<S1>/Saturation 4' */

    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Constant: '<Root>/land'
     *  Constant: '<Root>/take off'
     */
    if (ARDroneWPTracking_P.ManualSwitch1_CurrentSetting == 1) {
      bytesLeft = ARDroneWPTracking_P.land_Value;
    } else {
      bytesLeft = ARDroneWPTracking_P.takeoff_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */

    /* MATLAB Function: '<S8>/Drone state request' */
    /* MATLAB Function 'ARDrone Wi-Fi  Block/Subsystem1/Drone state request': '<S10>:1' */
    /* '<S10>:1:26' */
    /* '<S10>:1:32' */
    /* '<S10>:1:38' */
    /* '<S10>:1:42' */
    /* '<S10>:1:51' */
    /* '<S10>:1:54' */
    /* '<S10>:1:65' */
    /* '<S10>:1:72' */
    /* '<S10>:1:113' */
    /* '<S10>:1:16' */
    /* '<S10>:1:19' */
    /* '<S10>:1:22' */
    memset(&ARDroneWPTracking_B.dataControl[0], 0, 150U * sizeof(uint8_T));

    /* '<S10>:1:26' */
    loop_ub_0 = 0;
    guard1 = false;
    if (ARDroneWPTracking_DW.SequenceNumber <= 1.0) {
      /* '<S10>:1:29' */
      guard1 = true;
    } else {
      if (!rtIsInf(ARDroneWPTracking_DW.SequenceNumber)) {
        t = fmod(ARDroneWPTracking_DW.SequenceNumber, 100.0);
        if (t == 0.0) {
          t = 0.0;
        }
      } else {
        t = (rtNaN);
      }

      if (t == 0.0) {
        /* '<S10>:1:29' */
        guard1 = true;
      }
    }

    if (guard1) {
      /* '<S10>:1:30' */
      ARDroneWPTracking_DW.SequenceNumber++;

      /* '<S10>:1:31' */
      /* '<S10>:1:32' */
      ARDroneWPTracking_getString(ARDroneWPTracking_DW.SequenceNumber,
        strCmd_data, hex_size);
      loop_ub_0 = 41 + hex_size[1];
      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[i_0] = c[i_0];
      }

      loop_ub = hex_size[0] * hex_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&cmd_data[10], &strCmd_data[0], loop_ub * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 30; i_0++) {
        cmd_data[(i_0 + loop_ub) + 10] = d[i_0];
      }

      cmd_data[40 + loop_ub] = '\x0d';
    }

    /* '<S10>:1:36' */
    ARDroneWPTracking_DW.SequenceNumber++;

    /* '<S10>:1:37' */
    ARDroneWPTracking_getString(ARDroneWPTracking_DW.SequenceNumber, strCmd_data,
      hex_size);

    /* '<S10>:1:38' */
    aux = loop_ub_0 + 10;

    /* MATLAB Function: '<S8>/Drone state request' */
    m = hex_size[1];
    loop_ub_1 = aux + hex_size[1];
    loop_ub_0 = loop_ub_1 + 1;
    for (i_0 = 0; i_0 < 10; i_0++) {
      /* MATLAB Function: '<S8>/Drone state request' */
      cmd_data[(aux + i_0) - 10] = e[i_0];
    }

    for (i_0 = 0; i_0 < m; i_0++) {
      /* MATLAB Function: '<S8>/Drone state request' */
      cmd_data[aux + i_0] = strCmd_data[i_0];
    }

    /* MATLAB Function: '<S8>/Drone state request' */
    cmd_data[loop_ub_1] = '\x0d';

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/_'
     *  Constant: '<Root>/stop'
     */
    if (ARDroneWPTracking_P.ManualSwitch_CurrentSetting == 1) {
      t = ARDroneWPTracking_P._Value;
    } else {
      t = ARDroneWPTracking_P.stop_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* MATLAB Function: '<S8>/Drone state request' */
    if (t == 1.0) {
      /* '<S10>:1:41' */
      /* '<S10>:1:42' */
      loop_ub_0 = hex_size[1] + 18;
      for (i_0 = 0; i_0 < 7; i_0++) {
        cmd_data[i_0] = f[i_0];
      }

      loop_ub = hex_size[0] * hex_size[1];
      if (0 <= loop_ub - 1) {
        memcpy(&cmd_data[7], &strCmd_data[0], loop_ub * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[(i_0 + hex_size[0] * hex_size[1]) + 7] = g[i_0];
      }

      cmd_data[17 + hex_size[0] * hex_size[1]] = '\x0d';
    } else if ((ARDroneWPTracking_DW.SequenceNumber > 20.0) &&
               (ARDroneWPTracking_DW.SequenceNumber < 22.0)) {
      /* '<S10>:1:46' */
      /* '<S10>:1:49' */
      ARDroneWPTracking_DW.SequenceNumber = 22.0;

      /* '<S10>:1:50' */
      /* '<S10>:1:51' */
      ARDroneWPTracking_getString(22.0, strCmd_data, hex_size);
      loop_ub_1 = loop_ub_0 + hex_size[1];
      m = loop_ub_1 + 10;
      if (0 <= loop_ub_0 - 1) {
        memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
      }

      for (i_0 = 0; i_0 < 9; i_0++) {
        cmd_data_0[i_0 + loop_ub_0] = i[i_0];
      }

      loop_ub = hex_size[1];
      for (i_0 = 0; i_0 < loop_ub; i_0++) {
        cmd_data_0[(i_0 + loop_ub_0) + 9] = strCmd_data[hex_size[0] * i_0];
      }

      cmd_data_0[loop_ub_1 + 9] = '\x0d';
      loop_ub_0 = m;
      if (0 <= m - 1) {
        memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
      }
    } else if ((ARDroneWPTracking_DW.SequenceNumber >= 22.0) &&
               (ARDroneWPTracking_DW.SequenceNumber < 25.0)) {
      /* '<S10>:1:53' */
      /* '<S10>:1:54' */
      aux = loop_ub_0 + 10;
      m = hex_size[1];
      loop_ub_1 = aux + hex_size[1];
      loop_ub_0 = loop_ub_1 + 31;
      for (i_0 = 0; i_0 < 10; i_0++) {
        cmd_data[(aux + i_0) - 10] = c[i_0];
      }

      for (i_0 = 0; i_0 < m; i_0++) {
        cmd_data[aux + i_0] = strCmd_data[i_0];
      }

      for (i_0 = 0; i_0 < 30; i_0++) {
        cmd_data[(aux + i_0) + m] = h[i_0];
      }

      cmd_data[loop_ub_1 + 30] = '\x0d';
    } else {
      if (ARDroneWPTracking_DW.SequenceNumber >= 25.0) {
        /* '<S10>:1:57' */
        if (bytesLeft == 1.0) {
          /* '<S10>:1:59' */
          if (rtb_status[31] == 0) {
            /* '<S10>:1:61' */
            /* '<S10>:1:63' */
            ARDroneWPTracking_DW.SequenceNumber++;

            /* '<S10>:1:64' */
            /* '<S10>:1:65' */
            ARDroneWPTracking_getString(ARDroneWPTracking_DW.SequenceNumber,
              strCmd_data, hex_size);
            loop_ub_1 = loop_ub_0 + hex_size[1];
            m = loop_ub_1 + 18;
            if (0 <= loop_ub_0 - 1) {
              memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
            }

            for (i_0 = 0; i_0 < 7; i_0++) {
              cmd_data_0[i_0 + loop_ub_0] = f[i_0];
            }

            loop_ub = hex_size[1];
            for (i_0 = 0; i_0 < loop_ub; i_0++) {
              cmd_data_0[(i_0 + loop_ub_0) + 7] = strCmd_data[hex_size[0] * i_0];
            }

            for (i_0 = 0; i_0 < 10; i_0++) {
              cmd_data_0[((i_0 + loop_ub_0) + hex_size[1]) + 7] = j[i_0];
            }

            cmd_data_0[loop_ub_1 + 17] = '\x0d';
            loop_ub_0 = m;
            if (0 <= m - 1) {
              memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
            }
          } else {
            if ((rtb_status[31] == 1) && (bytesToRead == 1.0)) {
              /* '<S10>:1:67' */
              /* '<S10>:1:69' */
              ARDroneWPTracking_DW.SequenceNumber++;

              /* '<S10>:1:70' */
              /* '<S10>:1:72' */
              ARDroneWPTracking_getString(ARDroneWPTracking_DW.SequenceNumber,
                strCmd_data, hex_size);
              loop_ub_1 = loop_ub_0 + hex_size[1];
              m = loop_ub_1 + 11;
              if (0 <= loop_ub_0 - 1) {
                memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
              }

              for (i_0 = 0; i_0 < 8; i_0++) {
                cmd_data_0[i_0 + loop_ub_0] = l[i_0];
              }

              loop_ub = hex_size[1];
              for (i_0 = 0; i_0 < loop_ub; i_0++) {
                cmd_data_0[(i_0 + loop_ub_0) + 8] = strCmd_data[hex_size[0] *
                  i_0];
              }

              cmd_data_0[loop_ub_1 + 8] = ',';
              cmd_data_0[loop_ub_1 + 9] = '1';
              cmd_data_0[loop_ub_1 + 10] = ',';
              if (0 <= m - 1) {
                memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
              }

              /* '<S10>:1:74' */
              aux = ARDroneWPTracking_float2IEEE754
                (ARDroneWPTracking_B.Saturation1);

              /* '<S10>:1:75' */
              ARDroneWPTracking_getString(fabs((real_T)aux), strCmd_data,
                hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (ARDroneWPTracking_B.Saturation1 < 0.0) {
                /* '<S10>:1:76' */
                /* '<S10>:1:77' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S10>:1:79' */
              loop_ub_1 = m + strAux_size_idx_1;
              loop_ub_0 = loop_ub_1 + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[m + i_0] = strAux_data[i_0];
              }

              cmd_data[loop_ub_1] = ',';

              /* '<S10>:1:81' */
              aux = ARDroneWPTracking_float2IEEE754
                (ARDroneWPTracking_B.Saturation2);

              /* '<S10>:1:82' */
              ARDroneWPTracking_getString(fabs((real_T)aux), strCmd_data,
                hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (ARDroneWPTracking_B.Saturation2 < 0.0) {
                /* '<S10>:1:83' */
                /* '<S10>:1:84' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                loop_ub = hex_size[0] * hex_size[1];
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S10>:1:86' */
              aux = loop_ub_0;
              loop_ub_0 = (loop_ub_0 + strAux_size_idx_1) + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + strAux_size_idx_1] = ',';

              /* '<S10>:1:88' */
              /* '<S10>:1:89' */
              ARDroneWPTracking_getString(fabs((real_T)
                ARDroneWPTracking_float2IEEE754(rtb_hRef)), strCmd_data,
                hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (rtb_hRef < 0.0) {
                /* '<S10>:1:90' */
                /* '<S10>:1:91' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                loop_ub = hex_size[0] * hex_size[1];
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S10>:1:93' */
              aux = loop_ub_0;
              loop_ub_0 = (loop_ub_0 + strAux_size_idx_1) + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + strAux_size_idx_1] = ',';

              /* '<S10>:1:96' */
              /* '<S10>:1:97' */
              ARDroneWPTracking_getString(fabs((real_T)
                ARDroneWPTracking_float2IEEE754(scale)), strCmd_data, hex_size);
              strAux_size_idx_1 = hex_size[1];
              loop_ub = hex_size[0] * hex_size[1];
              if (0 <= loop_ub - 1) {
                memcpy(&strAux_data[0], &strCmd_data[0], loop_ub * sizeof(char_T));
              }

              if (scale < 0.0) {
                /* '<S10>:1:98' */
                /* '<S10>:1:99' */
                /* '<S10>:1:100' */
                strAux_size_idx_1 = 1 + hex_size[1];
                strAux_data[0] = '-';
                loop_ub = hex_size[0] * hex_size[1];
                if (0 <= loop_ub - 1) {
                  memcpy(&strAux_data[1], &strCmd_data[0], loop_ub * sizeof
                         (char_T));
                }
              }

              /* '<S10>:1:102' */
              aux = loop_ub_0;
              loop_ub_0 = (loop_ub_0 + strAux_size_idx_1) + 1;
              for (i_0 = 0; i_0 < strAux_size_idx_1; i_0++) {
                cmd_data[aux + i_0] = strAux_data[i_0];
              }

              cmd_data[aux + strAux_size_idx_1] = '\x0d';
            }
          }
        } else {
          if ((bytesLeft == 0.0) && (rtb_status[31] == 1)) {
            /* '<S10>:1:108' */
            /* '<S10>:1:110' */
            /* '<S10>:1:111' */
            ARDroneWPTracking_DW.SequenceNumber++;

            /* '<S10>:1:112' */
            /* '<S10>:1:113' */
            ARDroneWPTracking_getString(ARDroneWPTracking_DW.SequenceNumber,
              strCmd_data, hex_size);
            loop_ub_1 = loop_ub_0 + hex_size[1];
            m = loop_ub_1 + 18;
            if (0 <= loop_ub_0 - 1) {
              memcpy(&cmd_data_0[0], &cmd_data[0], loop_ub_0 * sizeof(char_T));
            }

            for (i_0 = 0; i_0 < 7; i_0++) {
              cmd_data_0[i_0 + loop_ub_0] = f[i_0];
            }

            loop_ub = hex_size[1];
            for (i_0 = 0; i_0 < loop_ub; i_0++) {
              cmd_data_0[(i_0 + loop_ub_0) + 7] = strCmd_data[hex_size[0] * i_0];
            }

            for (i_0 = 0; i_0 < 10; i_0++) {
              cmd_data_0[((i_0 + loop_ub_0) + hex_size[1]) + 7] = k[i_0];
            }

            cmd_data_0[loop_ub_1 + 17] = '\x0d';
            loop_ub_0 = m;
            if (0 <= m - 1) {
              memcpy(&cmd_data[0], &cmd_data_0[0], m * sizeof(char_T));
            }
          }
        }
      }
    }

    /* '<S10>:1:126' */
    for (i_0 = 0; i_0 < loop_ub_0; i_0++) {
      ARDroneWPTracking_B.dataControl[i_0] = (uint8_T)cmd_data[i_0];
    }

    /* '<S10>:1:131' */
    ARDroneWPTracking_B.isFlying = rtb_status[31];

    /* S-Function (sldrtpo): '<S8>/Packet Output' */
    /* S-Function Block: <S8>/Packet Output */

    /* no code required */

    /* RateTransition: '<S11>/Rate Transition' incorporates:
     *  Constant: '<S11>/Constant'
     */
    if (ARDroneWPTracking_M->Timing.RateInteraction.TID1_2) {
      ARDroneWPTracking_B.RateTransition[0] =
        ARDroneWPTracking_P.Constant_Value[0];
      ARDroneWPTracking_B.RateTransition[1] =
        ARDroneWPTracking_P.Constant_Value[1];
    }

    /* End of RateTransition: '<S11>/Rate Transition' */

    /* MATLAB Function: '<S19>/Velocity from vehicle body frame  to inertial NED  frame' incorporates:
     *  SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'Position estimation Important:This block provides an  inaccurate extimation of position  based on  velocity information. /Position estimation/Velocity from vehicle body frame  to inertial NED  frame': '<S20>:1' */
    /* '<S20>:1:3' */
    /* '<S20>:1:4' */
    ARDroneWPTracking_B.Vel_xy[0] = 0.0;
    ARDroneWPTracking_B.Vel_xy[0] += t_tmp * ARDroneWPTracking_B.TypeConversion5;
    ARDroneWPTracking_B.Vel_xy[0] += -sin(ARDroneWPTracking_B.deg2rad[2]) *
      ARDroneWPTracking_B.TypeConversion6;
    ARDroneWPTracking_B.Vel_xy[1] = 0.0;
    ARDroneWPTracking_B.Vel_xy[1] += u0_tmp *
      ARDroneWPTracking_B.TypeConversion5;
    ARDroneWPTracking_B.Vel_xy[1] += t_tmp * ARDroneWPTracking_B.TypeConversion6;
  }
}

/* Model update function for TID0 */
void ARDroneWPTracking_update0(void)   /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S19>/Integrator' */
  ARDroneWPTracking_DW.Integrator_IWORK = 0;
  if (rtmIsMajorTimeStep(ARDroneWPTracking_M)) {
    /* Update for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
    ARDroneWPTracking_DW.UnitDelaytoavoidalgebraicloop_DSTATE =
      ARDroneWPTracking_B.isFlying;

    /* Update for S-Function (sldrtpo): '<S8>/Packet Output' */

    /* S-Function Block: <S8>/Packet Output */
    {
      uint8_T outdata[150U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        int_T i1;
        const uint8_T *u0 = &ARDroneWPTracking_B.dataControl[0];
        for (i1=0; i1 < 150; i1++) {
          {
            uint8_T pktout = u0[i1];
            *outdp.p_uint8_T++ = pktout;
          }
        }
      }

      RTBIO_DriverIO(1, STREAMOUTPUT, IOWRITE, 150U,
                     &ARDroneWPTracking_P.PacketOutput_PacketID, (double*)
                     outdata, NULL);
    }
  }

  if (rtmIsMajorTimeStep(ARDroneWPTracking_M)) {
    rt_ertODEUpdateContinuousStates(&ARDroneWPTracking_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneWPTracking_M->Timing.clockTick0)) {
    ++ARDroneWPTracking_M->Timing.clockTickH0;
  }

  ARDroneWPTracking_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ARDroneWPTracking_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneWPTracking_M->Timing.clockTick1)) {
    ++ARDroneWPTracking_M->Timing.clockTickH1;
  }

  ARDroneWPTracking_M->Timing.t[1] = ARDroneWPTracking_M->Timing.clockTick1 *
    ARDroneWPTracking_M->Timing.stepSize1 +
    ARDroneWPTracking_M->Timing.clockTickH1 *
    ARDroneWPTracking_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void ARDroneWPTracking_derivatives(void)
{
  XDot_ARDroneWPTracking_T *_rtXdot;
  _rtXdot = ((XDot_ARDroneWPTracking_T *) ARDroneWPTracking_M->derivs);

  /* Derivatives for Integrator: '<S19>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ARDroneWPTracking_B.Vel_xy[0];
  _rtXdot->Integrator_CSTATE[1] = ARDroneWPTracking_B.Vel_xy[1];
}

/* Model output function for TID2 */
void ARDroneWPTracking_output2(void)   /* Sample time: [0.65s, 0.0s] */
{
  /* S-Function (sldrtpo): '<S11>/Packet Output1' */
  /* S-Function Block: <S11>/Packet Output1 */

  /* no code required */
}

/* Model update function for TID2 */
void ARDroneWPTracking_update2(void)   /* Sample time: [0.65s, 0.0s] */
{
  /* Update for S-Function (sldrtpo): '<S11>/Packet Output1' */

  /* S-Function Block: <S11>/Packet Output1 */
  {
    uint8_T outdata[2U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      uint8_T pktout = ARDroneWPTracking_B.RateTransition[0];
      *outdp.p_uint8_T++ = pktout;
    }

    {
      uint8_T pktout = ARDroneWPTracking_B.RateTransition[1];
      *outdp.p_uint8_T++ = pktout;
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 2U,
                   &ARDroneWPTracking_P.PacketOutput1_PacketID, (double*)
                   outdata, NULL);
  }

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ARDroneWPTracking_M->Timing.clockTick2)) {
    ++ARDroneWPTracking_M->Timing.clockTickH2;
  }

  ARDroneWPTracking_M->Timing.t[2] = ARDroneWPTracking_M->Timing.clockTick2 *
    ARDroneWPTracking_M->Timing.stepSize2 +
    ARDroneWPTracking_M->Timing.clockTickH2 *
    ARDroneWPTracking_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void ARDroneWPTracking_output(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneWPTracking_output0();
    break;

   case 2 :
    ARDroneWPTracking_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void ARDroneWPTracking_update(int_T tid)
{
  switch (tid) {
   case 0 :
    ARDroneWPTracking_update0();
    break;

   case 2 :
    ARDroneWPTracking_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void ARDroneWPTracking_initialize(void)
{
  /* Start for Constant: '<S19>/Constant1' */
  ARDroneWPTracking_B.Constant1[0] = ARDroneWPTracking_P.Constant1_Value[0];
  ARDroneWPTracking_B.Constant1[1] = ARDroneWPTracking_P.Constant1_Value[1];

  /* Start for S-Function (sldrtpo): '<S8>/Packet Output' */

  /* S-Function Block: <S8>/Packet Output */
  /* no initial value should be set */

  /* Start for S-Function (sldrtpo): '<S11>/Packet Output1' */

  /* S-Function Block: <S11>/Packet Output1 */
  /* no initial value should be set */

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay to avoid algebraic loop' */
  ARDroneWPTracking_DW.UnitDelaytoavoidalgebraicloop_DSTATE =
    ARDroneWPTracking_P.UnitDelaytoavoidalgebraicloop_InitialCondition;

  /* InitializeConditions for Integrator: '<S19>/Integrator' */
  if (rtmIsFirstInitCond(ARDroneWPTracking_M)) {
    ARDroneWPTracking_X.Integrator_CSTATE[0] = 0.0;
    ARDroneWPTracking_X.Integrator_CSTATE[1] = 0.0;
  }

  ARDroneWPTracking_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S19>/Integrator' */

  /* SystemInitialize for MATLAB Function: '<S1>/Data synchronization ' */
  memset(&ARDroneWPTracking_DW.buffer[0], 0, sizeof(uint8_T) << 10U);
  ARDroneWPTracking_DW.countBuffer = 0.0;
  ARDroneWPTracking_DW.count = 0.0;
  ARDroneWPTracking_DW.countHeader = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/ARDrone data decoding' */
  ARDroneWPTracking_DW.hPrev = 0.0;

  /* SystemInitialize for MATLAB Function: '<S1>/Data synchronization ' */
  memset(&ARDroneWPTracking_DW.frame[0], 0, 496U * sizeof(uint8_T));
  memset(&ARDroneWPTracking_DW.lastFrame[0], 0, 496U * sizeof(uint8_T));

  /* SystemInitialize for MATLAB Function: '<S1>/ARDrone data decoding' */
  memset(&ARDroneWPTracking_DW.dataPrev[0], 0, 496U * sizeof(uint8_T));

  /* SystemInitialize for MATLAB Function: '<S1>/This block sets the heading angle to zero when the  commands from the Simulink controller are enabled. ' */
  ARDroneWPTracking_DW.yaw0 = 0.0;
  ARDroneWPTracking_DW.mode = 0.0;

  /* SystemInitialize for MATLAB Function: '<S3>/Waypoint manager ' */
  ARDroneWPTracking_DW.wpointer = 1.0;
  ARDroneWPTracking_DW.t0 = 0.0;

  /* SystemInitialize for MATLAB Function: '<S8>/Drone state request' */
  ARDroneWPTracking_DW.SequenceNumber = 1.0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ARDroneWPTracking_M)) {
    rtmSetFirstInitCond(ARDroneWPTracking_M, 0);
  }
}

/* Model terminate function */
void ARDroneWPTracking_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<S8>/Packet Output' */

  /* S-Function Block: <S8>/Packet Output */
  /* no initial value should be set */

  /* Terminate for S-Function (sldrtpo): '<S11>/Packet Output1' */

  /* S-Function Block: <S11>/Packet Output1 */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  ARDroneWPTracking_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  ARDroneWPTracking_update(tid);
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
  ARDroneWPTracking_initialize();
}

void MdlTerminate(void)
{
  ARDroneWPTracking_terminate();
}

/* Registration function */
RT_MODEL_ARDroneWPTracking_T *ARDroneWPTracking(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ARDroneWPTracking_M, 0,
                sizeof(RT_MODEL_ARDroneWPTracking_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ARDroneWPTracking_M->solverInfo,
                          &ARDroneWPTracking_M->Timing.simTimeStep);
    rtsiSetTPtr(&ARDroneWPTracking_M->solverInfo, &rtmGetTPtr
                (ARDroneWPTracking_M));
    rtsiSetStepSizePtr(&ARDroneWPTracking_M->solverInfo,
                       &ARDroneWPTracking_M->Timing.stepSize0);
    rtsiSetdXPtr(&ARDroneWPTracking_M->solverInfo, &ARDroneWPTracking_M->derivs);
    rtsiSetContStatesPtr(&ARDroneWPTracking_M->solverInfo, (real_T **)
                         &ARDroneWPTracking_M->contStates);
    rtsiSetNumContStatesPtr(&ARDroneWPTracking_M->solverInfo,
      &ARDroneWPTracking_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ARDroneWPTracking_M->solverInfo,
      &ARDroneWPTracking_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ARDroneWPTracking_M->solverInfo,
      &ARDroneWPTracking_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ARDroneWPTracking_M->solverInfo,
      &ARDroneWPTracking_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ARDroneWPTracking_M->solverInfo, (&rtmGetErrorStatus
      (ARDroneWPTracking_M)));
    rtsiSetRTModelPtr(&ARDroneWPTracking_M->solverInfo, ARDroneWPTracking_M);
  }

  rtsiSetSimTimeStep(&ARDroneWPTracking_M->solverInfo, MAJOR_TIME_STEP);
  ARDroneWPTracking_M->intgData.f[0] = ARDroneWPTracking_M->odeF[0];
  ARDroneWPTracking_M->contStates = ((real_T *) &ARDroneWPTracking_X);
  rtsiSetSolverData(&ARDroneWPTracking_M->solverInfo, (void *)
                    &ARDroneWPTracking_M->intgData);
  rtsiSetSolverName(&ARDroneWPTracking_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ARDroneWPTracking_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    ARDroneWPTracking_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ARDroneWPTracking_M->Timing.sampleTimes =
      (&ARDroneWPTracking_M->Timing.sampleTimesArray[0]);
    ARDroneWPTracking_M->Timing.offsetTimes =
      (&ARDroneWPTracking_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ARDroneWPTracking_M->Timing.sampleTimes[0] = (0.0);
    ARDroneWPTracking_M->Timing.sampleTimes[1] = (0.065);
    ARDroneWPTracking_M->Timing.sampleTimes[2] = (0.65);

    /* task offsets */
    ARDroneWPTracking_M->Timing.offsetTimes[0] = (0.0);
    ARDroneWPTracking_M->Timing.offsetTimes[1] = (0.0);
    ARDroneWPTracking_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(ARDroneWPTracking_M, &ARDroneWPTracking_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ARDroneWPTracking_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      ARDroneWPTracking_M->Timing.perTaskSampleHitsArray;
    ARDroneWPTracking_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    ARDroneWPTracking_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ARDroneWPTracking_M, -1);
  ARDroneWPTracking_M->Timing.stepSize0 = 0.065;
  ARDroneWPTracking_M->Timing.stepSize1 = 0.065;
  ARDroneWPTracking_M->Timing.stepSize2 = 0.65;
  rtmSetFirstInitCond(ARDroneWPTracking_M, 1);

  /* External mode info */
  ARDroneWPTracking_M->Sizes.checksums[0] = (4041979730U);
  ARDroneWPTracking_M->Sizes.checksums[1] = (2975290993U);
  ARDroneWPTracking_M->Sizes.checksums[2] = (1861852599U);
  ARDroneWPTracking_M->Sizes.checksums[3] = (3415877413U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
    ARDroneWPTracking_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ARDroneWPTracking_M->extModeInfo,
      &ARDroneWPTracking_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ARDroneWPTracking_M->extModeInfo,
                        ARDroneWPTracking_M->Sizes.checksums);
    rteiSetTPtr(ARDroneWPTracking_M->extModeInfo, rtmGetTPtr(ARDroneWPTracking_M));
  }

  ARDroneWPTracking_M->solverInfoPtr = (&ARDroneWPTracking_M->solverInfo);
  ARDroneWPTracking_M->Timing.stepSize = (0.065);
  rtsiSetFixedStepSize(&ARDroneWPTracking_M->solverInfo, 0.065);
  rtsiSetSolverMode(&ARDroneWPTracking_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  ARDroneWPTracking_M->blockIO = ((void *) &ARDroneWPTracking_B);
  (void) memset(((void *) &ARDroneWPTracking_B), 0,
                sizeof(B_ARDroneWPTracking_T));

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      ARDroneWPTracking_B.TmpSignalConversionAtToWorkspaceInport1[i] = 0.0;
    }

    ARDroneWPTracking_B.TypeConversion = 0.0;
    ARDroneWPTracking_B.TypeConversion1 = 0.0;
    ARDroneWPTracking_B.TypeConversion2 = 0.0;
    ARDroneWPTracking_B.Clock1 = 0.0;
    ARDroneWPTracking_B.TypeConversion4 = 0.0;
    ARDroneWPTracking_B.Constant1[0] = 0.0;
    ARDroneWPTracking_B.Constant1[1] = 0.0;
    ARDroneWPTracking_B.Integrator[0] = 0.0;
    ARDroneWPTracking_B.Integrator[1] = 0.0;
    ARDroneWPTracking_B.deg2rad[0] = 0.0;
    ARDroneWPTracking_B.deg2rad[1] = 0.0;
    ARDroneWPTracking_B.deg2rad[2] = 0.0;
    ARDroneWPTracking_B.TypeConversion5 = 0.0;
    ARDroneWPTracking_B.TypeConversion6 = 0.0;
    ARDroneWPTracking_B.TypeConversion7 = 0.0;
    ARDroneWPTracking_B.deg2rad1 = 0.0;
    ARDroneWPTracking_B.Saturation1 = 0.0;
    ARDroneWPTracking_B.Saturation2 = 0.0;
    ARDroneWPTracking_B.Vel_xy[0] = 0.0;
    ARDroneWPTracking_B.Vel_xy[1] = 0.0;
    ARDroneWPTracking_B.XeRef = 0.0;
    ARDroneWPTracking_B.YeRef = 0.0;
    ARDroneWPTracking_B.yawOut = 0.0;
    ARDroneWPTracking_B.isFlying = 0.0;
  }

  /* parameters */
  ARDroneWPTracking_M->defaultParam = ((real_T *)&ARDroneWPTracking_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ARDroneWPTracking_X;
    ARDroneWPTracking_M->contStates = (x);
    (void) memset((void *)&ARDroneWPTracking_X, 0,
                  sizeof(X_ARDroneWPTracking_T));
  }

  /* states (dwork) */
  ARDroneWPTracking_M->dwork = ((void *) &ARDroneWPTracking_DW);
  (void) memset((void *)&ARDroneWPTracking_DW, 0,
                sizeof(DW_ARDroneWPTracking_T));
  ARDroneWPTracking_DW.UnitDelaytoavoidalgebraicloop_DSTATE = 0.0;
  ARDroneWPTracking_DW.wpointer = 0.0;
  ARDroneWPTracking_DW.t0 = 0.0;
  ARDroneWPTracking_DW.yaw0 = 0.0;
  ARDroneWPTracking_DW.mode = 0.0;
  ARDroneWPTracking_DW.SequenceNumber = 0.0;
  ARDroneWPTracking_DW.count = 0.0;
  ARDroneWPTracking_DW.countHeader = 0.0;
  ARDroneWPTracking_DW.countBuffer = 0.0;
  ARDroneWPTracking_DW.hPrev = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ARDroneWPTracking_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ARDroneWPTracking_M->Sizes.numContStates = (2);/* Number of continuous states */
  ARDroneWPTracking_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ARDroneWPTracking_M->Sizes.numY = (0);/* Number of model outputs */
  ARDroneWPTracking_M->Sizes.numU = (0);/* Number of model inputs */
  ARDroneWPTracking_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ARDroneWPTracking_M->Sizes.numSampTimes = (3);/* Number of sample times */
  ARDroneWPTracking_M->Sizes.numBlocks = (75);/* Number of blocks */
  ARDroneWPTracking_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  ARDroneWPTracking_M->Sizes.numBlockPrms = (94);/* Sum of parameter "widths" */
  return ARDroneWPTracking_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
