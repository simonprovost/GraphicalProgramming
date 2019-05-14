/*
** EPITECH PROJECT, 2017
** my str str
** File description:
** str str fonction
*/

#include <stdio.h>

int occur(char const *str, char const *to_find, int maxx, int *i)
{
	int j = 0;

	while (str[*i] == to_find[j]) {
		if (str[*i] == to_find[maxx] && j == maxx)
			return (1);
		*i = *i + 1;
		j = j + 1;
	}
	*i = *i - j;
	j = 0;
	return (0);
}

char *my_strstr(char const *str, char const *to_find)
{
	int i = 0;
	int maxx = 0;
	int res = 0;

	while (to_find[maxx] != '\0')
		maxx = maxx + 1;
	if (maxx == 0)
		return ((char *) &(str[0]));
	maxx = maxx - 1;
	while (str[i] != '\0') {
		if (str[i] == to_find[0])
			res = occur(str, to_find, maxx, &i);
		if (res == 1)
			return ((char *)&(str[i - maxx]));
		i = i + 1;
	}
	return (0);
}
