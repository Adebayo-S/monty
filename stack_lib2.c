#include "monty.h"

/**
 * ivstg - investigate the operand to check if the input is alpha.
 * @line_number: The line number of the opcode being worked on.
 * @return: the operand
 */
char *ivstg(char *operand, unsigned int line_number)
{
	int k;

	if (operand == NULL)
	{
		erro(5, line_number);
	}
	k = strlen(operand);
	while (k--)
	{
		if (operand[k] < 47 && operand[k] < 58)
			continue;
		erro(5, line_number);
	}
	return (operand);
}
