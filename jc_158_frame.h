/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 3 Nov 2019
 *
 * jc_158_frame.h
 * Header file for child class of converted CAN messages, the frame 158
 */

#ifndef JC_158_FRAME_H
#define JC_158_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

// Ncurses library NEEDED FOR PRINT TESTING FOR NOW////////////////////////
//#include <ncurses.h>

class CAN_frame_158 : public Converted_CAN_Data
{
private:
	static canid_t frame_id;

public:
    // Consider making an int??????????????????????????????????
    // Consider making PRIVATE????????????????????????????????
    float speed_1;
    float speed_2;

	CAN_frame_158();
	canid_t get_class_id(void);
    void convert_frame(struct can_frame &);

    //void print_test(void);
};

#endif