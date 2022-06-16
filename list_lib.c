#include "monty.h"


stack_t *makenode(int x)
{
    stack_t *newnode;

    newnode = malloc(sizeof(stack_t));
    if (!newnode)
    {
        h_error("Error: malloc failed", NULL);
    }
    newnode->prev = NULL;
    newnode->n = x;
    newnode->next = NULL;
    return (newnode);
}