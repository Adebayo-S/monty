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
		fprintf(stderr, "0L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	k = strlen(operand);
	while (k--)
	{
		if (operand[k] > 47 && operand[k] < 58)
			continue;
		fprintf(stderr, "1L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	return (operand);
}
