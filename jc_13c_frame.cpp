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

using namespace std;

// Set static frame ID
canid_t CAN_frame_13c::frame_id = 0x13c;

// Constructor that set initial values for throttle data
CAN_frame_13c::CAN_frame_13c()
{
	
	// Set initial values of converted data
    throttle_command = 0;
    throttle_plate = 0;
    clutch_status = false;

    // VERIFY THIS DECODE
    load_command = 0;
}

void CAN_frame_13c::convert_frame(struct can_frame & frame)
{
	// This may change, if 3, 2, or 1 is discovered, consider change
	// for safety critical if needed
	if (frame.data[6] == 0x04)
		clutch_status = false;
	else 
		clutch_status = true;

	// Scaling needs fixing !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	throttle_plate = (frame.data[0] << 8) + (frame.data[1]);
	throttle_command = (frame.data[2] << 8) + (frame.data[3]);

	// VERIFY THIS DECODE ////////////////////////////////////////////
	load_command = frame.data[4] / 2.56;

}

canid_t CAN_frame_13c::get_class_id(void)
{
	return frame_id;
}

// For TESTING /////////////////////////////////////////////
void CAN_frame_13c::print_test(void)
{
	mvprintw(1, 1, "Throttle Comm: %.1f", throttle_command);
	clrtoeol();
	mvprintw(2, 1, "Throttle plate: %.1f", throttle_plate);
	clrtoeol();
	mvprintw(3, 1, "Load Comm: %.1f", load_command);
	clrtoeol();
	mvprintw(4, 1, "Clutch: %s", clutch_status ? "In" : "Out");
	clrtoeol();
}