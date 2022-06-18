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

/**
 * modder - handles the modulo instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void modder(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int mod;

	if (dlistint_len(*stack) < 2)
		erro(14, line_number);

	first = *stack;
	second = first->next;

	mod = (second->n) % (first->n);
	*stack = second;
	(*stack)->n = mod;
	free(first);
}

/**
 * pchar - print the char at the top of the stack.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *start;

	start = *stack;
	if (!start)
		erro(15, line_number);

	if (start->n > 127 || start->n < 0)
		erro(16, line_number);

	printf("%c\n", start->n);
}

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
 * rotl - rotate the stack to the top.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */
void reverse(stack_t **stack, unsigned int line_number)
{
	stack_t *start, *temp, *temp2;
	(void)line_number;

	start = *stack;

	while (start->next)
		start = start->next;

	temp = start->prev;

	while (temp)
	{
		temp2 = temp->prev;

		temp->next->next = temp;
		temp->prev = temp->next;
		temp->next = temp2;

		temp = temp->next;
	}

	start->prev = NULL;
}
