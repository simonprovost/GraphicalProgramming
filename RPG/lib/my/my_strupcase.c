/*
** EPITECH PROJECT, 2017
** my str upcase
** File description:
** puts every letters in upercase
*/

char *my_strupcase(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] > 96 && str[i] < 123)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
