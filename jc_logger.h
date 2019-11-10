/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 7 Nov 2019
 *
 * jc_logger.h
 * Header file for class associated with creating log files
 */

#ifndef JC_LOGGER_H
#define JC_LOGGER_H

// Header files for what is being logged
#include "jc_decoded_frame.h"
#include "jc_CAN_socket.h"

// Library for file streams
#include <fstream>

// Library and namespace for strings
#include <string>
using namespace std;

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
	bool logger_error(void);
};

#endif
