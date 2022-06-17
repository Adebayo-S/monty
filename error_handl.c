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
			erro_ext(code, va_arg(param, int));
			break;
	}
	va_end(param), exit(EXIT_FAILURE);
}

/**
 * erro_ext - extensuion for the erro function
 * @code: the error code
 * @va_arg: the variable argument
 * Return: void
 */
void erro_ext(int code, int va_arg)
{
	switch (code)
	{
		case 8:
			dprintf(STDERR_FILENO, SWAP, va_arg);
			break;
		case 9:
			dprintf(STDERR_FILENO, ADD, va_arg);
			break;
		case 10:
			dprintf(STDERR_FILENO, SUB, va_arg);
			break;
		case 11:
			dprintf(STDERR_FILENO, DIV, va_arg);
			break;
		case 12:
			dprintf(STDERR_FILENO, DERR, va_arg);
			break;
		case 13:
			dprintf(STDERR_FILENO, MUL, va_arg);
			break;
		case 14:
			dprintf(STDERR_FILENO, MOD, va_arg);
			break;
		case 15:
			dprintf(STDERR_FILENO, PCHAR, va_arg);
			break;
		case 16:
			dprintf(STDERR_FILENO, RANGE, va_arg);
			break;
		default:
			break;
	}
}
