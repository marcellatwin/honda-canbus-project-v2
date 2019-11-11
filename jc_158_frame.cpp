/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 3 Nov 2019
 *
 * jc_158_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 158
 */

// Corresponding header file
#include "jc_158_frame.h"

// Set static frame ID
canid_t CAN_frame_158::frame_id = 0x158;

// Constructor that set initial values
CAN_frame_158::CAN_frame_158()
{
	// Set initial values of converted data
    speed_1 = 0;
    speed_2 = 0;
}

void CAN_frame_158::convert_frame(struct can_frame & frame)
{
	speed_1 = ((frame.data[0] << 8) + (frame.data[1])) / 160;
	speed_2 = ((frame.data[4] << 8) + (frame.data[5])) / 160;
}

canid_t CAN_frame_158::get_class_ID(void)
{
	return frame_id;
}

float CAN_frame_158::get_speed_1(void)
{
	return speed_1;
}

float CAN_frame_158::get_speed_2(void)
{
	return speed_2;
}
