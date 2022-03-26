// Functions used in the program SystemOfEquations.c
//

#include <stdio.h>
#include "extrafunctions.h"
#include "linalg.h"

void show_system(Matrix *sys)                   // Shows the system's augmented matrix on the screen.
{
    if (sys == NULL)
    {
        error_message_x(1, "NULL system informed!");

        return;
    }

    printf("\nSystem:");

    print_matrix(sys);
}

void print_results(Matrix *sys, Array *sol)     // Writes the results in a 'txt' file and on screen.
{
    register int i, j;
    int m, n;

    FILE *filout;
    
    if (sys == NULL)
    {
        error_message_x(2, "NULL system informed!");

        return;
    }

    filout = fopen("SystemOfEquationsOutput.txt", "w");

    if (filout == NULL)
    {
        error_message_x(2, "error opening file!");

        exit(2);
    }

    fprintf(filout, "\nSystem:\n\n");               // Prints the system.

    m = matrix_row_number(sys);

    n = matrix_column_number(sys);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            fprintf(filout, "%lf\t", get_from_matrix(sys, i, j));

        fprintf(filout, "\n");
    }

    if (sol == NULL)                                // Prints the solution.
    {
        fprintf(filout, "\nThere is no solution for the system.\n");

        printf("\nThere is no solution for the system.\n");
    }
    else
    {
        fprintf(filout, "\n\nSolution:\n\n");

        printf("\n\nSolution:\n\n");

        for (i = 0; i < m; i++)
        {
            fprintf(filout, "x%d: %lf\n", i + 1, get_from_array(sol, i));

            printf("x%d: %lf\n", i + 1, get_from_array(sol, i));
        }
    }

    fclose(filout);
}

static void error_message_x(int nmbr, char* mssg)  // Shows an error message indicating the function from where it came.
{
    if (mssg == NULL)
    {
        error_message_x(0, "NULL string informed!");

        return;
    }

    printf("\n\n** Error **\n** [X%04d]: %s **\n\a", nmbr, mssg);
}