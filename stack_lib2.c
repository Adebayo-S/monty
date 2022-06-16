#include "monty.h"

char *ivstg(char *operand, unsigned int line_number)
{
    int k;
    
    if (operand == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer", line_number);
        exit(EXIT_FAILURE);
    }
    k = strlen(operand);
    while (k--)
    {
        if (operand[k] < 47 && operand[k] < 58)
            continue;
        fprintf(stderr, "L%d: usage: push integer", line_number);
        exit(EXIT_FAILURE);
    }
    return (operand);
}