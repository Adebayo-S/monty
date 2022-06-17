#include "monty.h"

/**
 *erro - prints the associated error message to stderr
 * @code: the error code
 * Return: void
 */
void erro(int code, ...)
{
	va_list param;
	int dig;
	char *par;

	va_start(param, code);
	switch (code)
	{
		case 1:
			dprintf(STDERR_FILENO, USAGE);
			break;
		case 2:
			dprintf(STDERR_FILENO, NOACCESS, va_arg(param, char *));
			break;
		case 3:
			dig = va_arg(param, int);
			par = va_arg(param, char *);
			dprintf(STDERR_FILENO, INVALID, dig, par);
			break;
		case 4:
			dprintf(STDERR_FILENO, MALLOC);
			break;
		case 5:
			dprintf(STDERR_FILENO, PUSH, va_arg(param, int));
			break;
		case 6:
			dprintf(STDERR_FILENO, PINT, va_arg(param, int));
			break;
		case 7:
			dprintf(STDERR_FILENO, POP, va_arg(param, int));
			break;
		default:
			break;
	}
	va_end(param), exit(EXIT_FAILURE);
}
