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

class CAN_frame_13c : public Converted_CAN_Data
{
private:
	static __u8 frame_id;

    float throttle_command;
	float throttle_plate;
	float load_command;

	bool clutch_status;
public:
	CAN_frame_13c();
	__u8 get_class_id(void);
    void convert_frame(struct can_frame &);
};

#endif