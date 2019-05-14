/*
** EPITECH PROJECT, 2017
** my str n cat
** File description:
** concatenates two strings
*/

#include <stdio.h>

char *my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int z = 0;

	while (dest[i] != 0)
		i++;
	while (z < nb) {
		dest[i] = src[z];
		i++;
		z++;
	}
	dest[i] = '\0';
	return (dest);
}
