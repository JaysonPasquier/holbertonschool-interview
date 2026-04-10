#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to head of list
 * @number: integer to insert
 *
 * Return: address of the new node, or NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);
    new->n = number;

    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    current = *head;
    while (current->next && current->next->n < number)
        current = current->next;

    new->next = current->next;
    current->next = new;

    return (new);
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main2(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);

    printf("-----------------\n");

    insert_node(&head, 27);

    print_listint(head);


    free_listint(head);

    return (0);
}
