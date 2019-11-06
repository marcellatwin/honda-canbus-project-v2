/*****************************************************************************/
/*
 * By Jonathan Crossley
 * Version 0.1 - 30 Oct 2019
 *
 * jc_text_printing.h
 * Header file for printing to the console with ncurses
 */

#ifndef JC_TEXT_PRINTING_H
#define JC_TEXT_PRINTING_H

// Column for printing titles
#ifndef TITLE_COLM
#define TITLE_COLM  1
#endif

// Column for printing converted data
#ifndef DATA_COLM
#define DATA_COLM  23
#endif

// Row to start printing on
#ifndef STARTING_ROW
#define STARTING_ROW  1
#endif

// Ncurses library
#include <ncurses.h>

// Set up escape sequences for cursor and screen control
#if 0
#define CLR_SCREEN		"\33[2J"
#define CLR_LINE		"\33[2K"
#define CSR_HIDE  		"\33[?25l"
#define CSR_SHOW  		"\33[?25h"
#define CSR_HOME  		"\33[H"
#define CSR_NEW_HOME	"\33"
#endif

// Function prototypes
void start_text_dash(void);
void end_text_dash(void);

void print_dash_titles_text(void);
void print_dash_data_text(Decoded_frame &);

#endif