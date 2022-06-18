#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>

#define UNDEFINED 0
#define DELIM " \r\t\n"
#define USAGE "USAGE: monty file\n"
#define NOACCESS "Error: Can't open file %s\n"
#define INVALID "L%d: unknown instruction %s\n"
#define MALLOC "Error: malloc failed\n"
#define PUSH "L%d: usage: push integer\n"
#define POP "L%d: can't pop an empty stack\n"
#define PINT "L%d: can't pint, stack empty\n"
#define SWAP "L%d: can't swap, stack too short\n"
#define ADD "L%d: can't add, stack too short\n"
#define SUB "L%d: can't sub, stack too short\n"
#define DIV "L%d: can't div, stack too short\n"
#define DERR "L%d: division by zero\n"
#define MUL "L%d: can't mul, stack too short\n"
#define MOD "L%d: can't mod, stack too short\n"
#define PCHAR "L%d: can't pchar, stack empty\n"
#define RANGE "L%d: can't pchar, value out of range\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Alx project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global struct variable
 * @head: head of the stack
 * @value: value passed into the opcode
 * @line_number: line number of the opcode
 * @bufline: line read from bytecode
 * @fd: file descriptor
 * @cmd: opcode
 *
 */
typedef struct global_s
{
	stack_t *head;
	char *value;
	unsigned int line_number;
	char *bufline;
	FILE *fd;
	char *cmd;
	int mode;
	unsigned int idx;
} global_t;

extern global_t var;

void free_var(void);
void free_stack(void);
void run_cmd(char *bufline);
void (*get_cmd(void))(stack_t **head, unsigned int line_number);
void erro(int code, ...);
void erro_ext(int code, int va_arg);
char *ivstg(char *operand, unsigned int line_number);
void pusher(stack_t **stack, unsigned int line_number);
void paller(stack_t **stack, unsigned int line_number);
void pinter(stack_t **stack, unsigned int line_number);
void popper(stack_t **stack, unsigned int line_number);
void swapper(stack_t **stack, unsigned int line_number);
void adder(stack_t **stack, unsigned int line_number);
void subber(stack_t **stack, unsigned int line_number);
void divider(stack_t **stack, unsigned int line_number);
void multpler(stack_t **stack, unsigned int line_number);
void modder(stack_t **stack, unsigned int line_number);
void nopper(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void changemode(stack_t **stack, unsigned int line_number);

#endif
