/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** (enter)
*/

#include "../../include/my.h"

int my_str_isalphanum(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (!CHAR_IS_NUM(str[i]) && !(CHAR_IS_ALPHA(str[i])))
			return (1);
	}
	return (0);
}
