/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *
 * jc_CAN_socket.h
 * Header file for connecting to socket
 */

#ifndef JC_CAN_SOCKET_H
#define JC_CAN_SOCKET_H

//Common Libs
#include <iostream>
#include <cstring>

// Libraries for connecting to CAN socket
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>

#include <unistd.h>

// ????
#include <net/if.h>

// Libraries for linux-can-utils
#include <linux/can.h>
#include <linux/can/raw.h>

class CAN_socket
{
private:
	bool sock_error = false;
	int s;
	struct sockaddr_can addr;
	struct ifreq ifr;
public:
	CAN_socket();
	bool socket_error();
	struct can_frame read_frame(struct can_frame &);
};

#endif