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

using namespace std;

// Set static frame ID
canid_t CAN_frame_158::frame_id = 0x158;

// Constructor that set initial values for throttle data
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

canid_t CAN_frame_158::get_class_id(void)
{
	return frame_id;
}

// For TESTING /////////////////////////////////////////////
/*
void CAN_frame_158::print_test(void)
{
	mvprintw(11, TITLE_COLM, "Speed 1: %.1f", speed_1);
	clrtoeol();
	mvprintw(12, TITLE_COLM, "Speed 2: %.1f", speed_2);
	clrtoeol();
	
}
*/