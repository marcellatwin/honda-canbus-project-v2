/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 6 Nov 2019
 *
 * jc_1a4_frame.h
 * Header file for child class of converted CAN messages, the frame 1a4
 */

#ifndef JC_1A4_FRAME_H
#define JC_1A4_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

class CAN_frame_1a4 : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    float brake_pedal;
public:
	CAN_frame_1a4();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    float get_brake_pedal(void);

};

#endif