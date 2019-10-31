/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_text_printing.h
 * Header file for printing to the console with ncurses
 */

// Column for printing titles
#ifndef TITLE_COLM
#define TITLE_COLM  1
#endif

// Column for printing converted data
#ifndef DATA_COLM
#define DATA_COLM  23
#endif

// Function prototypes
void start_text_dash(void);
void end_text_dash(void);