/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

char *my_cleanstr(char *str, char to_clean)
{
	unsigned int len = 0;
	char *cleaned = NULL;
	unsigned int j = 0;

	for (unsigned int i = 0; str[i]; i++)
		if (str[i] != to_clean)
			len++;
	if (len == my_strlen(str))
		return (my_strdup(str));
	cleaned = malloc(sizeof(char) * (len + 1));
	cleaned[len] = 0;
	if (!cleaned)
		return (NULL);
	for (unsigned int i = 0; str[i]; i++) {
		if (str[i] != to_clean) {
			cleaned[j] = str[i];
			j++;
		}
	}
	return (cleaned);
}
