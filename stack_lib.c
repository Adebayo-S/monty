#include "monty.h"

/**
 * pusher - function to push entered operand to stack.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * @return: void
 */

void pusher(stack_t **stack, unsigned int line_number)
{
	stack_t *start;
	char *text;

	text = ivstg(var.value, line_number);
	start = malloc(sizeof(stack_t));
	if (!start)
		erro(4);

	if (*stack != NULL)
		(*stack)->prev = start;
	start->n = atoi(text);
	start->next = *stack;
	start->prev = NULL;
	*stack = start;
}

/**
 * paller - function to print out all element in stack.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * @return: void
 */

void paller(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int value;

	(void)line_number;

	if (!(*stack) || !stack)
		exit(EXIT_FAILURE);

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
 * @return: void
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
 * @return: void
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
 * noper - function to do nada.
 * @stack: The begining of the doubly linked list.
 * @line_number: The line number of the opcode being worked on.
 * @return: void
 */
void nopper(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	;
}
