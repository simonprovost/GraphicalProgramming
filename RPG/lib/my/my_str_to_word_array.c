/*
** EPITECH PROJECT, 2017
** PSU_my_exec_2018
** File description:
** (main.c bootstrap minishell_1)
*/

#include "../../include/my.h"

int count_words(char *str, char sep)
{
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '\n') {
			str[i] = 0;
		}
		if (str[i] != sep && str[i + 1] == sep) {
			count++;
		} else if (str[i] != sep && str[i + 1] == 0) {
			count++;
		}
	}
	return (count);
}

int alloc_my_words(char *str, char **array, char sep)
{
	int x = 0;
	int j = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] != sep)
			x++;
		if ((str[i] != sep && str[i + 1] == sep)
		|| (str[i] != sep && str[i + 1] == 0)) {
			array[j] = malloc(sizeof(char) * (x + 1));
			x = 0;
			j++;
		}
		if (j > 0 && !array[j - 1])
			return (84);
	}
	return (0);
}

void copy_my_words(char *str, char **array, char sep)
{
	int i = 0;
	int x = 0;

	for (int j = 0; str[j]; j++) {
		if (str[j] != sep) {
			array[i][x] = str[j];
			x++;
		}
		if ((str[j] != sep && str[j + 1] == sep)
		|| (str[j] != sep && str[j + 1] == 0)) {
			array[i][x] = 0;
			i++;
			x = 0;
		}
	}
}

char **my_str_to_word_array(char *str, char sep)
{
	int nb_words = count_words(str, sep);
	char **array = malloc(sizeof(char *) * (nb_words + 1));

	if (!array)
		return (NULL);
	my_replace_char(str, '\t', ' ');
	for (int i = 0; i < nb_words + 1; i++)
		array[i] = NULL;
	if (alloc_my_words(str, array, sep) != 0)
		return (NULL);
	copy_my_words(str, array, sep);
	return (array);
}
