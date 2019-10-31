/*****************************************************************************/
/* 
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 * 
 * jc_main.cpp
 * Main file for running CAN bus program
 */

// Socket class library
#include "jc_CAN_socket.h"

// Parent class library
#include "jc_converted_CAN_data.h"

// Standard libraries
#include <iostream>

using namespace std;

int main(void)
{
	// Set up socket and CAN frame
	CAN_socket sock;
	struct can_frame frame;

	// For testing
	int count = 0;

	if (!sock.socket_error())
	{
		while (count < 20)
		{
			// Get a frame to test
			frame = sock.read_frame(frame);

			// Break out if there's an error with reading the CAN bus
			if(sock.socket_error())
				break;

			if (frame.can_id == 0x17c)
			{
				float throttle = ((frame.data[0] << 8) + (frame.data[1])) / 654;
				// Display
				cout << "ID: " << hex << frame.can_id << "  Data: " << throttle << endl;

				count++;
			}
		}
	}
	else
		cout << "Socket not set up correctly." << endl;
}