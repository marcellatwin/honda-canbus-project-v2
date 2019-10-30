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
	// Set the file descriptor for the socket
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (s == -1)
	{
		cout << "Error creating endpoint for socket communication";
		perror("socket");
		sock_error = true;
	}
	else
	{
		// Set the name of the socket/CAN interface
		strcpy(ifr.ifr_name, "can0");

		// Find the address of the socket
		if (ioctl(s, SIOCGIFINDEX, &ifr) == -1)
		{
			cout << "Error with control device (SIOCGIFINDEX)";
			perror("SIOCGIFINDEX");
			sock_error = true;
			close(s);
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
			int x = bind(s, (struct sockaddr*) &addr, sizeof(addr));
			//int x = connect(s, (struct sockaddr*) &addr, sizeof(addr));
			//if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) == -1)
			//cout << "Binding/connecting value:  " << x << endl;
			if (x < 0)
			{
				perror("connect");
				cout << "Error with binding socket address";
				sock_error = true;
				close(s);
			}
		}
	}
}

CAN_socket::~CAN_socket()
{
	close(s);
	cout << endl << "Destructor, closing s, ending!" << endl;
}

bool CAN_socket::socket_error()
{
	return sock_error;
}

struct can_frame CAN_socket::read_frame(struct can_frame &frame)
{
	
	int x = read(s, &frame, sizeof(struct can_frame));
	//cout << x << endl;
	if (x < 0)
	//if (read(s, &frame, sizeof(frame)) < 0)
	//if (read(s, frame, sizeof(struct can_frame)) < 0)
	{
		sock_error = true;
		cout << "Error reading CAN bus address" << endl;
		close(s);
	}
	
	//cout << "GOT A FRAME!" << endl;
	return frame;
}