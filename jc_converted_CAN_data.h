/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_converted_CAN_data.h
 * Header file for parent class of converted CAN messages
 */

#ifndef JC_CONVERTED_CAN_DATA_H
#define JC_CONVERTED_CAN_DATA_H

class Converted_CAN_Data
{
private:
    string message_id = "";   // ???
    // or
    int message_id;
    // or
    __u8 message_id;
    // or
    int message_id[];  // can be multiple, but will always be one
                    // Except for transmission gear_calc maybe???
                    // gear_calc is just a function, Trans object still gets pedal and reverse message
    bool reprint_var;
public:
    virtual void convert_message(string message_data) = 0;
};

#endif