#include "monty.h"

/**
 * ivstg - investigate the operand to check if the input is alpha.
 * @operand: the operand to investigate.
 * @line_number: The line number of the opcode being worked on.
 * Return: the operand
 */
char *ivstg(char *operand, unsigned int line_number)
{
	int i, k;

	if (operand == NULL)
	{ 
		erro(5, line_number);
	}
	k = (strlen(operand));
	if (operand[0] == 45)
		i++;
	for (; i < k; i++)
	{
		if (operand[i] > 47 && operand[i] < 58)
			continue;
		erro(5, line_number);
	}
	return (operand); 
}
