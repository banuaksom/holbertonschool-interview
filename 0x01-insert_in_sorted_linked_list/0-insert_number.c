#include "lists.h"
/**
  * insert_node - inserts a new node
  * @head: pointer
  * @number: value of the node
  * Return: address of a new node
  */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else if ((*head)->n >= number)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        while ((current->next != NULL) && (current->next->n < number))
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
    return (new);
}
