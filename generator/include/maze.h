/*
** EPITECH PROJECT, 2018
** maze
** File description:
** header
*/

#ifndef MAZE_H_
#define MAZE_H_

#include <stdbool.h>
#include <stdlib.h>

#define EMPTY '*'
#define WALL 'X'

typedef struct maze {
	char **map;
	int width;
	int height;
	bool perfect;
} maze_t;

int init_maze(maze_t *maze, int ac, char **av);
int digging(maze_t *maze);

#endif
