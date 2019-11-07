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
    headlights = "Not sure...";
    ebrake_status = false;
    cruise_cont_main_status = false;
    cruise_cont_main_button = false;
    cruise_cont_cancel_button = false;
    cruise_cont_set_deaccel_button = false;
    cruise_cont_reset_accel_button = false;
    ac_compressor_status = false;
    reverse_status = false;
}

void CAN_frame_1a6::convert_frame(struct can_frame & frame)
{

    if ((frame.data[0] & 0x0F) == 0x00 || (frame.data[0] & 0x0F) == 0x04)
        headlights = "Off";
    else if ((frame.data[0] & 0x0F) == 0x01 || (frame.data[0] & 0x0F) == 0x05)
        headlights = "Parking";
    else if ((frame.data[0] & 0x0F) == 0x02 || (frame.data[0] & 0x0F) == 0x06)
        headlights = "LOW Beams";
    else if ((frame.data[0] & 0x0F) == 0x03 || (frame.data[0] & 0x0F) == 0x07)
        headlights = "HIGH Beams";
    else
        headlights = "Not sure...";

    if ((frame.data[0] & 0x0F) >= 0x04)
        ebrake_status = true;
    else
        ebrake_status = false;
    

    if ((frame.data[5] >> 4) == 0x08)
        cruise_cont_main_status = true;
    else
        cruise_cont_main_status = false;

    if ((frame.data[0] >> 4) == 0x02)
        cruise_cont_main_button = true;
    else
        cruise_cont_main_button = false;

    if ((frame.data[0] >> 4) == 0x04)
        cruise_cont_cancel_button = true;
    else
        cruise_cont_cancel_button = false;

    if ((frame.data[0] >> 4) == 0x06)
        cruise_cont_set_deaccel_button = true;
    else
        cruise_cont_set_deaccel_button = false;

    if ((frame.data[0] >> 4) == 0x08)
        cruise_cont_reset_accel_button = true;
    else
        cruise_cont_reset_accel_button = false;


    if ((frame.data[2] >> 4) == 0x04)
        ac_compressor_status = true;
    else
        ac_compressor_status = false;

    if ((frame.data[2] & 0x0F) == 0x04)
        reverse_status = true;
    else
        reverse_status = false;
}

canid_t CAN_frame_1a6::get_class_ID(void)
{
    return frame_id;
}

string CAN_frame_1a6::get_headlights(void)
{
    return headlights;
}

bool CAN_frame_1a6::get_ebrake_status(void)
{
    return ebrake_status;
}

bool CAN_frame_1a6::get_cruise_control_main_status(void)
{
    return cruise_cont_main_status;
}

bool CAN_frame_1a6::get_cruise_control_main_button(void)
{
    return cruise_cont_main_button;
}

bool CAN_frame_1a6::get_cruise_control_cancel_button(void)
{
    return cruise_cont_cancel_button;
}

bool CAN_frame_1a6::get_cruise_control_set_deaccel_button(void)
{
    return cruise_cont_set_deaccel_button;
}

bool CAN_frame_1a6::get_cruise_control_reset_accel_button(void)
{
    return cruise_cont_reset_accel_button;
}

bool CAN_frame_1a6::get_ac_compressor_status(void)
{
    return ac_compressor_status;
}

bool CAN_frame_1a6::get_reverse_status(void)
{
    return reverse_status;
}
