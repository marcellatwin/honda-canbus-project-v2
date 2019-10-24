/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 24 Oct 2019
 *
 * jc_class_converted_CAN_data.h
 * Header file for connecting to socket
 */

#ifndef CAN_SOCKET_H
#define CAN_SOCKET_H

//Common Libs
#include <iostream>

// Libraries for connecting to CAN socket
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>

// Libraries for linux-can-utils
#include <linux/can.h>
#include <linux/can/raw.h>

class CAN_socket
{
public:
	CAN_socket();
	bool socket_error();
	struct can_frame read_frame();
private:
	bool error = false;
	int s;
	struct socketaddr_can addr;
	struct ifreq ifr;
};

#endif
