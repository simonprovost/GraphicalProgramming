/*
** EPITECH PROJECT, 2017
** my is prime
** File description:
** returns 1 if prime and 0 if not
*/

int my_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	for (int i = nb - 1; i > 1; i--) {
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
