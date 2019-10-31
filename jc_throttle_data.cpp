/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_throttle_data.cpp
 * Cpp file for child class of converted CAN messages, throttle data
 */

// Corresponding header file
#include "jc_throttle_data.h"

// Supporting header file
#include "jc_text_printing.h"

using namespace std;

// Constructor that set initial values for throttle data
Throttle_Data::Throttle_Data()
{
	// Set frame IDs related to throttle data
	message_id[] = 0x13c, 0x17c;
	
	// Set initial values of converted data
	throttle_pedal = 0;
    throttle_cutout_flag = false;
    throttle_command = 0;
    throttle_plate = 0;

    //reprint_var = false;
}

void Throttle_Data::convert_message(struct can_frame &)
{
	//
	throttle_pedal = ((frame.data[0] << 8) + (frame.data[1])) / 654;

	

	// Determind throttle flag for exhaust cutout
	if (throttle_pedal > 75)
		throttle_cutout_flag = true;
	else
		throttle_cutout_flag = false;
}

int& Throttle_Data::initial_title_text(int & row)
{
	mvprintw(row++, TITLE_COLM, "Throttle Pedal (%%):");
	mvprintw(row++, TITLE_COLM, "Throttle Command (%%):");
	mvprintw(row++, TITLE_COLM, "Throttle Plate (%%):");
	mvprintw(row++, TITLE_COLM, "Throttle Flag:");
	row++;

	return row;
}