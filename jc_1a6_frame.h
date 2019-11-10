/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 6 Nov 2019
 *
 * jc_1a6_frame.h
 * Header file for child class of converted CAN messages, the frame 1a6
 */

#ifndef JC_1A6_FRAME_H
#define JC_1A6_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

// Library and namespace for strings
#include <string>
using namespace std;

class CAN_frame_1a6 : public Converted_CAN_Data
{
private:
    static canid_t frame_id;

    string headlights;
    bool ebrake_status;
    bool cruise_cont_main_status;
    bool cruise_cont_main_button;
    bool cruise_cont_cancel_button;
    bool cruise_cont_set_deaccel_button;
    bool cruise_cont_reset_accel_button;
    bool ac_compressor_status;
    bool reverse_status;

public:
    CAN_frame_1a6();
    canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    string get_headlights(void);
    bool get_ebrake_status(void);
    bool get_cruise_control_main_status(void);
    bool get_cruise_control_main_button(void);
    bool get_cruise_control_cancel_button(void);
    bool get_cruise_control_set_deaccel_button(void);
    bool get_cruise_control_reset_accel_button(void);
    bool get_ac_compressor_status(void);
    bool get_reverse_status(void);
};

#endif
