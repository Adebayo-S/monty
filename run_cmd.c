#include "monty.h"

/**
 * get_cmd - return the requisite opcode to run
 * @cmd: opcode passed
 * Return: pointer to the function that executes the opcode
 */
void (*get_cmd(void))(stack_t **head, unsigned int line_number)
{
	int i;
	instruction_t cmds[] = {
		{"push", pusher},
		{"pall", paller},
		{"pint", pinter},
		{"pop", popper},
		/*{"swap", swapper},
		{"add", adder},
		{"nop", nopper},*/
		{NULL, NULL}
	};

	for (i = 0; cmds[i].opcode; i++)
	{
		if (strcmp(cmds[i].opcode, var.cmd) == 0)
			break;
	}

	return (cmds[i].f);
}

void run_cmd(char *bufline)
{
	void (*f)(stack_t **head, unsigned int line_number);

	var.cmd = strtok(bufline, DELIM);
	if (var.cmd && var.cmd[0] != '#')
	{
		f = get_cmd();
		if (f)
		{
			var.value = strtok(NULL, DELIM);
			f(&(var.head), var.line_number);
		}
		else
			h_error(INVALID, var.line_number, var.cmd), free_stack();
		free_var();
	}
}
