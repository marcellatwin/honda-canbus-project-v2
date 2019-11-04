/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_text_printing.cpp
 * Cpp file for printing to the console with ncurses
 */

// Library for controlling the terminal curser
#include <ncurses.h>

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
void text_dash_titles(void)
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
void text_dash_data(void)
{
    int row = STARTING_ROW;

    // Frame 13c //
    mvprintw(row++, DATA_COLM, "%.1f", frame_13c.throttle_command);
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", frame_13c.throttle_plate);
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", frame_13c.load_command);
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", frame_13c.clutch_status ? "In" : "Out");
    clrtoeol();

    // Frame 158 //
    mvprintw(row++, DATA_COLM, "%.1f", frame_158.speed_1);
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", frame_158.speed_2);
    clrtoeol();
    row++;

    // Frame 17c //
    mvprintw(row++, DATA_COLM, "%.1f", frame_17c.throttle_pedal);
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", frame_17c.cruise_cont_active_flag ? "Active" : "Inactive");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%s", frame_17c.brake_status ? "On" : "Off");
    clrtoeol();
    mvprintw(row++, DATA_COLM, "%.1f", frame_17c.rpm_1);
    clrtoeol();
}