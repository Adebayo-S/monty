#include "monty.h"
#include "lists.h"

/**
 * multpler - handles the multiplication instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void multpler(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int mul;

	if (dlistint_len(*stack) < 2)
		erro(13, line_number);

	first = *stack;
	second = first->next;

	mul = (second->n) * (first->n);
	*stack = second;
	(*stack)->n = mul;
	free(first);
}
