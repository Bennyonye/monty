#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    // Check if bus.arg is not NULL
    if (bus.arg)
    {
        // Handle negative sign
        if (bus.arg[0] == '-')
            j++;

        // Check if the characters are digits
        for (; bus.arg[j] != '\0'; j++)
        {
            // Check if the character is not a digit
            if (bus.arg[j] > '9' || bus.arg[j] < '0')
                flag = 1;
        }

        // If non-digit characters are found, print an error message
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // If bus.arg is NULL, print an error message
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    // Convert the string to an integer using atoi
    n = atoi(bus.arg);

    // Add the node to the stack
    addnode(head, n);
}
