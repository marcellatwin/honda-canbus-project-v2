/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 11 Nov 2019
 *
 * jc_377_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 377
 */

// Corresponding header file
#include "jc_377_frame.h"

// Set static frame ID
canid_t CAN_frame_377::frame_id = 0x377;

// Constructor that set initial values
CAN_frame_377::CAN_frame_377()
{
	// Set initial values of converted data
    fuel_consumption_gauge = 0.0;
}

void CAN_frame_377::convert_frame(struct can_frame & frame)
{
	//// CHECK SCALING/////////////////////////////////////////////////////
	fuel_consumption_gauge =  frame.data[0] / 2;
}

canid_t CAN_frame_377::get_class_ID(void)
{
	return frame_id;
}

float CAN_frame_377::get_fuel_consumption_gauge(void)
{
	return fuel_consumption_gauge;
}
