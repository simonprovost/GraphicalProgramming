/*
** EPITECH PROJECT, 2017
** my str lower case
** File description:
** puts every letters in lowercase
*/

char *my_strlowcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
