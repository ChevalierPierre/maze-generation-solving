/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** displays a char string
*/

#include <unistd.h>
#include "my_strings.h"

int my_putstr_fd(char const *str, int fd)
{
	int len = my_strlen(str);

	if (fd < 0)
		return (1);
	if (write(fd, str, len) < len)
		return (1);
	return (0);
}
