/*
** EPITECH PROJECT, 2017
** my compute factorial rec
** File description:
** same as my compute compute it but recursive
*/

int my_compute_power_rec(int nb, int p)
{
	int r = 0;

	if (p == 0 || p == 1) {
		if (p == 0)
			return (1);
		else
			return (nb);
	} else if (p > 0) {
		r = nb * my_compute_power_rec(nb, p - 1);
	}
	return (r);
}
