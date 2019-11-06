/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 5 Nov 2019
 *
 * jc_decoded_frame.h
 * Header file for class of decoded CAN frames where each converted CAN class
 *  lives
 */

#ifndef JC_DECODED_FRAME_H
#define JC_DECODED_FRAME_H

// Library for linux types
#include <linux/can.h>

// Library for time ??????
//#include <time.h>

// Header files of each CAN frame class
#include "jc_13c_frame.h"
#include "jc_158_frame.h"
#include "jc_17c_frame.h"

class Decoded_frame
{
private:
	canid_t frame_ID_array[];
	int array_size;
public:
	Decoded_frame();
    void new_frame(struct can_frame &);
};

#endif