/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_throttle_data.h
 * Header file for child class of converted CAN messages, throttle data
 */

#ifndef JC_THROTTLE_DATA_H
#define JC_THROTTLE_DATA_H

class Throttle_Data : public Converted_CAN_Date
{
private:
    
    //bool reprint_var;
    
    float throttle_pedal;
    bool throttle_cutout_flag;
    float throttle_command;
    float throttle_plate;
public:
    Throttle_Data();
    void convert_message(struct can_frame &);
};

#endif