#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_113052499138860728) {
   out_113052499138860728[0] = delta_x[0] + nom_x[0];
   out_113052499138860728[1] = delta_x[1] + nom_x[1];
   out_113052499138860728[2] = delta_x[2] + nom_x[2];
   out_113052499138860728[3] = delta_x[3] + nom_x[3];
   out_113052499138860728[4] = delta_x[4] + nom_x[4];
   out_113052499138860728[5] = delta_x[5] + nom_x[5];
   out_113052499138860728[6] = delta_x[6] + nom_x[6];
   out_113052499138860728[7] = delta_x[7] + nom_x[7];
   out_113052499138860728[8] = delta_x[8] + nom_x[8];
   out_113052499138860728[9] = delta_x[9] + nom_x[9];
   out_113052499138860728[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_964570142091074406) {
   out_964570142091074406[0] = -nom_x[0] + true_x[0];
   out_964570142091074406[1] = -nom_x[1] + true_x[1];
   out_964570142091074406[2] = -nom_x[2] + true_x[2];
   out_964570142091074406[3] = -nom_x[3] + true_x[3];
   out_964570142091074406[4] = -nom_x[4] + true_x[4];
   out_964570142091074406[5] = -nom_x[5] + true_x[5];
   out_964570142091074406[6] = -nom_x[6] + true_x[6];
   out_964570142091074406[7] = -nom_x[7] + true_x[7];
   out_964570142091074406[8] = -nom_x[8] + true_x[8];
   out_964570142091074406[9] = -nom_x[9] + true_x[9];
   out_964570142091074406[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_6748758134973358957) {
   out_6748758134973358957[0] = 1.0;
   out_6748758134973358957[1] = 0;
   out_6748758134973358957[2] = 0;
   out_6748758134973358957[3] = 0;
   out_6748758134973358957[4] = 0;
   out_6748758134973358957[5] = 0;
   out_6748758134973358957[6] = 0;
   out_6748758134973358957[7] = 0;
   out_6748758134973358957[8] = 0;
   out_6748758134973358957[9] = 0;
   out_6748758134973358957[10] = 0;
   out_6748758134973358957[11] = 0;
   out_6748758134973358957[12] = 1.0;
   out_6748758134973358957[13] = 0;
   out_6748758134973358957[14] = 0;
   out_6748758134973358957[15] = 0;
   out_6748758134973358957[16] = 0;
   out_6748758134973358957[17] = 0;
   out_6748758134973358957[18] = 0;
   out_6748758134973358957[19] = 0;
   out_6748758134973358957[20] = 0;
   out_6748758134973358957[21] = 0;
   out_6748758134973358957[22] = 0;
   out_6748758134973358957[23] = 0;
   out_6748758134973358957[24] = 1.0;
   out_6748758134973358957[25] = 0;
   out_6748758134973358957[26] = 0;
   out_6748758134973358957[27] = 0;
   out_6748758134973358957[28] = 0;
   out_6748758134973358957[29] = 0;
   out_6748758134973358957[30] = 0;
   out_6748758134973358957[31] = 0;
   out_6748758134973358957[32] = 0;
   out_6748758134973358957[33] = 0;
   out_6748758134973358957[34] = 0;
   out_6748758134973358957[35] = 0;
   out_6748758134973358957[36] = 1.0;
   out_6748758134973358957[37] = 0;
   out_6748758134973358957[38] = 0;
   out_6748758134973358957[39] = 0;
   out_6748758134973358957[40] = 0;
   out_6748758134973358957[41] = 0;
   out_6748758134973358957[42] = 0;
   out_6748758134973358957[43] = 0;
   out_6748758134973358957[44] = 0;
   out_6748758134973358957[45] = 0;
   out_6748758134973358957[46] = 0;
   out_6748758134973358957[47] = 0;
   out_6748758134973358957[48] = 1.0;
   out_6748758134973358957[49] = 0;
   out_6748758134973358957[50] = 0;
   out_6748758134973358957[51] = 0;
   out_6748758134973358957[52] = 0;
   out_6748758134973358957[53] = 0;
   out_6748758134973358957[54] = 0;
   out_6748758134973358957[55] = 0;
   out_6748758134973358957[56] = 0;
   out_6748758134973358957[57] = 0;
   out_6748758134973358957[58] = 0;
   out_6748758134973358957[59] = 0;
   out_6748758134973358957[60] = 1.0;
   out_6748758134973358957[61] = 0;
   out_6748758134973358957[62] = 0;
   out_6748758134973358957[63] = 0;
   out_6748758134973358957[64] = 0;
   out_6748758134973358957[65] = 0;
   out_6748758134973358957[66] = 0;
   out_6748758134973358957[67] = 0;
   out_6748758134973358957[68] = 0;
   out_6748758134973358957[69] = 0;
   out_6748758134973358957[70] = 0;
   out_6748758134973358957[71] = 0;
   out_6748758134973358957[72] = 1.0;
   out_6748758134973358957[73] = 0;
   out_6748758134973358957[74] = 0;
   out_6748758134973358957[75] = 0;
   out_6748758134973358957[76] = 0;
   out_6748758134973358957[77] = 0;
   out_6748758134973358957[78] = 0;
   out_6748758134973358957[79] = 0;
   out_6748758134973358957[80] = 0;
   out_6748758134973358957[81] = 0;
   out_6748758134973358957[82] = 0;
   out_6748758134973358957[83] = 0;
   out_6748758134973358957[84] = 1.0;
   out_6748758134973358957[85] = 0;
   out_6748758134973358957[86] = 0;
   out_6748758134973358957[87] = 0;
   out_6748758134973358957[88] = 0;
   out_6748758134973358957[89] = 0;
   out_6748758134973358957[90] = 0;
   out_6748758134973358957[91] = 0;
   out_6748758134973358957[92] = 0;
   out_6748758134973358957[93] = 0;
   out_6748758134973358957[94] = 0;
   out_6748758134973358957[95] = 0;
   out_6748758134973358957[96] = 1.0;
   out_6748758134973358957[97] = 0;
   out_6748758134973358957[98] = 0;
   out_6748758134973358957[99] = 0;
   out_6748758134973358957[100] = 0;
   out_6748758134973358957[101] = 0;
   out_6748758134973358957[102] = 0;
   out_6748758134973358957[103] = 0;
   out_6748758134973358957[104] = 0;
   out_6748758134973358957[105] = 0;
   out_6748758134973358957[106] = 0;
   out_6748758134973358957[107] = 0;
   out_6748758134973358957[108] = 1.0;
   out_6748758134973358957[109] = 0;
   out_6748758134973358957[110] = 0;
   out_6748758134973358957[111] = 0;
   out_6748758134973358957[112] = 0;
   out_6748758134973358957[113] = 0;
   out_6748758134973358957[114] = 0;
   out_6748758134973358957[115] = 0;
   out_6748758134973358957[116] = 0;
   out_6748758134973358957[117] = 0;
   out_6748758134973358957[118] = 0;
   out_6748758134973358957[119] = 0;
   out_6748758134973358957[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_4985336149056058800) {
   out_4985336149056058800[0] = dt*state[3] + state[0];
   out_4985336149056058800[1] = dt*state[4] + state[1];
   out_4985336149056058800[2] = dt*state[5] + state[2];
   out_4985336149056058800[3] = state[3];
   out_4985336149056058800[4] = state[4];
   out_4985336149056058800[5] = state[5];
   out_4985336149056058800[6] = dt*state[7] + state[6];
   out_4985336149056058800[7] = dt*state[8] + state[7];
   out_4985336149056058800[8] = state[8];
   out_4985336149056058800[9] = state[9];
   out_4985336149056058800[10] = state[10];
}
void F_fun(double *state, double dt, double *out_7057326551453181267) {
   out_7057326551453181267[0] = 1;
   out_7057326551453181267[1] = 0;
   out_7057326551453181267[2] = 0;
   out_7057326551453181267[3] = dt;
   out_7057326551453181267[4] = 0;
   out_7057326551453181267[5] = 0;
   out_7057326551453181267[6] = 0;
   out_7057326551453181267[7] = 0;
   out_7057326551453181267[8] = 0;
   out_7057326551453181267[9] = 0;
   out_7057326551453181267[10] = 0;
   out_7057326551453181267[11] = 0;
   out_7057326551453181267[12] = 1;
   out_7057326551453181267[13] = 0;
   out_7057326551453181267[14] = 0;
   out_7057326551453181267[15] = dt;
   out_7057326551453181267[16] = 0;
   out_7057326551453181267[17] = 0;
   out_7057326551453181267[18] = 0;
   out_7057326551453181267[19] = 0;
   out_7057326551453181267[20] = 0;
   out_7057326551453181267[21] = 0;
   out_7057326551453181267[22] = 0;
   out_7057326551453181267[23] = 0;
   out_7057326551453181267[24] = 1;
   out_7057326551453181267[25] = 0;
   out_7057326551453181267[26] = 0;
   out_7057326551453181267[27] = dt;
   out_7057326551453181267[28] = 0;
   out_7057326551453181267[29] = 0;
   out_7057326551453181267[30] = 0;
   out_7057326551453181267[31] = 0;
   out_7057326551453181267[32] = 0;
   out_7057326551453181267[33] = 0;
   out_7057326551453181267[34] = 0;
   out_7057326551453181267[35] = 0;
   out_7057326551453181267[36] = 1;
   out_7057326551453181267[37] = 0;
   out_7057326551453181267[38] = 0;
   out_7057326551453181267[39] = 0;
   out_7057326551453181267[40] = 0;
   out_7057326551453181267[41] = 0;
   out_7057326551453181267[42] = 0;
   out_7057326551453181267[43] = 0;
   out_7057326551453181267[44] = 0;
   out_7057326551453181267[45] = 0;
   out_7057326551453181267[46] = 0;
   out_7057326551453181267[47] = 0;
   out_7057326551453181267[48] = 1;
   out_7057326551453181267[49] = 0;
   out_7057326551453181267[50] = 0;
   out_7057326551453181267[51] = 0;
   out_7057326551453181267[52] = 0;
   out_7057326551453181267[53] = 0;
   out_7057326551453181267[54] = 0;
   out_7057326551453181267[55] = 0;
   out_7057326551453181267[56] = 0;
   out_7057326551453181267[57] = 0;
   out_7057326551453181267[58] = 0;
   out_7057326551453181267[59] = 0;
   out_7057326551453181267[60] = 1;
   out_7057326551453181267[61] = 0;
   out_7057326551453181267[62] = 0;
   out_7057326551453181267[63] = 0;
   out_7057326551453181267[64] = 0;
   out_7057326551453181267[65] = 0;
   out_7057326551453181267[66] = 0;
   out_7057326551453181267[67] = 0;
   out_7057326551453181267[68] = 0;
   out_7057326551453181267[69] = 0;
   out_7057326551453181267[70] = 0;
   out_7057326551453181267[71] = 0;
   out_7057326551453181267[72] = 1;
   out_7057326551453181267[73] = dt;
   out_7057326551453181267[74] = 0;
   out_7057326551453181267[75] = 0;
   out_7057326551453181267[76] = 0;
   out_7057326551453181267[77] = 0;
   out_7057326551453181267[78] = 0;
   out_7057326551453181267[79] = 0;
   out_7057326551453181267[80] = 0;
   out_7057326551453181267[81] = 0;
   out_7057326551453181267[82] = 0;
   out_7057326551453181267[83] = 0;
   out_7057326551453181267[84] = 1;
   out_7057326551453181267[85] = dt;
   out_7057326551453181267[86] = 0;
   out_7057326551453181267[87] = 0;
   out_7057326551453181267[88] = 0;
   out_7057326551453181267[89] = 0;
   out_7057326551453181267[90] = 0;
   out_7057326551453181267[91] = 0;
   out_7057326551453181267[92] = 0;
   out_7057326551453181267[93] = 0;
   out_7057326551453181267[94] = 0;
   out_7057326551453181267[95] = 0;
   out_7057326551453181267[96] = 1;
   out_7057326551453181267[97] = 0;
   out_7057326551453181267[98] = 0;
   out_7057326551453181267[99] = 0;
   out_7057326551453181267[100] = 0;
   out_7057326551453181267[101] = 0;
   out_7057326551453181267[102] = 0;
   out_7057326551453181267[103] = 0;
   out_7057326551453181267[104] = 0;
   out_7057326551453181267[105] = 0;
   out_7057326551453181267[106] = 0;
   out_7057326551453181267[107] = 0;
   out_7057326551453181267[108] = 1;
   out_7057326551453181267[109] = 0;
   out_7057326551453181267[110] = 0;
   out_7057326551453181267[111] = 0;
   out_7057326551453181267[112] = 0;
   out_7057326551453181267[113] = 0;
   out_7057326551453181267[114] = 0;
   out_7057326551453181267[115] = 0;
   out_7057326551453181267[116] = 0;
   out_7057326551453181267[117] = 0;
   out_7057326551453181267[118] = 0;
   out_7057326551453181267[119] = 0;
   out_7057326551453181267[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_7101442657733273071) {
   out_7101442657733273071[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_1205373226368180211) {
   out_1205373226368180211[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1205373226368180211[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1205373226368180211[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1205373226368180211[3] = 0;
   out_1205373226368180211[4] = 0;
   out_1205373226368180211[5] = 0;
   out_1205373226368180211[6] = 1;
   out_1205373226368180211[7] = 0;
   out_1205373226368180211[8] = 0;
   out_1205373226368180211[9] = 0;
   out_1205373226368180211[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_1238762562760675251) {
   out_1238762562760675251[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_8839818693546915909) {
   out_8839818693546915909[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8839818693546915909[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8839818693546915909[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_8839818693546915909[3] = 0;
   out_8839818693546915909[4] = 0;
   out_8839818693546915909[5] = 0;
   out_8839818693546915909[6] = 1;
   out_8839818693546915909[7] = 0;
   out_8839818693546915909[8] = 0;
   out_8839818693546915909[9] = 1;
   out_8839818693546915909[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_3851795894157492390) {
   out_3851795894157492390[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_4685923984777977273) {
   out_4685923984777977273[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[6] = 0;
   out_4685923984777977273[7] = 1;
   out_4685923984777977273[8] = 0;
   out_4685923984777977273[9] = 0;
   out_4685923984777977273[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_3851795894157492390) {
   out_3851795894157492390[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_4685923984777977273) {
   out_4685923984777977273[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_4685923984777977273[6] = 0;
   out_4685923984777977273[7] = 1;
   out_4685923984777977273[8] = 0;
   out_4685923984777977273[9] = 0;
   out_4685923984777977273[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_113052499138860728) {
  err_fun(nom_x, delta_x, out_113052499138860728);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_964570142091074406) {
  inv_err_fun(nom_x, true_x, out_964570142091074406);
}
void gnss_H_mod_fun(double *state, double *out_6748758134973358957) {
  H_mod_fun(state, out_6748758134973358957);
}
void gnss_f_fun(double *state, double dt, double *out_4985336149056058800) {
  f_fun(state,  dt, out_4985336149056058800);
}
void gnss_F_fun(double *state, double dt, double *out_7057326551453181267) {
  F_fun(state,  dt, out_7057326551453181267);
}
void gnss_h_6(double *state, double *sat_pos, double *out_7101442657733273071) {
  h_6(state, sat_pos, out_7101442657733273071);
}
void gnss_H_6(double *state, double *sat_pos, double *out_1205373226368180211) {
  H_6(state, sat_pos, out_1205373226368180211);
}
void gnss_h_20(double *state, double *sat_pos, double *out_1238762562760675251) {
  h_20(state, sat_pos, out_1238762562760675251);
}
void gnss_H_20(double *state, double *sat_pos, double *out_8839818693546915909) {
  H_20(state, sat_pos, out_8839818693546915909);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_3851795894157492390) {
  h_7(state, sat_pos_vel, out_3851795894157492390);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_4685923984777977273) {
  H_7(state, sat_pos_vel, out_4685923984777977273);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_3851795894157492390) {
  h_21(state, sat_pos_vel, out_3851795894157492390);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_4685923984777977273) {
  H_21(state, sat_pos_vel, out_4685923984777977273);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
