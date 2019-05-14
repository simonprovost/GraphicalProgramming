/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** count the number of character of a string given as parameter
*/

int my_strlen(char const *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i]) {
		i++;
	}
	return (i);
}
