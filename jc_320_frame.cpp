/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 10 Nov 2019
 *
 * jc_320_frame.cpp
 * Cpp file for child class of converted CAN messages, frame 320
 */

// Corresponding header file
#include "jc_320_frame.h"

// Set static frame ID
canid_t CAN_frame_320::frame_id = 0x320;

// Constructor that set initial values
CAN_frame_320::CAN_frame_320()
{
	// Set initial values of converted data
    vtec_status = false;
}

void CAN_frame_320::convert_frame(struct can_frame & frame)
{
	if ((frame.data[1] >> 4) == 0x04)
        vtec_status = true;
    else
        vtec_status = false;
}

canid_t CAN_frame_320::get_class_ID(void)
{
	return frame_id;
}

bool CAN_frame_320::get_vtec_status(void)
{
	return vtec_status;
}
