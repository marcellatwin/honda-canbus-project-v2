/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 10 Nov 2019
 *
 * jc_320_frame.h
 * Header file for child class of converted CAN messages, the frame 320
 */

#ifndef JC_320_FRAME_H
#define JC_320_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

class CAN_frame_320 : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    bool vtec_status;

public:
	CAN_frame_320();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    bool get_vtec_status(void);

};

#endif