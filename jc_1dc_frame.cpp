/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 10 Nov 2019
 *
 * jc_1dc_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 1dc
 */

// Corresponding header file
#include "jc_1dc_frame.h"

// Set static frame ID
canid_t CAN_frame_1dc::frame_id = 0x1dc;

// Constructor that set initial values
CAN_frame_1dc::CAN_frame_1dc()
{
	// Set initial values of converted data
    rpm_2 = 0;
}

void CAN_frame_1dc::convert_frame(struct can_frame & frame)
{
	rpm_2 = ((frame.data[1] << 8) + (frame.data[2]));
}

canid_t CAN_frame_1dc::get_class_ID(void)
{
	return frame_id;
}

int CAN_frame_1dc::get_rpm_2(void)
{
	return rpm_2;
}
