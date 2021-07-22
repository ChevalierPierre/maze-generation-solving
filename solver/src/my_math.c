/*
** EPITECH PROJECT, 2018
** solver
** File description:
** compute math functions
*/

int my_pow_rec(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	return (nb * my_pow_rec(nb, p - 1));
}
