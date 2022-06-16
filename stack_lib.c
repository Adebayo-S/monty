#include "monty.h"

void pushh(stack_t **stack, unsigned int line_number)
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
    start->n = var.operand;
    start->next = *stack;
    start->prev = NULL;
    *stack = start;
}