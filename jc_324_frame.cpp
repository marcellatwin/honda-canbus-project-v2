/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 6 Nov 2019
 *
 * jc_324_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 324
 */

// Corresponding header file
#include "jc_324_frame.h"

// Set static frame ID
canid_t CAN_frame_324::frame_id = 0x324;

// Constructor that set initial values for throttle data
CAN_frame_324::CAN_frame_324()
{
    // Set initial values of converted data
    water_temp = 0.0;
    intake_temp = 0.0;
}

void CAN_frame_324::convert_frame(struct can_frame & frame)
{
    water_temp = frame.data[0] - 40;
    intake_temp = frame.data[1] - 40;
}

canid_t CAN_frame_324::get_class_ID(void)
{
    return frame_id;
}

float CAN_frame_324::get_water_temp(void)
{
    return water_temp;
}

float CAN_frame_324::get_intake_temp(void)
{
    return intake_temp;
}