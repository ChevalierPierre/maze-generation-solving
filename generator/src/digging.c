/*
** EPITECH PROJECT, 2018
** dante
** File description:
** digging
*/

#include "maze.h"

static int random_pick(maze_t *maze, int i, int j)
{
	if (maze->perfect == true) {
		if (rand() % 2 == 1)
			maze->map[i][j - 1] = EMPTY;
		else
			maze->map[i - 1][j] = EMPTY;
		return (0);
	}
	else if (maze->perfect == false) {
		if (rand() % 2 == 0) {
			maze->map[i][j - 1] = EMPTY;
			maze->map[i - 1][j] = EMPTY;
		}
		else if (rand() % 2 == 1)
			maze->map[i - 1][j] = EMPTY;
		else
			maze->map[i][j - 1] = EMPTY;
		return 0;
	}
	else
		return 84;
}

static int choose(maze_t *maze, int i, int j)
{
	if (i == 0 && j == 0)
		return (0);
	if (i == 0)
		if (maze->map[i][j] == EMPTY) {
			maze->map[i][j - 1] = EMPTY;
			return (0);
		}
	if (j == 0 && i != 0)
		if (maze->map[i][j] == EMPTY) {
			maze->map[i - 1][j] = EMPTY;
			return (0);
		}
	if (maze->map[i][j] == EMPTY)
		random_pick(maze, i, j);
	return (0);
}

int digging(maze_t *maze)
{
	for (int i = 0 ; maze->map[i] != NULL ; i++)
		for (int j = 0 ; maze->map[i][j] != '\0' ; j++)
			choose(maze, i, j);
	return (0);
}
