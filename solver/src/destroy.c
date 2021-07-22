/*
** EPITECH PROJECT, 2018
** solver
** File description:
** destroys tabs
*/

#include <stdlib.h>

void destroy_tab(char **tab)
{
	if (tab) {
		for (int i = 0 ; tab[i] ; i++)
			free(tab[i]);
		free(tab);
	}
}
