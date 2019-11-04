/*****************************************************************************/
/* 
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 * 
 * jc_main.cpp
 * Main file for running CAN bus program
 */

// Standard libraries
#include <iostream>

// Socket class library
#include "jc_CAN_socket.h"

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Children class libraries for CAN frames
#include "jc_13c_frame.h"
#include "jc_17c_frame.h"

// Supporting header file for printing
#include "jc_text_printing.h"

using namespace std;

int main(void)
{
	// Set up socket and CAN frame
	CAN_socket sock;
	struct can_frame frame;

	// Set up CAN message classes
	CAN_frame_13c frame_13c;
	CAN_frame_158 frame_158;
	CAN_frame_17c frame_17c;

	// For testing ///////////////////////////////////////
	bool quit_var = false;

	if (!sock.socket_error())
	{
		// Start up ncurses window
		start_text_dash();
		text_dash_titles();

		while (!quit_var)
		{
			// Get a frame to test
			frame = sock.read_frame(frame);

			// Break out if there's an error with reading the CAN bus
			if(sock.socket_error())
				break;

			// Switch case for each decoded frame 
			if (frame.can_id == frame_13c.get_class_id())
				frame_13c.convert_frame(frame);
			else if (frame.can_id == frame_158.get_class_id())
				frame_158.convert_frame(frame);
			else if (frame.can_id == frame_17c.get_class_id())
				frame_17c.convert_frame(frame);

			// For testing ////////////////////////
			text_dash_data();
			/*
			frame_13c.print_test();
			frame_158.print_test();
			frame_17c.print_test();
			*/
			
			// For testing /////////////////////////////////////////
			// Determind wheather to keep running or not
			if (getch() == 'q')
				quit_var = true;

		}

		// Shut down ncurses window
		end_text_dash();
	}
	else
		cout << "Socket not set up correctly." << endl;
}