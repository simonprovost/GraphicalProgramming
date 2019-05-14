/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** take number, change it in given base
*/

void my_putchar(char);
int my_strlen(char *);

void my_putnbr_base(unsigned long long nb, char *base)
{
	unsigned long long length = my_strlen(base);

	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	if (nb >= length) {
		my_putnbr_base(nb / length, base);
	}
	my_putchar(base[nb % length]);
}
