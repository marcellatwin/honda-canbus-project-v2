/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 7 Nov 2019
 *
 * jc_logger.cpp
 * Cpp file for logging data and errors to a logfile
 */

// Corresponding header file
#include "jc_logger.h"

// Constructor to set up the log file
//Logger::Logger(string file_name) - FOR LATER
Logger::Logger()
{
	// Set initial values
	log_status = false;
	log_error = false;

	// Create file and open it

}

void log_current(void)
{

}

void log_start_stop(void)
{
	if (log_status)
		log_status = false;
	else
		log_status = true;
}

bool get_log_status(void)
{
	return log_status;
}

bool log_error(void)
{
	return log_error;
}
