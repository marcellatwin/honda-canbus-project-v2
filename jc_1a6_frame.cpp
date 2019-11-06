/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 6 Nov 2019
 *
 * jc_1a6_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 1a6
 */

// Corresponding header file
#include "jc_1a6_frame.h"

// Set static frame ID
canid_t CAN_frame_1a6::frame_id = 0x1a6;

// Constructor that set initial values for throttle data
CAN_frame_1a6::CAN_frame_1a6()
{
    // Set initial values of converted data
    string headlights = "Not sure";
    bool ebrake_status = false;
    bool cruise_cont_main_status = false;
    bool cruise_cont_main_button = false;
    bool cruise_cont_cancel_button = false;
    bool cruise_cont_set_deaccel_button = false;
    bool cruise_cont_reset_accel_button = false;
    bool ac_compressor_status = false;
    bool reverse_status = false;
}

void CAN_frame_1a6::convert_frame(struct can_frame & frame)
{

//// CHECK OLD MAIN FOR BIT CONVERSIONS /////////////////////////////////
    headlights = ((frame.data[0] << 8) + (frame.data[1])) / 655.35;
    
    rpm_1 = (frame.data[2] << 8) + (frame.data[3]);

    if (frame.data[4] == 0x48)
        cruise_cont_active_status = true;
    else
        cruise_cont_active_status = false;

    if (frame.data[6] == 0x20)
        brake_status = true;
    else
        brake_status = false;
//// CHECK OLD MAIN FOR BIT CONVERSIONS /////////////////////////////////

}

canid_t CAN_frame_1a6::get_class_ID(void)
{
    return frame_id;
}

float CAN_frame_1a6::get_throttle_pedal(void)
{
    return throttle_pedal;
}


    string get_headlights(void);
    bool get_ebrake_status(void);
    bool get_cruise_control_main_status(void);
    bool get_cruise_control_main_button(void);
    bool get_cruise_control_cancel_button(void);
    bool get_cruise_control_set_deaccel_button(void);
    bool get_cruise_control_reset_accel_button(void);
    bool get_ac_compressor_status(void);
    bool get_reverse_status(void);