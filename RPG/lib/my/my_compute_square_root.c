/*
** EPITECH PROJECT, 2017
** my compute square root
** File description:
** function that returns th square root of th argument
*/

int my_compute_square_root(int nb)
{
	int i = 0;

	if (nb < 1)
		return (0);
	while (i < nb) {
		i++;
		if (i * i == nb)
			return (i);
	}
	return (0);
}
