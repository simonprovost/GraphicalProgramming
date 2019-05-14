/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

char* my_itoa(int i, char *b)
{
	char const digit[] = "0123456789";
	char *p = b;
	int shifter = i;

	if (i < 0) {
		*p++ = '-';
		i *= -1;
	}
	do {
		++p;
		shifter = shifter / 10;
	} while (shifter);
	*p = '\0';
	do {
		*--p = digit[i % 10];
		i = i / 10;
	} while (i);
	return (b);
}