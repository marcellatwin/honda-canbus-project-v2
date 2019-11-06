/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 31 Oct 2019
 *
 * jc_13c_frame.h
 * Header file for child class of converted CAN messages, the frame 13c
 */

#ifndef JC_13C_FRAME_H
#define JC_13C_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

// Ncurses library NEEDED FOR PRINT TESTING FOR NOW////////////////////////
//#include <ncurses.h>

class CAN_frame_13c : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    float throttle_command;
	float throttle_plate;
	float load_command;

	bool clutch_status;
public:
	CAN_frame_13c();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    float get_throttle_command(void);
    float get_throttle_plate(void);
    float get_load_command(void);
    bool get_clutch_status(void);
    
    //void print_test(void);
};

#endif