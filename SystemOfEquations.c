// This program gets a system of equations from a 'txt' file and solves it, if there is a solution.
// The number of equations must be equal to the number of variables.
//

#include "linalg.h"
#include "extrafunctions.h"

int main()
{
    Array *solution;
    Matrix *system;

    system = get_system("system.txt");

    show_system(system);

    solution = solve_system(system);

    print_results(system, solution);

    free_array(solution);

    free_matrix(system);

    return 0;
}
