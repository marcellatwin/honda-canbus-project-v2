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

	for (int i = 0; i < 10; i++)
	{
		// Get a frame to test
		frame = sock.read_frame(frame);

		// Display
		cout << "ID: " << frame.can_id << "  Data: " << frame.data << endl;
	}
}