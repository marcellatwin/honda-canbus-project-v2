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

//using namespace std;

// Set static frame ID
canid_t CAN_frame_17c::frame_id = 0x17c;

// Constructor that set initial values for throttle data
CAN_frame_17c::CAN_frame_17c()
{
	
	// Set initial values of converted data
    throttle_pedal = 0;

	// Consider making an int??????????????????????????????????
    rpm_1 = 0;

    cruise_cont_active_flag = false;
    brake_status = false;
}

void CAN_frame_17c::convert_frame(struct can_frame & frame)
{

	// Try different scaling ??????????????????????????????????????????
	//throttle_pedal = ((frame.data[0] << 8) + (frame.data[1])) / 654;
	throttle_pedal = ((frame.data[0] << 8) + (frame.data[1])) / 655.35;
	
	// Consider making an int??????????????????????????????????
	rpm_1 = (frame.data[2] << 8) + (frame.data[3]);

	if (frame.data[4] == 0x48)
		cruise_cont_active_flag = true;
	else
		cruise_cont_active_flag = false;

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

float CAN_frame_17c::get_rpm_1(void)
{
	return rpm_1;
}

bool CAN_frame_17c::get_cruise_cont_active_flag(void)
{
	return cruise_cont_active_flag;
}

bool CAN_frame_17c::get_brake_status(void)
{
	return brake_status;
}

// For TESTING /////////////////////////////////////////////
/*
void CAN_frame_17c::print_test(void)
{
	mvprintw(6, TITLE_COLM, "Throttle pedal: %.1f", throttle_pedal);
	clrtoeol();
	mvprintw(7, TITLE_COLM, "Cruise Control Active: %s", cruise_cont_active_flag ? "Active" : "Inactive");
	clrtoeol();
	mvprintw(8, TITLE_COLM, "Brake: %s", brake_status ? "On" : "Off");
	clrtoeol();
	mvprintw(9, TITLE_COLM, "RPM 1: %.1f", rpm_1);
	clrtoeol();
}
*/