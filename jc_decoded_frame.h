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

// Library for vectors
#include <vector>

// Library for time ??????
//#include <time.h>

// Header files of each CAN frame class
#include "jc_13c_frame.h"
#include "jc_158_frame.h"
#include "jc_17c_frame.h"

using namespace std;

class Decoded_frame
{
private:
	//canid_t frame_ID_array[];
	
	vector<canid_t> frame_IDs;

	//int array_size;

public:
	// Not sure if this is NEEDED????????????????????????
	// Does this need to be PRIVATE (but won't compile)????????????????
	CAN_frame_13c frame_13c;
	CAN_frame_158 frame_158;
	CAN_frame_17c frame_17c;

	Decoded_frame();
    void new_frame(struct can_frame &);
};

#endif