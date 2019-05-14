/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** take a string put it in number
*/

#include <limits.h>

int my_getnbr(char const *str)
{
	int n = 1;
	long int res = 0;
	int i = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58) {
		res += str[i] - '0';
		res *= 10;
		i++;
	}
	return ((res > INT_MAX || res < INT_MIN) ? (84) : (n * res / 10));
}
