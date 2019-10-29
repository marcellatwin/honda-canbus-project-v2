/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *
 * jc_CAN_socket.cpp
 * Header file for connecting to socket
 */

#include "jc_CAN_socket.h"

using namespace std;

CAN_socket::CAN_socket()
{
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (s == -1)
	{
		cout << "Error creating endpoint for socket communication";
		sock_error = true;
	}
	else
	{
		//ifr.ifr_name = "can0";
		strcpy(ifr.ifr_name, "can0");
		addr.can_family = AF_CAN;

		// Do something with control device
		if (ioctl(s, SIOCGIFINDEX, ifr) == -1)
		{
			cout << "Error with control device (SIOCGIFINDEX)";
			sock_error = true;
		}
		else
		{
			// Do some more with structs and something with the CPU socket
			addr.can_ifindex = ifr.ifr_ifindex;
			setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);

			//if (bind(s, (struct sockaddr*) addr, sizeof(addr)) == -1)
			if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) == -1)
			{
				cout << "Error with binding socket address";
				sock_error = true;
			}
		}
	}
}

bool CAN_socket::socket_error()
{
	return sock_error;
}

struct can_frame CAN_socket::read_frame(struct can_frame &frame)
{
	//struct can_frame frame;
	if (read(s, &frame, sizeof(struct can_frame)) < 0)
	//if (read(s, frame, sizeof(struct can_frame)) < 0)
	{
		sock_error = true;
		cout << "Error reading CAN bus address";
	}
	
	cout << "GOT A FRAME!" << endl;
	return frame;
}