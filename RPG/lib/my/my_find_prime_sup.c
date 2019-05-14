/*
** EPITECH PROJECT, 2017
** my find prime sup
** File description:
** prime sup
*/

int my_find_prime_sup(int nb)
{
	int not_prime = 0;

	if (nb < 2)
		return (2);
	for (int i = nb - 1; i > 1; i = i - 1) {
		if (nb % i == 0)
			not_prime = 1;
	}
	if (not_prime == 1)
		return (my_find_prime_sup(nb + 1));
	return (nb);
}
