/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 31 Oct 2019
 *
 * jc_13c_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 13c
 */

// Corresponding header file
#include "jc_13c_frame.h"

//using namespace std;

// Set static frame ID
canid_t CAN_frame_13c::frame_id = 0x13c;

// Constructor that set initial values for throttle data
CAN_frame_13c::CAN_frame_13c()
{
	
	// Set initial values of converted data
    throttle_command = 0;
    throttle_plate = 0;
    
    // VERIFY THIS DECODE
    load_command = 0.0;
    
    clutch_status = false;
}

void CAN_frame_13c::convert_frame(struct can_frame & frame)
{

	// Scaling needs fixing !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	throttle_command = (frame.data[2] << 8) + (frame.data[3]);
	throttle_plate = (frame.data[0] << 8) + (frame.data[1]);

	// VERIFY THIS DECODE ////////////////////////////////////////////
	load_command = frame.data[4] / 2.56;

	// This may change, if 3, 2, or 1 is discovered, consider change
	// for safety critical if needed
	if (frame.data[6] == 0x04)
		clutch_status = false;
	else 
		clutch_status = true;
}

canid_t CAN_frame_13c::get_class_ID(void)
{
	return frame_id;
}

int CAN_frame_13c::get_throttle_command(void)
{
	return throttle_command;
}

int CAN_frame_13c::get_throttle_plate(void)
{
	return throttle_plate;
}

float CAN_frame_13c::get_load_command(void)
{
	return load_command;
}

bool CAN_frame_13c::get_clutch_status(void)
{
	return clutch_status;
}
