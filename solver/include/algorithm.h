/*
** EPITECH PROJECT, 2018
** algorithm
** File description:
** header
*/

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <stdlib.h>
#include "maze.h"

typedef struct room {
	int x;
	int y;
} room_t;

typedef struct element {
	struct element *next;
	room_t room;
	int cost;
	double score;
	room_t prev;
} element_t;

typedef struct list {
	element_t *first;
	element_t *last;
	int size;
} list_t;

int remove_first(list_t *list);
void add_with_priority(list_t *list, element_t *element);
int add_to_list(list_t *list, element_t *element, int priority);

int init_open_list(list_t *list, maze_t *maze);
int make_path(maze_t *maze, list_t *closed_list, list_t *open_list,
	element_t *final);
int solve(maze_t *maze);

element_t *element_dup(element_t *element);
int is_in_list(list_t *list, element_t *current);
double compute_square_distance(room_t *room, room_t *exit);

void destroy_list(list_t *list);

room_t get_room(int x, int y);
int is_same_room(room_t *r1, room_t *r2);

#endif
