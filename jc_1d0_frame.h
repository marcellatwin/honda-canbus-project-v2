/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 10 Nov 2019
 *
 * jc_1d0_frame.h
 * Header file for child class of converted CAN messages, the frame 1d0
 */

#ifndef JC_1D0_FRAME_H
#define JC_1D0_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

class CAN_frame_1d0 : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    float speed_3;
public:
	CAN_frame_1d0();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    float get_speed_3(void);

};

#endif