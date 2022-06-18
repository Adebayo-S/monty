#include "monty.h"

global_t var;

/**
 * init_var - initializes the global variables
 *
 * Return: no return
 */
void init_var(void)
{
	var.bufline = NULL;
	var.cmd = NULL;
	var.value = NULL;
	var.head = NULL;
	var.line_number = 0;
	var.mode = 1;
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	size_t size = 0;

	if (argc != 2)
		erro(1);

	init_var();

	var.fd = fopen(argv[1], "r");

	if (!var.fd)
		erro(2, argv[1]);

	while (getline(&var.bufline, &size, var.fd) != EOF)
	{
		var.line_number++;
		run_cmd(var.bufline);
	}
	free_var(), free_stack();
	fclose(var.fd);

	return (EXIT_SUCCESS);
}
