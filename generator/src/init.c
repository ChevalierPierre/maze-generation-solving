/*
** EPITECH PROJECT, 2018
** generator dante
** File description:
** init
*/

#include <string.h>
#include "maze.h"
#include "my_strings.h"

static const char *NB_ERROR = "Width and height must be strictly positive\
 numbers\n";
static const char *MALLOC_ERROR = "Malloc failed !\n";
static const char *ARGUMENT = "Third argument unknown !\n";

int display_message(char const *str, int fd)
{
	my_putstr_fd(str, fd);
	return (1);
}

static int generate_maze(maze_t *maze)
{
	int len = maze->width + 1;

	maze->map = malloc(sizeof(char *) * (maze->height + 1));
	if (maze->map == NULL)
		return (display_message(MALLOC_ERROR, 2));
	for (int i = 0 ; i < maze->height ; i++) {
		maze->map[i] = calloc(len, 1);
		if (maze->map[i] == NULL)
			return (display_message(MALLOC_ERROR, 2));
		for (int j = 0 ; j < len - 1 ; j++)
			maze->map[i][j] = (i % 2 == 0 && j % 2 == 0 ?
					EMPTY : WALL);
	}
	maze->map[maze->height] = NULL;
	maze->map[0][0] = EMPTY;
	maze->map[maze->height - 1][maze->width - 1] = EMPTY;
	return (0);
}

int init_maze(maze_t *maze, int ac, char **av)
{
	if (ac == 4) {
		if (strcmp(av[3], "imperfect") == 0)
			maze->perfect = false;
		else if (strcmp(av[3], "perfect") == 0)
			maze->perfect = true;
		else
			return (display_message(ARGUMENT, 1));
	}
	if (my_get_check_nbr(av[1], &maze->width) == 1 || maze->width < 1)
		return (display_message(NB_ERROR, 1));
	if (my_get_check_nbr(av[2], &maze->height) == 1 || maze->height < 1)
		return (display_message(NB_ERROR, 1));
	return (generate_maze(maze));
}
