/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** .c
*/

int my_strlen(char const *str)
{
	int count = 0;

	for (; str[count] != '\0' ; count++);
	return (count);
}
