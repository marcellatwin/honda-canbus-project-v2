/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 31 Oct 2019
 *
 * jc_17c_frame.h
 * Header file for child class of converted CAN messages, the frame 17c
 */

#ifndef JC_17C_FRAME_H
#define JC_17C_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

// Ncurses library NEEDED FOR PRINT TESTING FOR NOW////////////////////////
#include <ncurses.h>

class CAN_frame_17c : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    float throttle_pedal;

    // Consider making an int??????????????????????????????????
    float rpm_1;

    bool cruise_cont_active_flag;
	bool brake_status;
public:
	CAN_frame_17c();
	canid_t get_class_id(void);
    void convert_frame(struct can_frame &);

    void print_test(void);
};

#endif