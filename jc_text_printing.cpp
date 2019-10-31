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
    //nodelay(stdscr, TRUE);
    
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