/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *
 * jc_CAN_socket.h
 * Header file for connecting to socket and all associated libraries
 */

#ifndef JC_CAN_SOCKET_H
#define JC_CAN_SOCKET_H

// Common libraries
#include <iostream>
#include <cstring>

// Libraries for connecting to CAN socket
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <net/if.h>
#include <unistd.h>

// Libraries for linux-can-utils
#include <linux/can.h>
#include <linux/can/raw.h>

using namespace std;

class CAN_socket
{
private:
	bool sock_error;
	int s;
	struct sockaddr_can addr;
	struct ifreq ifr;
	struct timeval time_stamp;
	//struct timeval start_time;
	//struct timeval end_time;

	struct tm start_time;
	struct tm end_time;
	time_t current_time;

public:
	CAN_socket();
	~CAN_socket();
	
	// Insertion operator overloading for C++ class project
	friend ostream &operator<<(ostream &, CAN_socket &);

	bool socket_error(void);
	struct can_frame read_frame(struct can_frame &);
	struct timeval get_timestamp(void);
};

#endif
