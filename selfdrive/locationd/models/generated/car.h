#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8224710768753384870);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6195700753239379980);
void car_H_mod_fun(double *state, double *out_5375910394241702470);
void car_f_fun(double *state, double dt, double *out_1448099311491195891);
void car_F_fun(double *state, double dt, double *out_523140851368550509);
void car_h_25(double *state, double *unused, double *out_1704824311903479744);
void car_H_25(double *state, double *unused, double *out_810681659242705099);
void car_h_24(double *state, double *unused, double *out_6014661257652399328);
void car_H_24(double *state, double *unused, double *out_8417383526826490126);
void car_h_30(double *state, double *unused, double *out_2235331708922326722);
void car_H_30(double *state, double *unused, double *out_5338377989370313297);
void car_h_26(double *state, double *unused, double *out_3178841561823989157);
void car_H_26(double *state, double *unused, double *out_4552184978116761323);
void car_h_27(double *state, double *unused, double *out_7091485152362517396);
void car_H_27(double *state, double *unused, double *out_3114783918186370080);
void car_h_29(double *state, double *unused, double *out_5199811725506374091);
void car_H_29(double *state, double *unused, double *out_4828146645055921113);
void car_h_28(double *state, double *unused, double *out_8939578826838322736);
void car_H_28(double *state, double *unused, double *out_2864516373490594862);
void car_h_31(double *state, double *unused, double *out_1547637643552350599);
void car_H_31(double *state, double *unused, double *out_5178393080350112799);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}