#include "monty.h"

/**
 * ivstg - investigate the operand to check if the input is alpha.
 * @operand: the operand to investigate.
 * @line_number: The line number of the opcode being worked on.
 * Return: the operand
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
		if (operand[k] > 47 && operand[k] < 58 || operand[1] == 45)
			continue;
		erro(5, line_number);
	}
	return (operand); 
}
