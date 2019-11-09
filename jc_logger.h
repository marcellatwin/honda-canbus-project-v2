/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 7 Nov 2019
 *
 * jc_logger.h
 * Header file for class associated with creating log files
 */

#ifndef JC_LOGFILE_H
#define JC_LOGFILE_H

// Library for file streams
#include <fstream>

// Library for linux types
//#include <linux/can.h>

class Logger
{
private:
	string file_name;
	string file_location;
    //int row_count;

    struct timeval temp_time;

	bool log_status;
	bool log_error;

    ofstream csv_log;

public:
	Logger();
	~Logger();
	//Logfile(string); - FOR LATER

	void log_titles(void);
    void log_current(Decoded_frame &, CAN_socket &);
    void log_start_stop(void);

    bool get_log_status(void);
	bool log_error(void);
};

#endif
