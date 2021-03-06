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
  #define CASADI_PREFIX(ID) chain_nm_6_external_cost_ ## ID
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
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_sq CASADI_PREFIX(sq)

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

static const casadi_int casadi_s0[34] = {30, 1, 0, 30, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
static const casadi_int casadi_s1[7] = {3, 1, 0, 3, 0, 1, 2};
static const casadi_int casadi_s2[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s3[37] = {33, 1, 0, 33, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
static const casadi_int casadi_s4[69] = {33, 33, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

casadi_real casadi_sq(casadi_real x) { return x*x;}

/* chain_nm_6_external_cost:(i0[30],i1[3])->(o0,o1[33],o2[33x33,33nz]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a3, a30, a31, a32, a33, a34, a35, a36, a4, a5, a6, a7, a8, a9;
  a0=5.0000000000000000e-01;
  a1=arg[1] ? arg[1][0] : 0;
  a2=casadi_sq(a1);
  a2=(a0*a2);
  a3=arg[1] ? arg[1][1] : 0;
  a4=casadi_sq(a3);
  a4=(a0*a4);
  a2=(a2+a4);
  a4=arg[1] ? arg[1][2] : 0;
  a5=casadi_sq(a4);
  a5=(a0*a5);
  a2=(a2+a5);
  a5=5.0000000000000001e-03;
  a6=arg[0] ? arg[0][0] : 0;
  a7=1.9382859999999999e-01;
  a6=(a6-a7);
  a7=casadi_sq(a6);
  a7=(a5*a7);
  a2=(a2+a7);
  a7=arg[0] ? arg[0][1] : 0;
  a8=-5.8708560000000000e-18;
  a7=(a7-a8);
  a8=casadi_sq(a7);
  a8=(a5*a8);
  a2=(a2+a8);
  a8=arg[0] ? arg[0][2] : 0;
  a9=-4.8382310000000001e-01;
  a8=(a8-a9);
  a9=casadi_sq(a8);
  a9=(a5*a9);
  a2=(a2+a9);
  a9=arg[0] ? arg[0][3] : 0;
  a10=casadi_sq(a9);
  a10=(a5*a10);
  a2=(a2+a10);
  a10=arg[0] ? arg[0][4] : 0;
  a11=casadi_sq(a10);
  a11=(a5*a11);
  a2=(a2+a11);
  a11=arg[0] ? arg[0][5] : 0;
  a12=casadi_sq(a11);
  a12=(a5*a12);
  a2=(a2+a12);
  a12=arg[0] ? arg[0][6] : 0;
  a13=4.0021800000000002e-01;
  a12=(a12-a13);
  a13=casadi_sq(a12);
  a13=(a5*a13);
  a2=(a2+a13);
  a13=arg[0] ? arg[0][7] : 0;
  a14=-1.2122169999999999e-17;
  a13=(a13-a14);
  a14=casadi_sq(a13);
  a14=(a5*a14);
  a2=(a2+a14);
  a14=arg[0] ? arg[0][8] : 0;
  a15=-6.6444579999999998e-01;
  a14=(a14-a15);
  a15=casadi_sq(a14);
  a15=(a5*a15);
  a2=(a2+a15);
  a15=arg[0] ? arg[0][9] : 0;
  a16=2.9571900000000000e-32;
  a15=(a15-a16);
  a16=casadi_sq(a15);
  a16=(a5*a16);
  a2=(a2+a16);
  a16=arg[0] ? arg[0][10] : 0;
  a17=-1.0291060000000001e-31;
  a16=(a16-a17);
  a17=casadi_sq(a16);
  a17=(a5*a17);
  a2=(a2+a17);
  a17=arg[0] ? arg[0][11] : 0;
  a18=-2.6061429999999998e-31;
  a17=(a17-a18);
  a18=casadi_sq(a17);
  a18=(a5*a18);
  a2=(a2+a18);
  a18=arg[0] ? arg[0][12] : 0;
  a19=6.0822719999999997e-01;
  a18=(a18-a19);
  a19=casadi_sq(a18);
  a19=(a5*a19);
  a2=(a2+a19);
  a19=arg[0] ? arg[0][13] : 0;
  a20=-1.8422540000000001e-17;
  a19=(a19-a20);
  a20=casadi_sq(a19);
  a20=(a5*a20);
  a2=(a2+a20);
  a20=arg[0] ? arg[0][14] : 0;
  a21=-5.0930640000000005e-01;
  a20=(a20-a21);
  a21=casadi_sq(a20);
  a21=(a5*a21);
  a2=(a2+a21);
  a21=arg[0] ? arg[0][15] : 0;
  a22=4.0979009999999996e-40;
  a21=(a21-a22);
  a22=casadi_sq(a21);
  a22=(a5*a22);
  a2=(a2+a22);
  a22=arg[0] ? arg[0][16] : 0;
  a23=4.5409220000000000e-40;
  a22=(a22-a23);
  a23=casadi_sq(a22);
  a23=(a5*a23);
  a2=(a2+a23);
  a23=arg[0] ? arg[0][17] : 0;
  a24=-2.3413739999999998e-40;
  a23=(a23-a24);
  a24=casadi_sq(a23);
  a24=(a5*a24);
  a2=(a2+a24);
  a24=arg[0] ? arg[0][18] : 0;
  a25=8.0262710000000004e-01;
  a24=(a24-a25);
  a25=casadi_sq(a24);
  a25=(a5*a25);
  a2=(a2+a25);
  a25=arg[0] ? arg[0][19] : 0;
  a26=-2.4310700000000001e-17;
  a25=(a25-a26);
  a26=casadi_sq(a25);
  a26=(a5*a26);
  a2=(a2+a26);
  a26=arg[0] ? arg[0][20] : 0;
  a27=-4.9198159999999998e-02;
  a26=(a26-a27);
  a27=casadi_sq(a26);
  a27=(a5*a27);
  a2=(a2+a27);
  a27=arg[0] ? arg[0][21] : 0;
  a28=5.1107029999999997e-41;
  a27=(a27-a28);
  a28=casadi_sq(a27);
  a28=(a5*a28);
  a2=(a2+a28);
  a28=arg[0] ? arg[0][22] : 0;
  a29=6.2387860000000004e-41;
  a28=(a28-a29);
  a29=casadi_sq(a28);
  a29=(a5*a29);
  a2=(a2+a29);
  a29=arg[0] ? arg[0][23] : 0;
  a30=2.0514500000000000e-42;
  a29=(a29-a30);
  a30=casadi_sq(a29);
  a30=(a5*a30);
  a2=(a2+a30);
  a30=arg[0] ? arg[0][24] : 0;
  a31=9.9221009999999998e-01;
  a30=(a30-a31);
  a31=casadi_sq(a30);
  a31=(a5*a31);
  a2=(a2+a31);
  a31=arg[0] ? arg[0][25] : 0;
  a32=-3.0052960000000000e-17;
  a31=(a31-a32);
  a32=casadi_sq(a31);
  a32=(a5*a32);
  a2=(a2+a32);
  a32=arg[0] ? arg[0][26] : 0;
  a33=7.0682089999999997e-01;
  a32=(a32-a33);
  a33=casadi_sq(a32);
  a33=(a5*a33);
  a2=(a2+a33);
  a33=arg[0] ? arg[0][27] : 0;
  a34=casadi_sq(a33);
  a34=(a5*a34);
  a2=(a2+a34);
  a34=arg[0] ? arg[0][28] : 0;
  a35=casadi_sq(a34);
  a35=(a5*a35);
  a2=(a2+a35);
  a35=arg[0] ? arg[0][29] : 0;
  a36=casadi_sq(a35);
  a36=(a5*a36);
  a2=(a2+a36);
  if (res[0]!=0) res[0][0]=a2;
  a1=(a1+a1);
  a1=(a0*a1);
  if (res[1]!=0) res[1][0]=a1;
  a3=(a3+a3);
  a3=(a0*a3);
  if (res[1]!=0) res[1][1]=a3;
  a4=(a4+a4);
  a0=(a0*a4);
  if (res[1]!=0) res[1][2]=a0;
  a6=(a6+a6);
  a6=(a5*a6);
  if (res[1]!=0) res[1][3]=a6;
  a7=(a7+a7);
  a7=(a5*a7);
  if (res[1]!=0) res[1][4]=a7;
  a8=(a8+a8);
  a8=(a5*a8);
  if (res[1]!=0) res[1][5]=a8;
  a9=(a9+a9);
  a9=(a5*a9);
  if (res[1]!=0) res[1][6]=a9;
  a10=(a10+a10);
  a10=(a5*a10);
  if (res[1]!=0) res[1][7]=a10;
  a11=(a11+a11);
  a11=(a5*a11);
  if (res[1]!=0) res[1][8]=a11;
  a12=(a12+a12);
  a12=(a5*a12);
  if (res[1]!=0) res[1][9]=a12;
  a13=(a13+a13);
  a13=(a5*a13);
  if (res[1]!=0) res[1][10]=a13;
  a14=(a14+a14);
  a14=(a5*a14);
  if (res[1]!=0) res[1][11]=a14;
  a15=(a15+a15);
  a15=(a5*a15);
  if (res[1]!=0) res[1][12]=a15;
  a16=(a16+a16);
  a16=(a5*a16);
  if (res[1]!=0) res[1][13]=a16;
  a17=(a17+a17);
  a17=(a5*a17);
  if (res[1]!=0) res[1][14]=a17;
  a18=(a18+a18);
  a18=(a5*a18);
  if (res[1]!=0) res[1][15]=a18;
  a19=(a19+a19);
  a19=(a5*a19);
  if (res[1]!=0) res[1][16]=a19;
  a20=(a20+a20);
  a20=(a5*a20);
  if (res[1]!=0) res[1][17]=a20;
  a21=(a21+a21);
  a21=(a5*a21);
  if (res[1]!=0) res[1][18]=a21;
  a22=(a22+a22);
  a22=(a5*a22);
  if (res[1]!=0) res[1][19]=a22;
  a23=(a23+a23);
  a23=(a5*a23);
  if (res[1]!=0) res[1][20]=a23;
  a24=(a24+a24);
  a24=(a5*a24);
  if (res[1]!=0) res[1][21]=a24;
  a25=(a25+a25);
  a25=(a5*a25);
  if (res[1]!=0) res[1][22]=a25;
  a26=(a26+a26);
  a26=(a5*a26);
  if (res[1]!=0) res[1][23]=a26;
  a27=(a27+a27);
  a27=(a5*a27);
  if (res[1]!=0) res[1][24]=a27;
  a28=(a28+a28);
  a28=(a5*a28);
  if (res[1]!=0) res[1][25]=a28;
  a29=(a29+a29);
  a29=(a5*a29);
  if (res[1]!=0) res[1][26]=a29;
  a30=(a30+a30);
  a30=(a5*a30);
  if (res[1]!=0) res[1][27]=a30;
  a31=(a31+a31);
  a31=(a5*a31);
  if (res[1]!=0) res[1][28]=a31;
  a32=(a32+a32);
  a32=(a5*a32);
  if (res[1]!=0) res[1][29]=a32;
  a33=(a33+a33);
  a33=(a5*a33);
  if (res[1]!=0) res[1][30]=a33;
  a34=(a34+a34);
  a34=(a5*a34);
  if (res[1]!=0) res[1][31]=a34;
  a35=(a35+a35);
  a5=(a5*a35);
  if (res[1]!=0) res[1][32]=a5;
  a5=1.;
  if (res[2]!=0) res[2][0]=a5;
  if (res[2]!=0) res[2][1]=a5;
  if (res[2]!=0) res[2][2]=a5;
  a5=1.0000000000000000e-02;
  if (res[2]!=0) res[2][3]=a5;
  if (res[2]!=0) res[2][4]=a5;
  if (res[2]!=0) res[2][5]=a5;
  if (res[2]!=0) res[2][6]=a5;
  if (res[2]!=0) res[2][7]=a5;
  if (res[2]!=0) res[2][8]=a5;
  if (res[2]!=0) res[2][9]=a5;
  if (res[2]!=0) res[2][10]=a5;
  if (res[2]!=0) res[2][11]=a5;
  if (res[2]!=0) res[2][12]=a5;
  if (res[2]!=0) res[2][13]=a5;
  if (res[2]!=0) res[2][14]=a5;
  if (res[2]!=0) res[2][15]=a5;
  if (res[2]!=0) res[2][16]=a5;
  if (res[2]!=0) res[2][17]=a5;
  if (res[2]!=0) res[2][18]=a5;
  if (res[2]!=0) res[2][19]=a5;
  if (res[2]!=0) res[2][20]=a5;
  if (res[2]!=0) res[2][21]=a5;
  if (res[2]!=0) res[2][22]=a5;
  if (res[2]!=0) res[2][23]=a5;
  if (res[2]!=0) res[2][24]=a5;
  if (res[2]!=0) res[2][25]=a5;
  if (res[2]!=0) res[2][26]=a5;
  if (res[2]!=0) res[2][27]=a5;
  if (res[2]!=0) res[2][28]=a5;
  if (res[2]!=0) res[2][29]=a5;
  if (res[2]!=0) res[2][30]=a5;
  if (res[2]!=0) res[2][31]=a5;
  if (res[2]!=0) res[2][32]=a5;
  return 0;
}

CASADI_SYMBOL_EXPORT int chain_nm_6_external_cost(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, void* mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT void chain_nm_6_external_cost_incref(void) {
}

CASADI_SYMBOL_EXPORT void chain_nm_6_external_cost_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int chain_nm_6_external_cost_n_in(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_int chain_nm_6_external_cost_n_out(void) { return 3;}

CASADI_SYMBOL_EXPORT const char* chain_nm_6_external_cost_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* chain_nm_6_external_cost_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    case 2: return "o2";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* chain_nm_6_external_cost_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* chain_nm_6_external_cost_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s2;
    case 1: return casadi_s3;
    case 2: return casadi_s4;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int chain_nm_6_external_cost_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 3;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
