#include "monty.h"
#include "lists.h"

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
	i = 0;
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

/**
 * swapper - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void swapper(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second = NULL;

	if (dlistint_len(*stack) < 2)
		erro(8, line_number);

	second = first->next;

	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}
