/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 5 Nov 2019
 *
 * jc_decoded_frame.cpp
 * Cpp file for class of decoded CAN frames where each converted CAN class
 *  lives
 */

// Corresponding header file
#include "jc_decoded_frame.h"

//using namespace std;

// Constructor that set
Decoded_frame::Decoded_frame()
{
	//array_size = 0;

	// Create CAN frame classes fill the frame ID array
	//CAN_frame_13c frame_13c;
	//frame_ID_array[array_size] = frame_13c.get_class_ID();
	frame_IDs.push_back(frame_13c.get_class_ID());

	//CAN_frame_158 frame_158;
	//frame_ID_array[array_size++] = frame_158.get_class_ID();
	frame_IDs.push_back(frame_158.get_class_ID());

	//CAN_frame_17c frame_17c;
	//frame_ID_array[array_size++] = frame_17c.get_class_ID();
	frame_IDs.push_back(frame_17c.get_class_ID());

	frame_IDs.push_back(frame_1a4.get_class_ID());

}


void Decoded_frame::new_frame(struct can_frame & new_frame)
{
	// Get new time and delta
	//new_time = ;
	//delta_time = new_time - old_time;

	// Compare ID vector to each CAN frame ID
	for (unsigned int i = 0; i < frame_IDs.size(); i++)
	//for (int i = 0; i < array_size; i++)
	{
		//if (new_frame.can_id == frame_13c.get_class_ID())
		if (new_frame.can_id == frame_13c.get_class_ID())
			frame_13c.convert_frame(new_frame);

		//else if (new_frame.can_id == frame_158.get_class_ID())
		else if (new_frame.can_id == frame_158.get_class_ID())
			frame_158.convert_frame(new_frame);

		//else if (new_frame.can_id == frame_17c.get_class_ID())
		else if (new_frame.can_id == frame_17c.get_class_ID())
			frame_17c.convert_frame(new_frame);

		else if (new_frame.can_id == frame_1a4.get_class_ID())
			frame_1a4.convert_frame(new_frame);
	}

	// Update time
	//old_time = new_time;

}

