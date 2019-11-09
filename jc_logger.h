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
	//string file_name
    int row_count;

	bool log_status;
	bool log_error;

public:
	Logger();
	//Logfile(string); - FOR LATER

    void log_current(void);
    void log_start_stop(void);

    bool get_log_status(void);
	bool log_error(void);
};

#endif





ofstream fout("/media/pi/0045-94E3/data_logs/");

fout.good();  // or status???

fout << (rand() % 100) + 1 << endl;





sprintf(fname, "candump-%04d-%02d-%02d_%02d%02d%02d.log",
			now.tm_year + 1900,
			now.tm_mon + 1,
			now.tm_mday,
			now.tm_hour,
			now.tm_min,
			now.tm_sec);

logfile = fopen(fname, "w");
if (!logfile) {
	perror("logfile");
	return 1;
}

fprintf(logfile, "(%010ld.%06ld) %*s %s\n",
						tv.tv_sec, tv.tv_usec,
						max_devname_len, devname[idx], buf);