/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 10 Nov 2019
 *
 * jc_1d0_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 1d0
 */

// Corresponding header file
#include "jc_1d0_frame.h"

// Set static frame ID
canid_t CAN_frame_1d0::frame_id = 0x1d0;

// Constructor that set initial values for speed data
CAN_frame_1d0::CAN_frame_1d0()
{
	// Set initial values of converted data
    speed_3 = 0.0;
}

void CAN_frame_1d0::convert_frame(struct can_frame & frame)
{
	speed_3 = ((frame.data[0] << 8) + (frame.data[1]));
}

canid_t CAN_frame_1d0::get_class_ID(void)
{
	return frame_id;
}

float CAN_frame_1d0::get_speed_3(void)
{
	return speed_3;
}
