#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8224710768753384870) {
   out_8224710768753384870[0] = delta_x[0] + nom_x[0];
   out_8224710768753384870[1] = delta_x[1] + nom_x[1];
   out_8224710768753384870[2] = delta_x[2] + nom_x[2];
   out_8224710768753384870[3] = delta_x[3] + nom_x[3];
   out_8224710768753384870[4] = delta_x[4] + nom_x[4];
   out_8224710768753384870[5] = delta_x[5] + nom_x[5];
   out_8224710768753384870[6] = delta_x[6] + nom_x[6];
   out_8224710768753384870[7] = delta_x[7] + nom_x[7];
   out_8224710768753384870[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6195700753239379980) {
   out_6195700753239379980[0] = -nom_x[0] + true_x[0];
   out_6195700753239379980[1] = -nom_x[1] + true_x[1];
   out_6195700753239379980[2] = -nom_x[2] + true_x[2];
   out_6195700753239379980[3] = -nom_x[3] + true_x[3];
   out_6195700753239379980[4] = -nom_x[4] + true_x[4];
   out_6195700753239379980[5] = -nom_x[5] + true_x[5];
   out_6195700753239379980[6] = -nom_x[6] + true_x[6];
   out_6195700753239379980[7] = -nom_x[7] + true_x[7];
   out_6195700753239379980[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5375910394241702470) {
   out_5375910394241702470[0] = 1.0;
   out_5375910394241702470[1] = 0;
   out_5375910394241702470[2] = 0;
   out_5375910394241702470[3] = 0;
   out_5375910394241702470[4] = 0;
   out_5375910394241702470[5] = 0;
   out_5375910394241702470[6] = 0;
   out_5375910394241702470[7] = 0;
   out_5375910394241702470[8] = 0;
   out_5375910394241702470[9] = 0;
   out_5375910394241702470[10] = 1.0;
   out_5375910394241702470[11] = 0;
   out_5375910394241702470[12] = 0;
   out_5375910394241702470[13] = 0;
   out_5375910394241702470[14] = 0;
   out_5375910394241702470[15] = 0;
   out_5375910394241702470[16] = 0;
   out_5375910394241702470[17] = 0;
   out_5375910394241702470[18] = 0;
   out_5375910394241702470[19] = 0;
   out_5375910394241702470[20] = 1.0;
   out_5375910394241702470[21] = 0;
   out_5375910394241702470[22] = 0;
   out_5375910394241702470[23] = 0;
   out_5375910394241702470[24] = 0;
   out_5375910394241702470[25] = 0;
   out_5375910394241702470[26] = 0;
   out_5375910394241702470[27] = 0;
   out_5375910394241702470[28] = 0;
   out_5375910394241702470[29] = 0;
   out_5375910394241702470[30] = 1.0;
   out_5375910394241702470[31] = 0;
   out_5375910394241702470[32] = 0;
   out_5375910394241702470[33] = 0;
   out_5375910394241702470[34] = 0;
   out_5375910394241702470[35] = 0;
   out_5375910394241702470[36] = 0;
   out_5375910394241702470[37] = 0;
   out_5375910394241702470[38] = 0;
   out_5375910394241702470[39] = 0;
   out_5375910394241702470[40] = 1.0;
   out_5375910394241702470[41] = 0;
   out_5375910394241702470[42] = 0;
   out_5375910394241702470[43] = 0;
   out_5375910394241702470[44] = 0;
   out_5375910394241702470[45] = 0;
   out_5375910394241702470[46] = 0;
   out_5375910394241702470[47] = 0;
   out_5375910394241702470[48] = 0;
   out_5375910394241702470[49] = 0;
   out_5375910394241702470[50] = 1.0;
   out_5375910394241702470[51] = 0;
   out_5375910394241702470[52] = 0;
   out_5375910394241702470[53] = 0;
   out_5375910394241702470[54] = 0;
   out_5375910394241702470[55] = 0;
   out_5375910394241702470[56] = 0;
   out_5375910394241702470[57] = 0;
   out_5375910394241702470[58] = 0;
   out_5375910394241702470[59] = 0;
   out_5375910394241702470[60] = 1.0;
   out_5375910394241702470[61] = 0;
   out_5375910394241702470[62] = 0;
   out_5375910394241702470[63] = 0;
   out_5375910394241702470[64] = 0;
   out_5375910394241702470[65] = 0;
   out_5375910394241702470[66] = 0;
   out_5375910394241702470[67] = 0;
   out_5375910394241702470[68] = 0;
   out_5375910394241702470[69] = 0;
   out_5375910394241702470[70] = 1.0;
   out_5375910394241702470[71] = 0;
   out_5375910394241702470[72] = 0;
   out_5375910394241702470[73] = 0;
   out_5375910394241702470[74] = 0;
   out_5375910394241702470[75] = 0;
   out_5375910394241702470[76] = 0;
   out_5375910394241702470[77] = 0;
   out_5375910394241702470[78] = 0;
   out_5375910394241702470[79] = 0;
   out_5375910394241702470[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1448099311491195891) {
   out_1448099311491195891[0] = state[0];
   out_1448099311491195891[1] = state[1];
   out_1448099311491195891[2] = state[2];
   out_1448099311491195891[3] = state[3];
   out_1448099311491195891[4] = state[4];
   out_1448099311491195891[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1448099311491195891[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1448099311491195891[7] = state[7];
   out_1448099311491195891[8] = state[8];
}
void F_fun(double *state, double dt, double *out_523140851368550509) {
   out_523140851368550509[0] = 1;
   out_523140851368550509[1] = 0;
   out_523140851368550509[2] = 0;
   out_523140851368550509[3] = 0;
   out_523140851368550509[4] = 0;
   out_523140851368550509[5] = 0;
   out_523140851368550509[6] = 0;
   out_523140851368550509[7] = 0;
   out_523140851368550509[8] = 0;
   out_523140851368550509[9] = 0;
   out_523140851368550509[10] = 1;
   out_523140851368550509[11] = 0;
   out_523140851368550509[12] = 0;
   out_523140851368550509[13] = 0;
   out_523140851368550509[14] = 0;
   out_523140851368550509[15] = 0;
   out_523140851368550509[16] = 0;
   out_523140851368550509[17] = 0;
   out_523140851368550509[18] = 0;
   out_523140851368550509[19] = 0;
   out_523140851368550509[20] = 1;
   out_523140851368550509[21] = 0;
   out_523140851368550509[22] = 0;
   out_523140851368550509[23] = 0;
   out_523140851368550509[24] = 0;
   out_523140851368550509[25] = 0;
   out_523140851368550509[26] = 0;
   out_523140851368550509[27] = 0;
   out_523140851368550509[28] = 0;
   out_523140851368550509[29] = 0;
   out_523140851368550509[30] = 1;
   out_523140851368550509[31] = 0;
   out_523140851368550509[32] = 0;
   out_523140851368550509[33] = 0;
   out_523140851368550509[34] = 0;
   out_523140851368550509[35] = 0;
   out_523140851368550509[36] = 0;
   out_523140851368550509[37] = 0;
   out_523140851368550509[38] = 0;
   out_523140851368550509[39] = 0;
   out_523140851368550509[40] = 1;
   out_523140851368550509[41] = 0;
   out_523140851368550509[42] = 0;
   out_523140851368550509[43] = 0;
   out_523140851368550509[44] = 0;
   out_523140851368550509[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_523140851368550509[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_523140851368550509[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_523140851368550509[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_523140851368550509[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_523140851368550509[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_523140851368550509[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_523140851368550509[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_523140851368550509[53] = -9.8000000000000007*dt;
   out_523140851368550509[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_523140851368550509[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_523140851368550509[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_523140851368550509[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_523140851368550509[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_523140851368550509[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_523140851368550509[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_523140851368550509[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_523140851368550509[62] = 0;
   out_523140851368550509[63] = 0;
   out_523140851368550509[64] = 0;
   out_523140851368550509[65] = 0;
   out_523140851368550509[66] = 0;
   out_523140851368550509[67] = 0;
   out_523140851368550509[68] = 0;
   out_523140851368550509[69] = 0;
   out_523140851368550509[70] = 1;
   out_523140851368550509[71] = 0;
   out_523140851368550509[72] = 0;
   out_523140851368550509[73] = 0;
   out_523140851368550509[74] = 0;
   out_523140851368550509[75] = 0;
   out_523140851368550509[76] = 0;
   out_523140851368550509[77] = 0;
   out_523140851368550509[78] = 0;
   out_523140851368550509[79] = 0;
   out_523140851368550509[80] = 1;
}
void h_25(double *state, double *unused, double *out_1704824311903479744) {
   out_1704824311903479744[0] = state[6];
}
void H_25(double *state, double *unused, double *out_810681659242705099) {
   out_810681659242705099[0] = 0;
   out_810681659242705099[1] = 0;
   out_810681659242705099[2] = 0;
   out_810681659242705099[3] = 0;
   out_810681659242705099[4] = 0;
   out_810681659242705099[5] = 0;
   out_810681659242705099[6] = 1;
   out_810681659242705099[7] = 0;
   out_810681659242705099[8] = 0;
}
void h_24(double *state, double *unused, double *out_6014661257652399328) {
   out_6014661257652399328[0] = state[4];
   out_6014661257652399328[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8417383526826490126) {
   out_8417383526826490126[0] = 0;
   out_8417383526826490126[1] = 0;
   out_8417383526826490126[2] = 0;
   out_8417383526826490126[3] = 0;
   out_8417383526826490126[4] = 1;
   out_8417383526826490126[5] = 0;
   out_8417383526826490126[6] = 0;
   out_8417383526826490126[7] = 0;
   out_8417383526826490126[8] = 0;
   out_8417383526826490126[9] = 0;
   out_8417383526826490126[10] = 0;
   out_8417383526826490126[11] = 0;
   out_8417383526826490126[12] = 0;
   out_8417383526826490126[13] = 0;
   out_8417383526826490126[14] = 1;
   out_8417383526826490126[15] = 0;
   out_8417383526826490126[16] = 0;
   out_8417383526826490126[17] = 0;
}
void h_30(double *state, double *unused, double *out_2235331708922326722) {
   out_2235331708922326722[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5338377989370313297) {
   out_5338377989370313297[0] = 0;
   out_5338377989370313297[1] = 0;
   out_5338377989370313297[2] = 0;
   out_5338377989370313297[3] = 0;
   out_5338377989370313297[4] = 1;
   out_5338377989370313297[5] = 0;
   out_5338377989370313297[6] = 0;
   out_5338377989370313297[7] = 0;
   out_5338377989370313297[8] = 0;
}
void h_26(double *state, double *unused, double *out_3178841561823989157) {
   out_3178841561823989157[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4552184978116761323) {
   out_4552184978116761323[0] = 0;
   out_4552184978116761323[1] = 0;
   out_4552184978116761323[2] = 0;
   out_4552184978116761323[3] = 0;
   out_4552184978116761323[4] = 0;
   out_4552184978116761323[5] = 0;
   out_4552184978116761323[6] = 0;
   out_4552184978116761323[7] = 1;
   out_4552184978116761323[8] = 0;
}
void h_27(double *state, double *unused, double *out_7091485152362517396) {
   out_7091485152362517396[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3114783918186370080) {
   out_3114783918186370080[0] = 0;
   out_3114783918186370080[1] = 0;
   out_3114783918186370080[2] = 0;
   out_3114783918186370080[3] = 1;
   out_3114783918186370080[4] = 0;
   out_3114783918186370080[5] = 0;
   out_3114783918186370080[6] = 0;
   out_3114783918186370080[7] = 0;
   out_3114783918186370080[8] = 0;
}
void h_29(double *state, double *unused, double *out_5199811725506374091) {
   out_5199811725506374091[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4828146645055921113) {
   out_4828146645055921113[0] = 0;
   out_4828146645055921113[1] = 1;
   out_4828146645055921113[2] = 0;
   out_4828146645055921113[3] = 0;
   out_4828146645055921113[4] = 0;
   out_4828146645055921113[5] = 0;
   out_4828146645055921113[6] = 0;
   out_4828146645055921113[7] = 0;
   out_4828146645055921113[8] = 0;
}
void h_28(double *state, double *unused, double *out_8939578826838322736) {
   out_8939578826838322736[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2864516373490594862) {
   out_2864516373490594862[0] = 1;
   out_2864516373490594862[1] = 0;
   out_2864516373490594862[2] = 0;
   out_2864516373490594862[3] = 0;
   out_2864516373490594862[4] = 0;
   out_2864516373490594862[5] = 0;
   out_2864516373490594862[6] = 0;
   out_2864516373490594862[7] = 0;
   out_2864516373490594862[8] = 0;
}
void h_31(double *state, double *unused, double *out_1547637643552350599) {
   out_1547637643552350599[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5178393080350112799) {
   out_5178393080350112799[0] = 0;
   out_5178393080350112799[1] = 0;
   out_5178393080350112799[2] = 0;
   out_5178393080350112799[3] = 0;
   out_5178393080350112799[4] = 0;
   out_5178393080350112799[5] = 0;
   out_5178393080350112799[6] = 0;
   out_5178393080350112799[7] = 0;
   out_5178393080350112799[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8224710768753384870) {
  err_fun(nom_x, delta_x, out_8224710768753384870);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6195700753239379980) {
  inv_err_fun(nom_x, true_x, out_6195700753239379980);
}
void car_H_mod_fun(double *state, double *out_5375910394241702470) {
  H_mod_fun(state, out_5375910394241702470);
}
void car_f_fun(double *state, double dt, double *out_1448099311491195891) {
  f_fun(state,  dt, out_1448099311491195891);
}
void car_F_fun(double *state, double dt, double *out_523140851368550509) {
  F_fun(state,  dt, out_523140851368550509);
}
void car_h_25(double *state, double *unused, double *out_1704824311903479744) {
  h_25(state, unused, out_1704824311903479744);
}
void car_H_25(double *state, double *unused, double *out_810681659242705099) {
  H_25(state, unused, out_810681659242705099);
}
void car_h_24(double *state, double *unused, double *out_6014661257652399328) {
  h_24(state, unused, out_6014661257652399328);
}
void car_H_24(double *state, double *unused, double *out_8417383526826490126) {
  H_24(state, unused, out_8417383526826490126);
}
void car_h_30(double *state, double *unused, double *out_2235331708922326722) {
  h_30(state, unused, out_2235331708922326722);
}
void car_H_30(double *state, double *unused, double *out_5338377989370313297) {
  H_30(state, unused, out_5338377989370313297);
}
void car_h_26(double *state, double *unused, double *out_3178841561823989157) {
  h_26(state, unused, out_3178841561823989157);
}
void car_H_26(double *state, double *unused, double *out_4552184978116761323) {
  H_26(state, unused, out_4552184978116761323);
}
void car_h_27(double *state, double *unused, double *out_7091485152362517396) {
  h_27(state, unused, out_7091485152362517396);
}
void car_H_27(double *state, double *unused, double *out_3114783918186370080) {
  H_27(state, unused, out_3114783918186370080);
}
void car_h_29(double *state, double *unused, double *out_5199811725506374091) {
  h_29(state, unused, out_5199811725506374091);
}
void car_H_29(double *state, double *unused, double *out_4828146645055921113) {
  H_29(state, unused, out_4828146645055921113);
}
void car_h_28(double *state, double *unused, double *out_8939578826838322736) {
  h_28(state, unused, out_8939578826838322736);
}
void car_H_28(double *state, double *unused, double *out_2864516373490594862) {
  H_28(state, unused, out_2864516373490594862);
}
void car_h_31(double *state, double *unused, double *out_1547637643552350599) {
  h_31(state, unused, out_1547637643552350599);
}
void car_H_31(double *state, double *unused, double *out_5178393080350112799) {
  H_31(state, unused, out_5178393080350112799);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_init(car);
