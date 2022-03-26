// Functions used in the program SystemOfEquations.c
//

#include "linalg.h"

// Shows the system coeficients on the screen.
//
void show_system(Matrix *sys);

// Write the results in a 'txt' file and on screen.
//
void print_results(Matrix *sys, Array *sol);

// Shows an error message indicating the function from where it came.
//
static void error_message_x(int nmbr, char *mssg);