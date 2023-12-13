#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: not used
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter; // Counter is not used, so we silence the unused variable warning

    h = *head;

    // Check if the stack is empty
    if (h == NULL)
    {
        return; // If the stack is empty, no need to print anything
    }

    // Loop through the stack and print each element
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
