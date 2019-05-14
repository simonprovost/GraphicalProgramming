/*
** EPITECH PROJECT, 2017
** my strncpy
** File description:
** copies n characters of a string into another string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;
	int x = 0;

	while (src[x] != '\0')
		x++;
	if (n > x) {
		while (i < x) {
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	} else {
		while (i < n) {
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
