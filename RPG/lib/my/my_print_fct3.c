/*
** EPITECH PROJECT, 2017
** my_print_ftc3.c
** File description:
** 2nd part of all printf functions
*/

#include <stdarg.h>
#include "../../include/my.h"

void my_printpercent(va_list list)
{
	(void)(list);
	my_putchar('%');
}

void my_printformatedstring(va_list list)
{
	int i = 0;
	int dec = 0;
	char *str = va_arg(list, char *);

	while (str[i] != 0) {
		dec = str[i];
		if (dec < 8 && (str[i] < 32 || str[i] >= 127))
			my_printf("\\00%o", dec);
		if (dec >= 8 && dec < 64 && (str[i] < 32 || str[i] >= 127))
			my_printf("\\0%o", dec);
		if (dec >= 64 && (str[i] < 32 || str[i] >= 127))
			my_printf("\\%o", dec);
		if (str[i] > 31 && str[i] < 127)
			my_putchar(str[i]);
		i++;
	}
}
