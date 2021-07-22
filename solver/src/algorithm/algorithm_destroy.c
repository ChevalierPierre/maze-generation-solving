/*
** EPITECH PROJECT, 2018
** solver
** File description:
** destroy
*/

#include "algorithm.h"

void destroy_list(list_t *list)
{
	element_t *tmp;

	if (list == NULL)
		return;
	tmp = list->first;
	while (tmp) {
		tmp = tmp->next;
		free(list->first);
		list->first = tmp;
	}
}
