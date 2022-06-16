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

    start = malloc(sizeof(stack_t));
    if (!start)
    {
        h_error("Error: malloc failed\n", NULL);
        exit(EXIT_FAILURE);
    }
    if (*stack != NULL)
        (*stack)->prev = start;
    start->n = atoi(var.value);
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

    if (stack == NULL)
        exit(EXIT_FAILURE);

    temp = *stack;
    while (temp != NULL)
    {
        value = temp->n;
        printf("%d\n", value);
        temp = temp->next;
    }
}


void pinter(stack_t **stack, unsigned int line_number)
{
    stack_t *start;

    start = *stack;
    if (!start)
        fprintf(stderr, "L%d: can't pint, stack empty", line_number);
        exit(EXIT_FAILURE);
        
    printf("%d\n", start->n);
}