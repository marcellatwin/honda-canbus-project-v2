/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 31 Oct 2019
 *
 * jc_17c_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 17c
 */

// Corresponding header file
#include "jc_17c_frame.h"

// Set static frame ID
canid_t CAN_frame_17c::frame_id = 0x17c;

// Constructor that set initial values
CAN_frame_17c::CAN_frame_17c()
{
	
	// Set initial values of converted data
    throttle_pedal = 0.0;
    rpm_1 = 0;

    cruise_cont_active_status = false;
    brake_status = false;
}

void CAN_frame_17c::convert_frame(struct can_frame & frame)
{

	// Try different scaling ??????????????????????????????????????????
	//throttle_pedal = ((frame.data[0] << 8) + (frame.data[1])) / 654;
	throttle_pedal = ((frame.data[0] << 8) + (frame.data[1])) / 655.35;
	
	rpm_1 = (frame.data[2] << 8) + (frame.data[3]);

	if (frame.data[4] == 0x48)
		cruise_cont_active_status = true;
	else
		cruise_cont_active_status = false;

	if (frame.data[6] == 0x20)
		brake_status = true;
	else
		brake_status = false;
}

canid_t CAN_frame_17c::get_class_ID(void)
{
	return frame_id;
}

float CAN_frame_17c::get_throttle_pedal(void)
{
	return throttle_pedal;
}

int CAN_frame_17c::get_rpm_1(void)
{
	return rpm_1;
}

bool CAN_frame_17c::get_cruise_cont_active_status(void)
{
	return cruise_cont_active_status;
}

bool CAN_frame_17c::get_brake_status(void)
{
	return brake_status;
}
