/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_converted_CAN_data.h
 * Header file for parent class of converted CAN messages based on frame ID
 */

#ifndef JC_CONVERTED_CAN_DATA_H
#define JC_CONVERTED_CAN_DATA_H

class Converted_CAN_Data
{
public:
    virtual void convert_frame(struct can_frame &) = 0;
};

#endif