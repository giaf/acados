/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CODEGEN_PREFIX
  #define NAMESPACE_CONCAT(NS, ID) _NAMESPACE_CONCAT(NS, ID)
  #define _NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) simple_dae_impl_ode_jac_x_xdot_u_z_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

static const casadi_int casadi_s0[6] = {2, 1, 0, 2, 0, 1};
static const casadi_int casadi_s1[9] = {4, 2, 0, 2, 4, 0, 2, 1, 3};
static const casadi_int casadi_s2[7] = {4, 2, 0, 1, 2, 0, 1};
static const casadi_int casadi_s3[9] = {4, 2, 0, 2, 4, 1, 2, 0, 3};

/* simple_dae_impl_ode_jac_x_xdot_u_z:(i0[2],i1[2],i2[2],i3[2])->(o0[4x2,4nz],o1[4x2,2nz],o2[4x2,2nz],o3[4x2,4nz]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem) {
  casadi_real a0, a1;
  a0=1.;
  if (res[0]!=0) res[0][0]=a0;
  a1=-1.;
  if (res[0]!=0) res[0][1]=a1;
  if (res[0]!=0) res[0][2]=a0;
  if (res[0]!=0) res[0][3]=a1;
  if (res[1]!=0) res[1][0]=a0;
  if (res[1]!=0) res[1][1]=a0;
  if (res[2]!=0) res[2][0]=a1;
  if (res[2]!=0) res[2][1]=a1;
  a1=-1.0000000000000001e-01;
  if (res[3]!=0) res[3][0]=a1;
  if (res[3]!=0) res[3][1]=a0;
  if (res[3]!=0) res[3][2]=a1;
  if (res[3]!=0) res[3][3]=a0;
  return 0;
}

CASADI_SYMBOL_EXPORT int simple_dae_impl_ode_jac_x_xdot_u_z(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT void simple_dae_impl_ode_jac_x_xdot_u_z_incref(void) {
}

CASADI_SYMBOL_EXPORT void simple_dae_impl_ode_jac_x_xdot_u_z_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int simple_dae_impl_ode_jac_x_xdot_u_z_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int simple_dae_impl_ode_jac_x_xdot_u_z_n_out(void) { return 4;}

CASADI_SYMBOL_EXPORT const char* simple_dae_impl_ode_jac_x_xdot_u_z_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* simple_dae_impl_ode_jac_x_xdot_u_z_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    case 2: return "o2";
    case 3: return "o3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* simple_dae_impl_ode_jac_x_xdot_u_z_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s0;
    case 3: return casadi_s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* simple_dae_impl_ode_jac_x_xdot_u_z_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s1;
    case 1: return casadi_s2;
    case 2: return casadi_s2;
    case 3: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int simple_dae_impl_ode_jac_x_xdot_u_z_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 4;
  if (sz_res) *sz_res = 4;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
