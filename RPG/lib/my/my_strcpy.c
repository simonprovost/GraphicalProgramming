/*
** EPITECH PROJECT, 2017
** my strcpy
** File description:
** copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (dest[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
