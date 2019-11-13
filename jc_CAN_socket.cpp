/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *
 * jc_CAN_socket.cpp
 * Cpp file for connecting to socket
 * General code for connecting to socket taken from:
 *   Copyright (c) 2002-2009 Volkswagen Group Electronic Research
 */

// Corresponding header file
#include "jc_CAN_socket.h"

using namespace std;

// Constructor that sets up the socket
CAN_socket::CAN_socket()
{
	// Set initial values
	sock_error = false;

	// Set the file descriptor for the socket
	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

	if (s == -1)
	{
		perror("Error with setting up socket file descriptor: ");
		// output to logfile - FOR LATER
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
			// output to logfile - FOR LATER
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
			if (bind(s, (struct sockaddr*) &addr, sizeof(addr)) == -1)
			{
				perror("Error with binding socket address: ");
				sock_error = true;
			}
		}
	}

	// Get starting time
	//start_time = get_timestamp();
	time(&current_time);
	localtime_r(&current_time, &start_time);
}

// Destructor that will close the file descriptor for the socket
CAN_socket::~CAN_socket()
{
	close(s);
	cout << endl << "Destructor, closing s, ending program!" << endl << endl;
}

// Insertion operator overloading for C++ class project
ostream& operator<<(ostream &output, CAN_socket &sock)
{ 
	//sock.end_time = sock.get_timestamp();
	time(&sock.current_time);
	localtime_r(&sock.current_time, &sock.end_time);
	output << "Hours: " << (sock.end_time.tm_hour - sock.start_time.tm_hour)
		<< "  Minutes: " << (sock.end_time.tm_min - sock.start_time.tm_min)
		<< "  Seconds: " << (sock.end_time.tm_sec - sock.start_time.tm_sec);
	return output;
}

// Returns the state of the error variable
bool CAN_socket::socket_error(void)
{
	return sock_error;
}

// Reads the CAN bus and places it in a can_frame struct
struct can_frame CAN_socket::read_frame(struct can_frame &frame)
{
	if (read(s, &frame, sizeof(struct can_frame)) == -1)
	{
		sock_error = true;
		cout << "Error reading CAN bus" << endl;
		// output to logfile - FOR LATER
	}
	
	return frame;
}

// Get the current timestamp from socket
struct timeval CAN_socket::get_timestamp(void)
{
	//int temp_error = ioctl(s, SIOCGSTAMP, &time_stamp);
	//cout << "ioctl time error: " << temp_error;
	if (ioctl(s, SIOCGSTAMP, &time_stamp) == -1)
	{	
		sock_error = true;
		perror("time stamp error");
	}
	return time_stamp;
}
