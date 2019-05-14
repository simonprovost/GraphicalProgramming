/*
** EPITECH PROJECT, 2017
** my_put_llnbr.c
** File description:
** display up to long long int
*/

void my_putchar(char);

void my_put_llnbr(long long int nb)
{
	long long int mod = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = nb % 10;
			nb = (nb - mod) / 10;
			my_put_llnbr(nb);
			my_putchar(48 + mod);
		} else
			my_putchar(48 + nb % 10);
	}
}
