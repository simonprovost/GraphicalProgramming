/*
** EPITECH PROJECT, 2017
** my str is alpha
** File description:
** my is alpha
*/

int my_str_isalpha(char const *str)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a')
		|| str[i] > 'z')
			return (1);
	}
	return (0);
}
