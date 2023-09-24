#include "sort.h"

/**
 * insertion_sort_list -sort a doubly linked list
 * using insertion sort algorithm
 *
 * @list: double linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sort_list, *unsort_list, *temp;

	if (list == NULL || *list == NULL)
		return;

	temp = (*list)->next;

	while (temp != NULL)
	{
		unsort_list = temp->next;
		sort_list = temp->prev;

		while (sort_list != NULL && sort_list->n > temp->n)
		{

			if (sort_list->prev != NULL)
				sort_list->prev->next =  temp;
			else
				*list = temp;

			if (temp->next != NULL)
				temp->next->prev = sort_list;

			sort_list->next = temp->next;
			temp->prev = sort_list->prev;

			temp->next = sort_list;
			sort_list->prev = temp;

			sort_list = temp->prev;
			print_list(*list);
		}

		temp = unsort_list;
	}
}

