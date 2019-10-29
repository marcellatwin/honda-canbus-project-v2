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
	cout << "Test" << endl;
	// Set up socket and CAN frame
	CAN_socket sock;
	cout << "Test2" << endl;
	struct can_frame frame;
	cout << "Test3" << endl;

	for (int i = 0; i < 10; i++)
	{
		// Get a frame to test
		frame = sock.read_frame(frame);

		// Display
		cout << frame.can_id << " " << frame.data << endl;
	}
}