/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 6 Nov 2019
 *
 * jc_1a4_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 1a4
 */

// Corresponding header file
#include "jc_1a4_frame.h"

// Set static frame ID
canid_t CAN_frame_1a4::frame_id = 0x1a4;

// Constructor that set initial values
CAN_frame_1a4::CAN_frame_1a4()
{
	// Set initial values of converted data
    brake_pedal = 0.0;
}

void CAN_frame_1a4::convert_frame(struct can_frame & frame)
{
	// NEED TO FIGURE OUT SCALING//////////////////////////////////
	brake_pedal = ((frame.data[0] << 8) + (frame.data[1]));
}

canid_t CAN_frame_1a4::get_class_ID(void)
{
	return frame_id;
}

float CAN_frame_1a4::get_brake_pedal(void)
{
	return brake_pedal;
}
