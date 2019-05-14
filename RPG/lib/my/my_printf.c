/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my printf fonction
*/

#include <stdarg.h>
#include "../../include/my.h"

void initializer2(fnct_t *tab)
{
	tab[10].balise = '%';
	tab[10].fptr = &my_printpercent;
	tab[11].balise = 'S';
	tab[11].fptr = &my_printformatedstring;
}

void initializer(fnct_t *tab)
{
	tab[0].balise = 'c';
	tab[0].fptr = &my_printchar;
	tab[1].balise = 'd';
	tab[1].fptr = &my_printint;
	tab[2].balise = 'i';
	tab[2].fptr = &my_printint;
	tab[3].balise = 's';
	tab[3].fptr = &my_printstr;
	tab[4].balise = 'u';
	tab[4].fptr = &my_printunsignedint;
	tab[5].balise = 'x';
	tab[5].fptr = &my_printlowhexa;
	tab[6].balise = 'X';
	tab[6].fptr = &my_printuphexa;
	tab[7].balise = 'b';
	tab[7].fptr = &my_printbinary;
	tab[8].balise = 'p';
	tab[8].fptr = &my_printadress;
	tab[9].balise = 'o';
	tab[9].fptr = &my_printoctal;
}

void redirector(fnct_t *tab, char type, va_list list, int *i)
{
	if (type == '\0')
		(*i)--;
	for (int j = 0; j < 12; j++) {
		if (tab[j].balise == type)
			tab[j].fptr(list);
	}
}

int my_printf(char *str, ...)
{
	va_list list;
	fnct_t tab[12];
	int i = 0;

	initializer(tab);
	initializer2(tab);
	va_start(list, str);
	while (str[i] != '\0') {
		if (str[i] == '%') {
			i++;
			redirector(tab, str[i], list, &i);
		} else
			my_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (0);
}
