/*****************************************************************************/
/* 
 * jc_main.cpp
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *         
 */

// Socket class object library
#include "jc_CAN_socket.h"

// Standard libraries
#include <iostream>

using namespace std;

int main(void)
{
	// Set up socket and CAN frame
	CAN_socket sock;
	struct can_frame frame;

	int count = 0;

	if (!sock.socket_error())
	{
		//for (int i = 0; i < 20; i++)
		while (count < 20)
		{
			// Get a frame to test
			frame = sock.read_frame(frame);

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
		cout << "Socket not set up, ending program" << endl;
}