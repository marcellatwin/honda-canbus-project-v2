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

using namespace std;

// Set static frame ID
canid_t CAN_frame_17c::frame_id = 0x17c;

// Constructor that set initial values for throttle data
CAN_frame_17c::CAN_frame_17c()
{
	
	// Set initial values of converted data
    throttle_pedal = 0;

    brake_status = false;
    cruise_cont_active_flag = false;

}

void CAN_frame_17c::convert_frame(struct can_frame & frame)
{

	throttle_pedal = ((frame.data[0] << 8) + (frame.data[1])) / 654;

	if (frame.data[4] == 0x48)
		cruise_cont_active_flag = true;
	else
		cruise_cont_active_flag = false;


	if (frame.data[6] == 0x20)
		brake_status = true;
	else
		brake_status = false;


}

canid_t CAN_frame_17c::get_class_id(void)
{
	return frame_id;
}

// For TESTING /////////////////////////////////////////////
void CAN_frame_17c::print_test(void)
{
	mvprintw(6, 1, "Throttle pedal: %.1f", throttle_pedal);
	clrtoeol();
	mvprintw(7, 1, "Cruise Control Active: %s", cruise_cont_active_flag ? "Active" : "Inactive");
	clrtoeol();
	mvprintw(8, 1, "Clutch: %s", brake_status ? "On" : "Off");
	clrtoeol();
}