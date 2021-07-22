/*
** EPITECH PROJECT, 2018
** solver
** File description:
** add or remove element from lists
*/

#include "algorithm.h"

int remove_first(list_t *list)
{
	if (list == NULL || list->first == NULL)
		return (1);
	list->first = list->first->next;
	list->size--;
	if (list->size == 0)
		list->last = NULL;
	return (0);
}

void add_with_priority(list_t *list, element_t *element)
{
	element_t *tmp = list->first;
	element_t *tmp2 = NULL;

	while (tmp) {
		if (tmp->score > element->score) {
			if (tmp2 == NULL) {
				element->next = list->first;
				list->first = element;
			} else {
				tmp2->next = element;
				element->next = tmp;
			}
			return;
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	element->next = NULL;
	list->last->next = element;
	list->last = element;
}

int add_to_list(list_t *list, element_t *element, int priority)
{
	element_t *new = element_dup(element);

	if (new == NULL || list == NULL || element == NULL)
		return (1);
	if (list->first == NULL) {
		new->next = NULL;
		list->first = new;
		list->last = new;
	} else {
		if (priority == 1) {
			add_with_priority(list, new);
		} else {
			new->next = NULL;
			list->last->next = new;
			list->last = new;
		}
	}
	list->size++;
	return (0);
}
