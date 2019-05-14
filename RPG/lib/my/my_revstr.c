/*
** EPITECH PROJECT, 2017
** my revstr
** File description:
** reverse the string ( hawai --> iawah )
*/

char *my_revstr(char *str)
{
	int z = 0;
	int i = 0;
	char stock = 0;

	while (str[z] != 0)
		z++;
	z--;
	while (i < z) {
		stock = str[z];
		str[z] = str[i];
		str[i] = stock;
		i++;
		z--;
	}
	return (str);
}
