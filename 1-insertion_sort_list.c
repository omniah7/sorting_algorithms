#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Bubble sort algorithm
 *
 * @list: pointer to the doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		if (current->n < current->prev->n)
		{
			tmp = current->prev;
			while (current->prev && current->n < current->prev->n)
			{
				if (current->prev->prev == NULL)
					*list = current;
				swap_nodes(current->prev, current);
				print_list(*list);
			}
			current = tmp->next;
		}
		else
			current = current->next;
	}
}
/**
 * swap_nodes - swaps two nodes in a doubly linked list
 *
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	listint_t *prev, *next;

	a->next = b->next;
	b->prev = a->prev;
	prev = a->prev;
	next = b->next;
	a->prev = b;
	b->next = a;
	if (prev)
		prev->next = b;
	if (next)
		next->prev = a;
}
