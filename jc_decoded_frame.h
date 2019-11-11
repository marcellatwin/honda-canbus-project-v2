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

// Header files of each CAN frame class
#include "jc_13c_frame.h"
#include "jc_158_frame.h"
#include "jc_17c_frame.h"
#include "jc_1a4_frame.h"
#include "jc_1a6_frame.h"
#include "jc_1d0_frame.h"
#include "jc_1dc_frame.h"

#include "jc_320_frame.h"
#include "jc_324_frame.h"

// Namespace for vector
using namespace std;

class Decoded_frame
{
private:
	vector<canid_t> frame_IDs;

public:
	// Does this need to be PRIVATE (but won't compile)????????????????
	CAN_frame_13c frame_13c;
	CAN_frame_158 frame_158;
	CAN_frame_17c frame_17c;
	CAN_frame_1a4 frame_1a4;
	CAN_frame_1a6 frame_1a6;
	CAN_frame_1d0 frame_1d0;
	CAN_frame_1dc frame_1dc;

	CAN_frame_320 frame_320;
	CAN_frame_324 frame_324;

	Decoded_frame();
    void new_frame(struct can_frame &);
};

#endif