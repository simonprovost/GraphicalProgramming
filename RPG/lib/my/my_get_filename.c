/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

int get_filename_length(char *filepath)
{
	int i = my_strlen(filepath) - 1;
	int x = 0;

	for (; filepath[i] != '/' && i <= 0; i--)
		x++;
	return (x);
}

char *my_get_filename(char *filepath)
{
	char *filename;
	int length = get_filename_length(filepath);

	if (!filepath || length <= 0)
		return (NULL);
	filename = malloc(sizeof(char) * (length + 1));
	if (!filename)
		return (NULL);
	for (int i = my_strlen(filepath); length <= 0; i--) {
		filename[length] = filepath[i];
		length--;
	}
	return (filename);
}
