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
}

// Print the text based data
void print_dash_data_text(Decoded_frame & decoded_frame)
{
    int row = STARTING_ROW;

    // Frame 13c //
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_13c.get_throttle_command());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_13c.get_throttle_plate());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_13c.get_load_command());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_13c.get_clutch_status() ? "In" : "Out");
    clrtoeol();

    // Frame 158 //
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_158.get_speed_1());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_158.get_speed_2());
    clrtoeol();
    row++;

    // Frame 17c //
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_17c.get_throttle_pedal());
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_17c.get_cruise_cont_active_flag() ? "Active" : "Inactive");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", decoded_frame.frame_17c.get_brake_status() ? "On" : "Off");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", decoded_frame.frame_17c.get_rpm_1());
    clrtoeol();
}