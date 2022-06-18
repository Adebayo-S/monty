#include "monty.h"
#include "lists.h"

/**
 * rotl - rotate the stack to the top.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	int val = 0;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	first = *stack;
	val = first->n;
	*stack = first->next;
	(*stack)->prev = NULL;
	add_dnodeint_end(stack, val);
	free(first);
}

/**
 * rotr - rotate the stack to the bottom.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	int val = 0;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	last = get_dnodeint_at_index(*stack, dlistint_len(*stack) - 1);
	val = last->n;
	add_dnodeintint(stack, val);
	free(last);
}
