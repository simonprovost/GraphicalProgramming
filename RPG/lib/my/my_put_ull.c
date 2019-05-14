/*
** EPITECH PROJECT, 2017
** my_put_ull.c
** File description:
** display an unsigned long long (ull)
*/

void my_putchar(char);

void my_put_ull(unsigned long long nb)
{
	unsigned long long mod = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = nb % 10;
			nb = (nb - mod) / 10;
			my_put_ull(nb);
			my_putchar(48 + mod);
		} else
			my_putchar(48 + nb % 10);
	}
}
