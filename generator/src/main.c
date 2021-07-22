/*
** EPITECH PROJECT, 2018
** generator dante
** File description:
** main
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "maze.h"
#include "my_strings.h"

static int display_maze(maze_t *maze)
{
	for (int i = 0 ; i < maze->height - 1 ; i++) {
		write(1, maze->map[i], maze->width);
		write(1, "\n", 1);
	}
	write(1, maze->map[maze->height - 1], maze->width);
	return (0);
}

static int usage(int ret)
{
	printf("USAGE:\t./generator x y [perfect]\n\n");
	printf("\tx\twidth of the maze to generate\n");
	printf("\ty\theight of the maze to generate\n");
	printf("\tperfect\tgenerate a perfect maze (optional)\n");
	return (ret);
}

int main(int ac, char **av)
{
	maze_t maze = {NULL, 0, 0, true};

	if (ac == 2 && strcmp(av[1], "-h") == 0)
		return (usage(0));
	if (ac < 3 || ac > 4)
		return (usage(84));
	if (init_maze(&maze, ac, av) == 1)
		return (84);
	digging(&maze);
	display_maze(&maze);
	destroy_tab(maze.map);
	return (0);
}
