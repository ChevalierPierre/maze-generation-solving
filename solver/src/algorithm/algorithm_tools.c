/*
** EPITECH PROJECT, 2018
** solver
** File description:
** tools for a star algorithm
*/

#include "algorithm.h"

room_t get_room(int x, int y)
{
	room_t room = {x, y};

	return (room);
}

int is_same_room(room_t *r1, room_t *r2)
{
	return ((r1->x == r2->x) && (r1->y == r2->y));
}

element_t *element_dup(element_t *element)
{
	element_t *new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);
	new->room = get_room(element->room.x, element->room.y);
	new->cost = element->cost;
	new->score = element->score;
	new->prev = get_room(element->prev.x, element->prev.y);
	new->next = element->next;
	return (new);
}

int is_in_list(list_t *list, element_t *current)
{
	element_t *tmp = list->first;

	while (tmp != NULL) {
		if (is_same_room(&tmp->room, &current->room))
			return (tmp->cost < current->cost ? 1 : 0);
		tmp = tmp->next;
	}
	return (0);
}

double compute_square_distance(room_t *room, room_t *exit)
{
	double a = (room->x - exit->x) * (room->x - exit->x);
	double b = (room->y - exit->y) * (room->y - exit->y);

	return (a + b);
}
