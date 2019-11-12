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

	// Get local time according to raspberry pi
	time(&current_time);
	localtime_r(&current_time, &now); 

	// Setup file name and location for log file
	file_location = "/media/pi/PI_USB_LOGS/";
	
	file_name << boost::format("log_%04d-%02d-%02d_%02d-%02d-%02d.csv") %
		(now.tm_year + 1900) %
		(now.tm_mon + 1) %
		now.tm_mday %
		now.tm_hour % 
		now.tm_min %
		now.tm_sec;

	// Create file and open it
	csv_log.open(file_location + file_name.str());
	
	// Check if it is open
	if (!csv_log.is_open())
		log_error = true;
}

Logger::~Logger()
{
	csv_log.close();
	cout << endl << "Destructor, closing " << file_name.str() << endl;
}

void Logger::log_titles(void)
{
	if (csv_log.good())
	{
		csv_log << 
			"time (s)" << "," << 
			"throttle_pedal" << "," << 
			"brake_pedal" << "," <<
			"rpm_1" << "," << 
			"speed_1" << "," <<
			"water_temp" << "," <<
			"intake_temp" << "," <<
			"AC" << "," <<
			"fuel_consumption_gauge";
		csv_log << endl;
	}
	else
		log_error = true;
}

void Logger::log_current(Decoded_frame & decoded_frame, CAN_socket & sock)
{
	temp_time = sock.get_timestamp();

	csv_log << temp_time.tv_sec << "." << temp_time.tv_usec << ",";
	csv_log << decoded_frame.frame_17c.get_throttle_pedal() << ",";
	csv_log << decoded_frame.frame_1a4.get_brake_pedal() << ",";
	csv_log << decoded_frame.frame_17c.get_rpm_1() << ",";
	csv_log << decoded_frame.frame_158.get_speed_1() << ",";
	csv_log << decoded_frame.frame_324.get_water_temp() << ",";
	csv_log << decoded_frame.frame_324.get_intake_temp() << ",";
	csv_log << decoded_frame.frame_1a6.get_ac_compressor_status() << ",";
	csv_log << decoded_frame.frame_377.get_fuel_consumption_gauge() << ",";

	csv_log << endl;
}

void Logger::log_start_stop(void)
{
	if (log_status)
		log_status = false;
	else
		log_status = true;
}

bool Logger::get_log_status(void)
{
	return log_status;
}

bool Logger::logger_error(void)
{
	return log_error;
}
