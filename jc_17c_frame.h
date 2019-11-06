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
//#include <ncurses.h>

class CAN_frame_17c : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

    float throttle_pedal;
    int rpm_1;
    bool cruise_cont_active_flag;
	bool brake_status;

public:
	CAN_frame_17c();
	canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    float get_throttle_pedal(void);
    int get_rpm_1(void);
    bool get_cruise_cont_active_flag(void);
    bool get_brake_status(void);

};

#endif