#include "monty.h"

void erro(int code, ...)
{
    va_list param;

    va_start(param, code);
    switch (code)
    {
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file <file>\n", va_arg(param, char *));
			break;
		case 3:
			printf("L%d: unknown instruction <opcode>\n", va_arg(param, int), va_arg(param, char *));
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer", va_arg(param, int));
			break;
		case 6:
			printf("L%d: can't pint, stack empty", va_arg(param, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack", va_arg(param, int));
			break;
		case 8:
			printf("L%d: can't swap, stack too short", va_arg(param, int));
			break;
		case 9:
			printf("L%d: can't add, stack too short", va_arg(param, int));
			break;
		default:
			break;
    }
	exit(EXIT_FAILURE);
}
