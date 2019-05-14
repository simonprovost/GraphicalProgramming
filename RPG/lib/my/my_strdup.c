/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

char *my_strdup(char *str)
{
	int len = my_strlen(str);
	char *returned = malloc(sizeof(char) * (len + 1));

	if (!returned || !str)
		return (NULL);
	for (int i = 0; i < len; i++)
		returned[i] = str[i];
	returned[len] = 0;
	return (returned);
}
