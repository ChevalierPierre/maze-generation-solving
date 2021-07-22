/*
** EPITECH PROJECT, 2018
** solver
** File description:
** main function to compute moves
*/

#include "algorithm.h"

static char EMPTY = '*';

int init_open_list(list_t *list, maze_t *maze)
{
	element_t *first;

	if (maze->map == NULL || maze->map[0][0] != EMPTY ||
	maze->map[maze->y - 1][maze->x - 1] != EMPTY)
		return (1);
	first = malloc(sizeof(*first));
	if (first == NULL)
		return (1);
	first->room = get_room(0, 0);
	first->next = NULL;
	first->prev = get_room(0, 0);
	first->cost = 0;
	first->score = 0;
	list->first = first;
	list->last = first;
	list->size = 1;
	return (0);
}

int make_path(maze_t *maze, list_t *closed_list, list_t *open_list, element_t *final)
{
	element_t *cursor = closed_list->last;
	element_t *tmp = NULL;

	maze->map[final->room.y][final->room.x] = 'o';
	maze->map[cursor->room.y][cursor->room.x] = 'o';
	while (cursor->room.x != 0 || cursor->room.y != 0) {
		tmp = closed_list->first;
		while (is_same_room(&tmp->room, &cursor->prev) == 0)
			tmp = tmp->next;
		cursor = tmp;
		maze->map[cursor->room.y][cursor->room.x] = 'o';
	}
	free(final);
	destroy_list(open_list);
	destroy_list(closed_list);
	return (0);
}

static void get_neighbor(int *x, int *y, int i)
{
	if (i % 2 == 0) {
		*y = 0;
		*x = (i == 0 ? 1 : -1);
	} else {
		*x = 0;
		*y = (i == 1 ? 1 : -1);
	}
}

static void check_in_lists(element_t *current, list_t *open_list,
			list_t *closed_list, maze_t *maze)
{
	static element_t neighbor = {NULL, {0, 0}, 0, 0, {0, 0}};
	int x = 0;
	int y = 0;
	room_t end = get_room(maze->x - 1, maze->y - 1);

	neighbor.prev = get_room(current->room.x, current->room.y);
	for (int i = 0 ; i < 4 ; i++) {
		get_neighbor(&x, &y, i);
		neighbor.room = get_room(current->room.x + x,
					current->room.y + y);
		if (neighbor.room.x < 0 || neighbor.room.y < 0 ||
		neighbor.room.x >= maze->x || neighbor.room.y >= maze->y ||
		maze->map[neighbor.room.y][neighbor.room.x] != EMPTY ||
		is_in_list(closed_list, &neighbor) ||
		is_in_list(open_list, &neighbor))
			continue;
		else {
			neighbor.cost = current->cost + 1;
			neighbor.score = neighbor.cost +
				compute_square_distance(&neighbor.room, &end);
			add_to_list(open_list, &neighbor, 1);
		}
	}
}

int solve(maze_t *maze)
{
	list_t open_list;
	list_t closed_list = {NULL, NULL, 0};
	element_t *current = NULL;

	if (init_open_list(&open_list, maze) == 1)
		return (1);
	while (open_list.size != 0) {
		current = open_list.first;
		remove_first(&open_list);
		if (maze->map[current->room.y][current->room.x + 1] == 0)
			return (make_path(maze, &closed_list, &open_list, current));
		check_in_lists(current, &open_list, &closed_list, maze);
		add_to_list(&closed_list, current, 0);
		free(current);
	}
	return (0);
}
