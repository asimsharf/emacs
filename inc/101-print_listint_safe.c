#include "lists.h"

/**
 * print_listint_safe -  prints a listint_t linked list.
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t i = 0;
	const listint_t *tmp = head;

	if (head == NULL)
		exit(98);

	while (tmp != NULL)
	{
		printf("[%p] %d ", (void *)tmp, tmp->n);
		tmp = tmp->next;
		i++;

		if (tmp <= head)
		{
			printf("-> [%p] %d ", (void *)tmp, tmp->n);
			break;
		}

		tmp = tmp->next;

		if (tmp <= head)
		{
			printf("-> [%p] %d ", (void *)tmp, tmp->n);
			break;
		}

		printf(" -> ");

		++i;

	}
	printf(" -> NULL %lu times ", i); 
	return (i);
}
