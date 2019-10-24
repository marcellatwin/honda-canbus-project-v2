/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *
 * jc_.cpp
 * Header file for connecting to socket
 */


#include "CAN_socket.h"

CAN_socket::CAN_socket()
{
	this->s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (this->s == -1)
	{
		std::cout << "Error creating endpoint for socket communication";
		this->error = true;
	}
	else
	{
		this->ifr.ifr_name = "can0";
		this->addr.can_family = AF_CAN;

		// Do something with control device
		if (ioctl(this->s, SIOCGIFINDEX, this->ifr) == -1)
		{
			cout << "Error with control device (SIOCGIFINDEX)";
			this->error = true;
		}
		else
		{
			// Do some more with structs and something with the CPU socket
			this->addr.can_ifindex = this->ifr.ifr_ifindex;
			setsockopt(this->s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);

			if (bind(this->s, (struct sockaddr*) this->addr, sizeof(this->addr)) == -1)
			{
				this->error = true;
				cout << "Error with binding socket address";
			}
		}
	}
}

bool CAN_socket::socket_error()
{
	return this->error;
}

struct can_frame CAN_socket::read_frame()
{
	struct can_frame frame;
	if (read(this->s, &frame, sizeof(struct can_frame)) < 0) {
		this->error = true;
		std::cout << "Error reading CAN bus address";
	}
	std::cout << "GOT A FRAME!" << std::endl;
	return frame;
}