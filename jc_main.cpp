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

// Class header files for converting CAN data
#include "jc_converted_CAN_data.h"
#include "jc_decoded_frame.h"

// Supporting header file for printing
#include "jc_text_printing.h"

using namespace std;

//g++ -Wall -Wextra -O3 src/jc_main.cpp src/jc_CAN_socket.cpp src/jc_text_printing.cpp src/jc_decoded_frame.cpp src/jc_13c_frame.cpp src/jc_158_frame.cpp src/jc_17c_frame.cpp src/jc_1a4_frame.cpp src/jc_1a6_frame.cpp -lncurses

int main(void)
{
	// Set up socket and CAN frame
	CAN_socket sock;
	struct can_frame frame;

	// Set up CAN message classes
	Decoded_frame decoded_frame;

	// For testing ///////////////////////////////////////
	bool quit_var = false;

	if (!sock.socket_error())
	{
		// Start up ncurses window
		start_text_dash();
		print_dash_titles_text();

		while (!quit_var)
		{
			// Get a frame to test
			frame = sock.read_frame(frame);

			// Break out if there's an error with reading the CAN bus
			if(sock.socket_error())
				break;

			decoded_frame.new_frame(frame);

			print_dash_data_text(decoded_frame);

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