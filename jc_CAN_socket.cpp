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
		if (ioctl(s, SIOCGIFINDEX, &ifr) == -1)
		{
			cout << "Error with control device (SIOCGIFINDEX)";
			sock_error = true;
			close(s);
		}
		else
		{
			// Do some more with structs and something with the CPU socket
			addr.can_ifindex = ifr.ifr_ifindex;
			//setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
			fcntl(s, F_SETFL, O_NONBLOCK);

			//if (bind(s, (struct sockaddr*) addr, sizeof(addr)) == -1)
			if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) == -1)
			{
				cout << "Error with binding socket address";
				sock_error = true;
				close(s);
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
	
	int x = read(s, &frame, sizeof(struct can_frame));
	cout << x << endl;
	if (x < 0)
	//if (read(s, &frame, sizeof(frame)) < 0)
	//if (read(s, frame, sizeof(struct can_frame)) < 0)
	{
		sock_error = true;
		cout << "Error reading CAN bus address" << endl;
		close(s);
	}
	
	cout << "GOT A FRAME!" << endl;
	return frame;
}