#include "monty.h"
#include "lists.h"

/**
 * free_var - free the global struct variable
 */
void free_var(void)
{
	if (var.bufline)
	{
		free(var.bufline);
		free(var.cmd);
		free(var.value);
	}
}

/**
 * free_stack - free the created stack
 */
void free_stack(void)
{
	if (var.head)
		free_dlistint(var.head);
}
