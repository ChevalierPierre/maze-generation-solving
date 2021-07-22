/*
** EPITECH PROJECT, 2017
** my_strings.h
** File description:
** contains the header of all string-related functions
*/

#ifndef MY_STRINGS_H_
#define MY_STRINGS_H_

void destroy_tab(char **tab);
int my_get_check_nbr(char const *str, int *n);
int my_putstr_fd(char const *str, int fd);
int my_strlen(char const *str);

#endif
