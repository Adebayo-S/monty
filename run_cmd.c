#include "monty.h"

/**
 * get_cmd - return the requisite opcode to run
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
		{"nop", nopper},
		{"swap", swapper},
		{"add", adder},
		{"sub", subber},
		{"div", divider},
		{"mul", multpler},
		{"mod", modder},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", changemode},
		{"queue", changemode},
		{NULL, NULL}
	};

	for (i = 0; cmds[i].opcode; i++)
	{
		if (strcmp(cmds[i].opcode, var.cmd) == 0)
			break;
	}

	return (cmds[i].f);
}

/**
 * run_cmd - run the command
 * @bufline: line read from bytecode
 * Return: no return
 */
void run_cmd(char *bufline)
{
	void (*f)(stack_t **head, unsigned int line_number);

	var.cmd = strtok(bufline, DELIM);
	if (var.cmd && var.cmd[0] != '#')
	{
		f = get_cmd();
		if (f)
		{
			if (strcmp(var.cmd, "push") == 0)
				var.value = strtok(NULL, DELIM);
			f(&(var.head), var.line_number);
		}
		else
			erro(3, var.line_number, var.cmd), free_stack();
	}
}
