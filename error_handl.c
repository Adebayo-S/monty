#include "monty.h"

void h_error(const char *message, unsigned int var_1, char *var_2)
{
	if (!var_1)
		dprintf(STDERR_FILENO, message, var_2);
	else
		dprintf(STDERR_FILENO, message, var_1, var_2);
	exit(EXIT_FAILURE);
}
