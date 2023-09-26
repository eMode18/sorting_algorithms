#include "sort.h"

/**
 * swap_pointers - Rearrange the order of two nodes
 * in a listint_t doubly-linked list.
 * @h: Pointer pointing to the head of the doubly-linked list.
 * @a1: Pointer to the initial node for swapping.
 * @b2: The second node to be swapped.
 */

void swap_pointers(listint_t **h, listint_t **a1, listint_t *b2)
{
	(*a1)->next = b2->next;
	if (b2->next != NULL)
		b2->next->prev = *a1;
	b2->prev = (*a1)->prev;
	b2->next = *a1;
	if ((*a1)->prev != NULL)
		(*a1)->prev->next = b2;
	else
		*h = b2;
	(*a1)->prev = b2;
	*a1 = b2->prev;
}

/**
 * insertion_sort_list - Applies the insertion sort algorithm to sort
 *a doubly linked list of integers.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: This function sorts the list and prints it after
 *each swap operation.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *loop, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (loop = (*list)->next; loop != NULL; loop = temp)
	{
		temp = loop->next;
		insert = loop->prev;
		while (insert != NULL && loop->n < insert->n)
		{
			swap_pointers(list, &insert, loop);
			print_list((const listint_t *)*list);
		}
	}
}
