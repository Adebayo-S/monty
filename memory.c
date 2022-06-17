#include "monty.h"
#include "lists.h"

/**
 * free_var - free the global struct variable
 */
void free_var(void)
{
	if (var.bufline)
		free(var.bufline);
}

/**
 * free_stack - free the created stack
 */
void free_stack(void)
{
	if (var.head)
		free_dlistint(var.head);
}
