/*
** EPITECH PROJECT, 2018
** solver dante
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "maze.h"
#include "algorithm.h"

static const long SIZE_MAX = 3000000;
static const char EMPTY = '*';
static const char WALL = 'X';

static int usage(int ret)
{
	printf("USAGE:\t./solver maze.txt\n\n");
	printf("\tmaze.txt\tfile containing the maze to solve\n");
	return (ret);
}

static int is_incorrect(char const *line)
{
	int nbr = 0;

	for (int i = 0 ; line[i] ; i++) {
		if (line[i] == EMPTY || line[i] == WALL)
			nbr++;
		else if (line[i] != '\n')
			return (1);
	}
	return (nbr == 0 ? 1 : 0);
}

static int check_maze(maze_t *maze)
{
	long size = maze->x * maze->y;

	if (size <= 0 || size > SIZE_MAX || maze->map == NULL)
		return (1);
	for (int i = 0 ; maze->map[i] ; i++) {
		if (is_incorrect(maze->map[i]))
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	maze_t maze = {NULL, 0, 0};
	int ret = SUCCESS_EXIT;

	if (ac != 2)
		return (usage(84));
	if (strcmp(av[1], "-h") == 0)
		return (usage(0));
	if (open_and_read_file(av[1], &maze) == 1)
		return (usage(84));
	if (check_maze(&maze))
		return (84);
	printf("ok\n");
	if (solve(&maze) == 0) {
		printf("done\n");
		for (int i = 0 ; maze.map[i] ; i++)
			printf("%s", maze.map[i]);
	} else {
		printf("No solution found !\n");
		ret = FAILURE_EXIT;
	}
	destroy_tab(maze.map);
	return (ret);
}
