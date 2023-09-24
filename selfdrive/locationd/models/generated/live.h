#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_5931037656412210587);
void live_err_fun(double *nom_x, double *delta_x, double *out_238307230270618879);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6996259531543842646);
void live_H_mod_fun(double *state, double *out_8148689651805700146);
void live_f_fun(double *state, double dt, double *out_902112657953448943);
void live_F_fun(double *state, double dt, double *out_8903580631120383034);
void live_h_4(double *state, double *unused, double *out_7028545921639587217);
void live_H_4(double *state, double *unused, double *out_4535428380652713976);
void live_h_9(double *state, double *unused, double *out_302101887128481646);
void live_H_9(double *state, double *unused, double *out_2751790554611733494);
void live_h_10(double *state, double *unused, double *out_7103874480815483869);
void live_H_10(double *state, double *unused, double *out_79742523300234424);
void live_h_12(double *state, double *unused, double *out_4435864690509638899);
void live_H_12(double *state, double *unused, double *out_7530057316014104644);
void live_h_35(double *state, double *unused, double *out_2551716309463514366);
void live_H_35(double *state, double *unused, double *out_8171123725370433263);
void live_h_32(double *state, double *unused, double *out_8595242243604104642);
void live_H_32(double *state, double *unused, double *out_2369819353162820705);
void live_h_13(double *state, double *unused, double *out_1530891615425827232);
void live_H_13(double *state, double *unused, double *out_986548921908989728);
void live_h_14(double *state, double *unused, double *out_302101887128481646);
void live_H_14(double *state, double *unused, double *out_2751790554611733494);
void live_h_33(double *state, double *unused, double *out_3412008473235288356);
void live_H_33(double *state, double *unused, double *out_5020566720731575659);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}