/*
** EPITECH PROJECT, 2017
** CPE_getnextline_2017
** File description:
** (CPE_getnextline_2017)
*/

#include "../../include/my.h"

char *my_realloc(char *str, int len)
{
	char *new_str = malloc(sizeof(char) * (READ_SIZE + len + 1));

	if (!new_str)
		return (NULL);
	for (int j = 0; j < len; j++) {
		new_str[j] = str[j];
		new_str[j + 1] = 0;
	}
	free(str);
	return (new_str);
}

char get_my_char(int fd)
{
	static char str[READ_SIZE + 1];
	static int len = 0;
	static int i = 0;

	if (len == i) {
		len = read(fd, str, READ_SIZE);
		if (len == 0)
			return (0);
		i = 0;
	}
	i++;
	return (str[i - 1]);
}

char *my_get_next_line(int fd)
{
	char *str = malloc(sizeof(char) * (READ_SIZE + 1));

	if (fd == -1 || !str)
		return (NULL);
	for (int i = 0; 1; i++) {
		if (i % READ_SIZE == 0)
			str = my_realloc(str, i);
		str[i] = get_my_char(fd);
		if (str[i] == '\n') {
			str[i] = 0;
			break;
		}
		if (str[i] == 0 && i == 0) {
			free(str);
			return (NULL);
		} else if (str[i] == 0 && i != 0)
			return (str);
	}
	return (str);
}
