/*
** EPITECH PROJECT, 2017
** my str  is lower
** File description:
** is lower
*/

int my_str_islower(char const *str)
{
	int i = 0;

	while (str[i] != 0) {
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i = i + 1;
	}
	return (1);
}
