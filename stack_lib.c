#include "monty.h"
#include "lists.h"

/**
 * pusher - function to push entered operand to stack.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */

void pusher(stack_t **stack, unsigned int line_number)
{
	char *text;
	int n;

	text = ivstg(var.value, line_number);
	n = atoi(text);
	if (var.mode == -1)
	{
		add_dnodeint_end(stack, n);
	}
	else
	{
		add_dnodeint(stack, n);
	}
}

/**
 * paller - function to print out all element in stack.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */

void paller(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int value;

	(void)line_number;

	if (!(*stack) || !stack)
		return;

	temp = *stack;
	while (temp != NULL)
	{
		value = temp->n;
		printf("%d\n", value);
		temp = temp->next;
	}
}

/**
 * pinter - function to print the first element in stack.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */
void pinter(stack_t **stack, unsigned int line_number)
{
	stack_t *start;

	start = *stack;
	if (!start)
		erro(6, line_number);

	printf("%d\n", start->n);
}

/**
 * popper - function to delete an element from the stack.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */
void popper(stack_t **stack, unsigned int line_number)
{
	stack_t *start;

	start = *stack;
	if (stack == NULL || *stack == NULL)
		erro(7, line_number);
	*stack = start->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(start);
}


/**
 * nopper - function to do nada.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * Return: void
 */
void nopper(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
