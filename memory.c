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
		/*free(var.cmd);
		printf("free cmd done\n");*/
		/*free(var.value);
		printf("free value done\n");*/
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
