/*
** EPITECH PROJECT, 2017
** my_print_ftc1.c
** File description:
** 1st part of all printf functions
*/

#include <stdarg.h>
#include "../../include/my.h"

void my_printllnumber(va_list list)
{
	long long int lli = va_arg(list, long long int);

	my_put_llnbr(lli);
}

void my_printunsignedint(va_list list)
{
	unsigned long long ui = va_arg(list, unsigned long long);

	my_put_ull(ui);
}

void my_printchar(va_list list)
{
	char c = (char)va_arg(list, int);

	my_putchar(c);
}

void my_printint(va_list list)
{
	int i = va_arg(list, int);

	my_put_nbr(i);
}

void my_printstr(va_list list)
{
	char *str = va_arg(list, char *);

	if (str)
		my_putstr(str);
}
