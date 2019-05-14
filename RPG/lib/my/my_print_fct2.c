/*
** EPITECH PROJECT, 2017
** my_print_ftc2.c
** File description:
** 2nd part of all printf functions
*/

#include <stdarg.h>
#include "../../include/my.h"

void my_printlowhexa(va_list list)
{
	long long unsigned lhexa = va_arg(list, long long unsigned);

	my_putnbr_base(lhexa, "0123456789abcdef");
}

void my_printuphexa(va_list list)
{
	long long unsigned uphexa = va_arg(list, long long unsigned);

	my_putnbr_base(uphexa, "0123456789ABCDEF");
}

void my_printbinary(va_list list)
{
	int bin = va_arg(list, long long unsigned);

	my_putnbr_base(bin, "01");
}

void my_printadress(va_list list)
{
	long long unsigned adress;

	adress = va_arg(list, long long unsigned);
	my_printf("0x");
	my_putnbr_base(adress, "0123456789abcdef");
}

void my_printoctal(va_list list)
{
	long long unsigned oct = va_arg(list, long long unsigned);

	my_putnbr_base(oct, "01234567");
}
