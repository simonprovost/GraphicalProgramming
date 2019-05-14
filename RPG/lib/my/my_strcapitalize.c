/*
** EPITECH PROJECT, 2017
** my str capitalize
** File description:
** capitalize the str
*/

#include <stdio.h>
#include <string.h>

void my_uppercase(int i, char *str)
{
	if (str[i] > 64 && str[i] < 91)
		str[i] = str[i] + 32;
}

void my_lowcase(int i, char *str)
{
	if (str[i] > 96 && str[i] < 123)
		str[i] = str[i] - 32;
}

char *my_strcapitalize(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i - 1] > 64 && str[i - 1] < 91)
		|| (str[i - 1] > 96 && str[i - 1] < 123)
		|| (str[i - 1] > 47 && str[i - 1] < 58))
			my_uppercase(i, str);
		else
			my_lowcase(i, str);
		i = i + 1;
	}
	return (str);
}
