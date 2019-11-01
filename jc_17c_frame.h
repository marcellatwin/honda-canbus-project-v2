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

class CAN_frame_17c : public Converted_CAN_Data
{
private:
	static __u8 frame_id;

    float throttle_pedal;
    
    bool cruise_cont_active_flag;
	bool brake_status;
public:
	CAN_frame_17c();
	__u8 get_class_id(void);
    void convert_frame(struct can_frame &);

    void print_test(void);
};

#endif