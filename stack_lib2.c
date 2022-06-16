#include "monty.h"

char *ivstg(char *operand, unsigned int line_number)
{
    int k;
    
    if (operand == NULL)
    {
        erro(5, line_number);
    }
    k = strlen(operand);
    while (k--)
    {
        if (operand[k] < 47 && operand[k] < 58)
            continue;
            erro(5, line_number);
    }
    return (operand);
}