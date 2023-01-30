#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the cocktail sort algorithm
 *
 * @list: pointer to the doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *first = NULL, *last = NULL;
	size_t swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	do {
		swapped = 0;
		while (current->next != last)
		{
			current = current->next;
			if (current->n < current->prev->n)
			{
				if (current->prev->prev == NULL)
					*list = current;
				swap_nodes(current->prev, current);
				swapped = 1;
				print_list(*list);
				current = current->next;
			}
		}
		if (!swapped)
			break;
		last = current;
		swapped = 0;
		while (current->prev != first)
		{
			current = current->prev;
			if (current->n > current->next->n)
			{
				if (current->prev == NULL)
					*list = current->next;
				swap_nodes(current, current->next);
				swapped = 1;
				print_list(*list);
				current = current->prev;
			}
		}
		first = current;
	} while (first != last);
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
