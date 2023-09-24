#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_113052499138860728);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_964570142091074406);
void gnss_H_mod_fun(double *state, double *out_6748758134973358957);
void gnss_f_fun(double *state, double dt, double *out_4985336149056058800);
void gnss_F_fun(double *state, double dt, double *out_7057326551453181267);
void gnss_h_6(double *state, double *sat_pos, double *out_7101442657733273071);
void gnss_H_6(double *state, double *sat_pos, double *out_1205373226368180211);
void gnss_h_20(double *state, double *sat_pos, double *out_1238762562760675251);
void gnss_H_20(double *state, double *sat_pos, double *out_8839818693546915909);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_3851795894157492390);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_4685923984777977273);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_3851795894157492390);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_4685923984777977273);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}