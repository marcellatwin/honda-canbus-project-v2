/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 11 Nov 2019
 *
 * jc_377_frame.h
 * Header file for child class of converted CAN messages, the frame 377
 */

#ifndef JC_377_FRAME_H
#define JC_377_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

class CAN_frame_377 : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    float fuel_consumption_gauge;

public:
	CAN_frame_377();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    float get_fuel_consumption_gauge(void);

};

#endif