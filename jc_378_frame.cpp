/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 11 Nov 2019
 *
 * jc_378_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 378
 */

// Corresponding header file
#include "jc_378_frame.h"

// Set static frame ID
canid_t CAN_frame_378::frame_id = 0x378;

// Constructor that set initial values
CAN_frame_378::CAN_frame_378()
{
	// Set initial values of converted data
    fuel_tank_level = 0.0;
}

void CAN_frame_378::convert_frame(struct can_frame & frame)
{
	//// CHECK SCALING/////////////////////////////////////////////////////
	fuel_tank_level = ((frame.data[4] << 8) + frame.data[5]) / 1000;
}

canid_t CAN_frame_378::get_class_ID(void)
{
	return frame_id;
}

float CAN_frame_378::get_fuel_tank_level(void)
{
	return fuel_tank_level;
}
