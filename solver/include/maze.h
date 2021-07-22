/*
** EPITECH PROJECT, 2018
** maze
** File description:
** header
*/

#ifndef MAZE_H_
#define MAZE_H_

typedef struct maze {
	char **map;
	int x;
	int y;
} maze_t;

enum exit_value {
	SUCCESS_EXIT = 0,
	FAILURE_EXIT = 84
};

void destroy_tab(char **tab);
int open_and_read_file(char const *path, maze_t *maze);
int my_pow_rec(int nb, int n);

#endif
