/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 10 Nov 2019
 *
 * jc_1dc_frame.h
 * Header file for child class of converted CAN messages, the frame 1dc
 */

#ifndef JC_1DC_FRAME_H
#define JC_1DC_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

class CAN_frame_1dc : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    int rpm_2;
public:
	CAN_frame_1dc();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    int get_rpm_2(void);

};

#endif