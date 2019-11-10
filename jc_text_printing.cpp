/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_text_printing.cpp
 * Cpp file for printing to the console with ncurses
 */

// Corresponding header file
#include "jc_text_printing.h"

// Initialize ncurses window
void start_text_dash(void)
{
	// Initialize ncurses variables
    initscr();
    //clear();

    // Set to no delay on getch() from user???
    nodelay(stdscr, TRUE);
    
    // Make the cursor invisible
    curs_set(0);
}

// Shutdown ncurses window
void end_text_dash(void)
{
	// Reset screen and show the curser
	endwin();
    curs_set(1);
}

// Print the text based dash titles
void print_dash_titles_text(void)
{
    int row = STARTING_ROW;

    mvprintw(row++, TITLE_COLM, "Logging:");
    row++;

    mvprintw(row++, TITLE_COLM, "--Frame 13c--");
    mvprintw(row++, TITLE_COLM, "Throttle Comm:");
    mvprintw(row++, TITLE_COLM, "Throttle plate:");
    mvprintw(row++, TITLE_COLM, "Load Comm:");
    mvprintw(row++, TITLE_COLM, "Clutch:");
    row++;

    mvprintw(row++, TITLE_COLM, "--Frame 158--");
    mvprintw(row++, TITLE_COLM, "Speed 1:");
    mvprintw(row++, TITLE_COLM, "Speed 2:");
    row++;

    mvprintw(row++, TITLE_COLM, "--Frame 17c--");
    mvprintw(row++, TITLE_COLM, "Throttle pedal:");
    mvprintw(row++, TITLE_COLM, "Cruise Control:");
    mvprintw(row++, TITLE_COLM, "Brake:");
    mvprintw(row++, TITLE_COLM, "RPM 1:");
    row++;

    mvprintw(row++, TITLE_COLM, "--Frame 1a4--");
    mvprintw(row++, TITLE_COLM, "Brake pedal:");
    row++;

    mvprintw(row++, TITLE_COLM, "--Frame 1a6--");
    mvprintw(row++, TITLE_COLM, "Headlights:");
    mvprintw(row++, TITLE_COLM, "E-brake:");
    mvprintw(row++, TITLE_COLM, "Cruise Control:");
    mvprintw(row++, TITLE_COLM, "Cruise Control - Main:");
    mvprintw(row++, TITLE_COLM, "Cruise Control - Cancel:");
    mvprintw(row++, TITLE_COLM, "Cruise Control - Set/Deaccelerate:");
    mvprintw(row++, TITLE_COLM, "Cruise Control - Reset/Accelerate:");
    mvprintw(row++, TITLE_COLM, "AC Compressor:");
    mvprintw(row++, TITLE_COLM, "Reverse:");
    row++;



    mvprintw(row++, TITLE_COLM, "--Frame 324--");
    mvprintw(row++, TITLE_COLM, "Water Temp (C):");
    mvprintw(row++, TITLE_COLM, "Intake Temp (C):");
    row++;
}

// Print the text based data
void print_dash_data_text(Decoded_frame & decoded_frame, Logger & data_log)
{
    int row = STARTING_ROW;

    mvprintw(row++, DATA_COLM, "%s", data_log.get_log_status() ? "On" : "Off");
    clrtoeol();
    row++;

    // Frame 13c //
    row++;
    mvprintw(row++, DATA_COLM, "%d", decoded_frame.frame_13c.get_throttle_command());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%d", decoded_frame.frame_13c.get_throttle_plate());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_13c.get_load_command());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_13c.get_clutch_status() ? "In" : "Out");
    clrtoeol();
    row++;

    // Frame 158 //
    row++;
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_158.get_speed_1());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_158.get_speed_2());
    clrtoeol();
    row++;

    // Frame 17c //
    row++;
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_17c.get_throttle_pedal());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_17c.get_cruise_cont_active_status() ? "Active" : "Inactive");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_17c.get_brake_status() ? "On" : "Off");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%d", decoded_frame.frame_17c.get_rpm_1());
    clrtoeol();
    row++;

    // Frame 1a4 //
    row++;
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_1a4.get_brake_pedal());
    clrtoeol();
    row++;

    // Frame 1a6 //
    row++;
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_1a6.get_headlights());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_1a6.get_ebrake_status() ? "On" : "Off");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_1a6.get_cruise_control_main_status() ? "On" : "Off");
    clrtoeol();
    mvprintw(row++, DATA_COLM + 8, "%s", decoded_frame.frame_1a6.get_cruise_control_main_button() ? "Pressed" : "na");
    clrtoeol();
    mvprintw(row++, DATA_COLM + 8, "%s", decoded_frame.frame_1a6.get_cruise_control_cancel_button() ? "Pressed" : "na");
    clrtoeol();
    mvprintw(row++, DATA_COLM + 20, "%s", decoded_frame.frame_1a6.get_cruise_control_set_deaccel_button() ? "Pressed" : "na");
    clrtoeol();
    mvprintw(row++, DATA_COLM + 20, "%s", decoded_frame.frame_1a6.get_cruise_control_reset_accel_button() ? "Pressed" : "na");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_1a6.get_ac_compressor_status() ? "On" : "Off");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_1a6.get_reverse_status() ? "Reverse" : "na");
    clrtoeol();
    row++;



    // Frame 324 //
    row++;
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_324.get_water_temp());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_324.get_intake_temp());
    clrtoeol();
    row++;
}