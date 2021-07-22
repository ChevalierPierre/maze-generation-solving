/*
** EPITECH PROJECT, 2018
** dante solver
** File description:
** open and reads a file and checks if there's no error
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "maze.h"

int strlen_no_return(char const *line)
{
	int len = strlen(line);

	if (line[len - 1] == '\n')
		return (--len);
	return (len);
}

int get_first_line(maze_t *maze, FILE *file, size_t *n)
{
	maze->map = malloc(sizeof(char *));
	if (maze->map == NULL || getline(&maze->map[0], n, file) == -1 ||
	maze->map[0] == NULL)
		return (1);
	maze->x = strlen_no_return(maze->map[0]);
	return (0);
}

int open_and_read_file(char const *path, maze_t *maze)
{
	FILE *file = fopen(path, "r");
	int i = 1;
	size_t n = 0;

	if (file == NULL)
		return (1);
	if (get_first_line(maze, file, &n) == 1) {
		fclose(file);
		return (1);
	}
	do {
		maze->map = realloc(maze->map, sizeof(char *) * (i + 1));
		if (maze->map == NULL || strlen_no_return(maze->map[i - 1]) !=
		maze->x) {
			fclose(file);
			return (1);
		}
		maze->map[i] = NULL;
	} while (getline(&maze->map[i++], &n, file) != -1);
	free(maze->map[i - 1]);
	maze->map[i - 1] = NULL;
	maze->y = i - 1;
	fclose(file);
	return (0);
}
