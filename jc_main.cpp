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
//#include "jc_converted_CAN_data.h"
#include "jc_decoded_frame.h"

// Supporting header file for printing
#include "jc_text_printing.h"

// Class header file for logging
#include "jc_logger.h"

using namespace std;

//g++ -Wall -Wextra -O3 src/jc_main.cpp src/jc_CAN_socket.cpp src/jc_text_printing.cpp src/jc_decoded_frame.cpp src/jc_logger.cpp src/jc_13c_frame.cpp src/jc_158_frame.cpp src/jc_17c_frame.cpp src/jc_1a4_frame.cpp src/jc_1a6_frame.cpp src/jc_1d0_frame.cpp src/jc_1dc_frame.cpp src/jc_320_frame.cpp src/jc_324_frame.cpp src/jc_377_frame.cpp src/jc_378_frame.cpp -lncurses

int main(void)
{
	// Setup logging for errors - FOR LATER
	//Logger error_log("error_log");
	// WRITE TO ERROR LOG - time of starting!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Set up socket and CAN frame
	CAN_socket sock;
	struct can_frame raw_frame;

	// Set up CAN message classes
	Decoded_frame decoded_frame;

	// For NOW ///////////////////////////////////////
	bool quit_var = false;
	int loop_counter = 0;
	
	// Set up outout class - FOR LATER
	/*
	Output output;
	output.setup(TEXT, &decoded_frame);
	output.setup(GUI, &decoded_frame);
	*/
	
	// Set up data log
	//Logger data_log("data_log") - FOR LATER
	Logger data_log;
	data_log.log_titles();

	// Testing/////////////////////////////////////////////
	//cout << "socket: " << sock.socket_error() << endl;
	//cout << "logger: " << data_log.logger_error() << endl;

	// Made just for C++ class project
	try
	{

		if (!sock.socket_error() && !data_log.logger_error())
		{
			// Start up ncurses window
			start_text_dash();
			print_dash_titles_text();

			while (!quit_var)
			{
				// Read in a frame and send it for processing
				raw_frame = sock.read_frame(raw_frame);
				decoded_frame.new_frame(raw_frame);

				// Print out the results
				print_dash_data_text(decoded_frame, data_log);
				//output.update() - FOR LATER

				// Determind when to log data
				if (getch() == 'l')
					data_log.log_start_stop();
				

				if (data_log.get_log_status())
				{
					// Increment loop counter
					loop_counter++;

					if ((loop_counter % 100) == 0)
						data_log.log_current(decoded_frame, sock);
				}

				// For NOW /////////////////////////////////////////
				// Determind wheather to keep running by way of user input or
				// an error with reading the CAN bus
				if (getch() == 'q' || sock.socket_error() || data_log.logger_error())
				{
					quit_var = true;

					// Made just for C++ class project
					throw quit_var;
				}
				// WRITE TO ERROR LOG - time of ending!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			}

			// Shut down ncurses window
			end_text_dash();
		}
		else
			cout << "Socket or logger not set up correctly." << endl;
	}

	// Made just for C++ class project
	catch (bool quit_var)
	{
		// Shut down ncurses window
		end_text_dash();
		cout << endl << "Socket error, Logger error, or 'q' pressed" << endl;
	}

	// Made just for C++ class project
	cout << endl << "Total run time:  ";
	cout << sock << endl;

	return 0;
}