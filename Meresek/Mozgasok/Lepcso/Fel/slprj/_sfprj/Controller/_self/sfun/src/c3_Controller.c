/* Include files */

#include "Controller_sfun.h"
#include "c3_Controller.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Controller_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[8] = { "deg", "sx", "sy", "nargin",
  "nargout", "ex", "ey", "y" };

/* Function Declarations */
static void initialize_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance);
static void initialize_params_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance);
static void enable_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance);
static void disable_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_Controller(SFc3_ControllerInstanceStruct *
  chartInstance);
static void set_sim_state_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance);
static void sf_gateway_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance);
static void mdl_start_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance);
static void initSimStructsc3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_ControllerInstanceStruct *chartInstance,
  const mxArray *c3_b_y, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_ControllerInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Controller, const char_T
  *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_ControllerInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_ControllerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_Controller(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_Controller = 0U;
}

static void initialize_params_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_Controller(SFc3_ControllerInstanceStruct *
  chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_b_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(2, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_y;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_Controller;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 1, c3_d_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("y", c3_u, 0)), "y");
  chartInstance->c3_is_active_c3_Controller = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c3_Controller", c3_u, 1)),
     "is_active_c3_Controller");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Controller(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_ex;
  real_T c3_b_ey;
  uint32_T c3_debug_family_var_map[8];
  real_T c3_deg;
  real_T c3_sx;
  real_T c3_sy;
  real_T c3_nargin = 2.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_y;
  real_T c3_A;
  real_T c3_B;
  real_T c3_x;
  real_T c3_c_y;
  real_T c3_b_x;
  real_T c3_d_y;
  real_T c3_e_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_angleInRadians;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_l_x;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ey, 1U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ex, 0U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *chartInstance->c3_ex;
  c3_b_hoistedGlobal = *chartInstance->c3_ey;
  c3_b_ex = c3_hoistedGlobal;
  c3_b_ey = c3_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_deg, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sx, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sy, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_ex, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_ey, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_y, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_A = c3_b_ey;
  c3_B = c3_b_ex;
  c3_x = c3_A;
  c3_c_y = c3_B;
  c3_b_x = c3_x;
  c3_d_y = c3_c_y;
  c3_e_y = c3_b_x / c3_d_y;
  c3_c_x = c3_e_y;
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarAtan(c3_d_x);
  c3_angleInRadians = c3_d_x;
  c3_deg = 57.295779513082323 * c3_angleInRadians;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_e_x = c3_b_ex;
  c3_sx = c3_e_x;
  c3_f_x = c3_sx;
  c3_sx = c3_f_x;
  c3_g_x = c3_sx;
  c3_sx = c3_g_x;
  c3_h_x = c3_sx;
  c3_sx = c3_h_x;
  c3_sx = muDoubleScalarSign(c3_sx);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_i_x = c3_b_ey;
  c3_sy = c3_i_x;
  c3_j_x = c3_sy;
  c3_sy = c3_j_x;
  c3_k_x = c3_sy;
  c3_sy = c3_k_x;
  c3_l_x = c3_sy;
  c3_sy = c3_l_x;
  c3_sy = muDoubleScalarSign(c3_sy);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_b_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c3_sx, 1.0, -1, 0U,
        c3_sx == 1.0)) && CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1,
        c3_sy, 1.0, -1, 0U, c3_sy == 1.0))) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 0, true);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
    c3_b_y = c3_deg;
  } else {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c3_sx, -1.0, -1, 0U,
        c3_sx == -1.0)) && CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3,
        c3_sy, -1.0, -1, 0U, c3_sy == -1.0))) {
    CV_EML_MCDC(0, 1, 1, true);
    CV_EML_IF(0, 1, 1, true);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
    c3_b_y = -90.0 - c3_deg;
  } else {
    CV_EML_MCDC(0, 1, 1, false);
    CV_EML_IF(0, 1, 1, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  if (CV_EML_COND(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c3_sx, 1.0, -1, 0U,
        c3_sx == 1.0)) && CV_EML_COND(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5,
        c3_sy, -1.0, -1, 0U, c3_sy == -1.0))) {
    CV_EML_MCDC(0, 1, 2, true);
    CV_EML_IF(0, 1, 2, true);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
    c3_b_y = 90.0 - c3_deg;
  } else {
    CV_EML_MCDC(0, 1, 2, false);
    CV_EML_IF(0, 1, 2, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  if (CV_EML_COND(0, 1, 6, CV_RELATIONAL_EVAL(4U, 0U, 6, c3_sx, -1.0, -1, 0U,
        c3_sx == -1.0)) && CV_EML_COND(0, 1, 7, CV_RELATIONAL_EVAL(4U, 0U, 7,
        c3_sy, 1.0, -1, 0U, c3_sy == 1.0))) {
    CV_EML_MCDC(0, 1, 3, true);
    CV_EML_IF(0, 1, 3, true);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
    c3_b_y = c3_deg;
  } else {
    CV_EML_MCDC(0, 1, 3, false);
    CV_EML_IF(0, 1, 3, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_y = c3_b_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ControllerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_y, 2U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
}

static void mdl_start_c3_Controller(SFc3_ControllerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc3_Controller(SFc3_ControllerInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_ControllerInstanceStruct *chartInstance;
  chartInstance = (SFc3_ControllerInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_ControllerInstanceStruct *chartInstance,
  const mxArray *c3_b_y, const char_T *c3_identifier)
{
  real_T c3_c_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId);
  sf_mex_destroy(&c3_b_y);
  return c3_c_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_ControllerInstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_y;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_c_y;
  SFc3_ControllerInstanceStruct *chartInstance;
  chartInstance = (SFc3_ControllerInstanceStruct *)chartInstanceVoid;
  c3_b_y = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_y), &c3_thisId);
  sf_mex_destroy(&c3_b_y);
  *(real_T *)c3_outData = c3_c_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Controller_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_ControllerInstanceStruct *chartInstance;
  chartInstance = (SFc3_ControllerInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_b_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_b_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_b_y;
  SFc3_ControllerInstanceStruct *chartInstance;
  chartInstance = (SFc3_ControllerInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_Controller, const char_T
  *c3_identifier)
{
  uint8_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_Controller), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_Controller);
  return c3_b_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_ControllerInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void init_dsm_address_info(SFc3_ControllerInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_ControllerInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_ex = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c3_y = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c3_ey = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_Controller_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2538256140U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(635191163U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1730974240U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2245433261U);
}

mxArray* sf_c3_Controller_get_post_codegen_info(void);
mxArray *sf_c3_Controller_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NYPHhJQvQcWMU6xc8nuhcB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_Controller_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Controller_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Controller_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_Controller_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Controller_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_Controller(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c3_Controller\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Controller_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ControllerInstanceStruct *chartInstance =
      (SFc3_ControllerInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ControllerMachineNumber_,
           3,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ControllerMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ControllerMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ControllerMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"ex");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ey");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,4,0,0,0,0,0,8,4);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,257);
        _SFD_CV_INIT_EML_IF(0,1,0,89,108,-1,125);
        _SFD_CV_INIT_EML_IF(0,1,1,127,148,-1,171);
        _SFD_CV_INIT_EML_IF(0,1,2,173,193,-1,215);
        _SFD_CV_INIT_EML_IF(0,1,3,217,237,-1,254);

        {
          static int condStart[] = { 92, 100 };

          static int condEnd[] = { 97, 107 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,92,107,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 130, 139 };

          static int condEnd[] = { 136, 147 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,130,147,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 176, 184 };

          static int condEnd[] = { 181, 192 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,176,192,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 220, 229 };

          static int condEnd[] = { 226, 236 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,220,236,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,92,97,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,100,107,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,130,136,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,139,147,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,176,181,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,184,192,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,6,220,226,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,7,229,236,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ControllerMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ControllerInstanceStruct *chartInstance =
      (SFc3_ControllerInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c3_ex);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c3_y);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_ey);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "skGzYrCk3Hw56QGH6EVzqKG";
}

static void sf_opaque_initialize_c3_Controller(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ControllerInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c3_Controller((SFc3_ControllerInstanceStruct*)
    chartInstanceVar);
  initialize_c3_Controller((SFc3_ControllerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Controller(void *chartInstanceVar)
{
  enable_c3_Controller((SFc3_ControllerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Controller(void *chartInstanceVar)
{
  disable_c3_Controller((SFc3_ControllerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Controller(void *chartInstanceVar)
{
  sf_gateway_c3_Controller((SFc3_ControllerInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Controller(SimStruct* S)
{
  return get_sim_state_c3_Controller((SFc3_ControllerInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Controller(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c3_Controller((SFc3_ControllerInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_Controller(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ControllerInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Controller_optimization_info();
    }

    finalize_c3_Controller((SFc3_ControllerInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Controller((SFc3_ControllerInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Controller(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Controller((SFc3_ControllerInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_Controller(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Controller_optimization_info(sim_mode_is_rtw_gen
      (S), sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2900932103U));
  ssSetChecksum1(S,(1149068347U));
  ssSetChecksum2(S,(3179252043U));
  ssSetChecksum3(S,(1014767451U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_Controller(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Controller(SimStruct *S)
{
  SFc3_ControllerInstanceStruct *chartInstance;
  chartInstance = (SFc3_ControllerInstanceStruct *)utMalloc(sizeof
    (SFc3_ControllerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_ControllerInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Controller;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_Controller;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Controller;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Controller;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Controller;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Controller;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Controller;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_Controller;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Controller;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Controller;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Controller;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_Controller(chartInstance);
}

void c3_Controller_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Controller(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Controller(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Controller(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Controller_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
