/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 6 Nov 2019
 *
 * jc_324_frame.h
 * Header file for child class of converted CAN messages, the frame 324
 */

#ifndef JC_324_FRAME_H
#define JC_324_FRAME_H

// Parent class library for converting CAN data
#include "jc_converted_CAN_data.h"

// Library for linux types
#include <linux/can.h>

// Library for strings
#include <string>

class CAN_frame_1a6 : public Converted_CAN_Data
{
private:
    static canid_t frame_id;

    float water_temp;
    float intake_temp;

public:
    CAN_frame_1a6();
    canid_t get_class_ID(void);
    void convert_frame(struct can_frame &);

    float get_water_temp(void);
    float get_intake_temp(void);
};

#endif
