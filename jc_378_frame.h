/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 11 Nov 2019
 *
 * jc_378_frame.h
 * Header file for child class of converted CAN messages, the frame 378
 */

#ifndef JC_378_FRAME_H
#define JC_378_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

class CAN_frame_378 : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    float fuel_tank_level;

public:
	CAN_frame_378();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    float get_fuel_tank_level(void);
};

#endif