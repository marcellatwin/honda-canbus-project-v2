/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *
 * jc_CAN_socket.cpp
 * Cpp file for connecting to socket
 */

// Corresponding header file
#include "jc_CAN_socket.h"

using namespace std;

// Constructor that sets up the socket
CAN_socket::CAN_socket()
{
	// Set the file descriptor for the socket
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (s == -1)
	{
		perror("Error with setting up socket file descriptor: ");
		sock_error = true;
	}
	else
	{
		// Set the name of the socket/CAN interface
		strcpy(ifr.ifr_name, "can0");

		// Find the address of the socket
		if (ioctl(s, SIOCGIFINDEX, &ifr) == -1)
		{
			perror("Error with control device (SIOCGIFINDEX): ");
			sock_error = true;
		}
		else
		{
			// Set the address of the socket
			addr.can_family = AF_CAN;
			addr.can_ifindex = ifr.ifr_ifindex;
			
			// Set the options of the socket
			//setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
			//fcntl(s, F_SETFL, O_NONBLOCK);

			// Bind the socket and address
			if (bind(s, (struct sockaddr*) &addr, sizeof(addr)) < 0)
			{
				perror("Error with binding socket address: ");
				sock_error = true;
			}
		}
	}
}

// Destructor that will close the file descriptor for the socket
CAN_socket::~CAN_socket()
{
	close(s);
	cout << endl << "Destructor, closing s, ending program!" << endl;
}

// Returns the state of the error variable
bool CAN_socket::socket_error()
{
	return sock_error;
}

// Reads the CAN bus and places it in a can_frame struct
struct can_frame CAN_socket::read_frame(struct can_frame &frame)
{
	if (read(s, &frame, sizeof(struct can_frame)) < 0)
	{
		sock_error = true;
		cout << "Error reading CAN bus" << endl;
	}
	
	return frame;
}