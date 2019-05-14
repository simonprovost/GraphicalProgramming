/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** (enter)
*/

int my_find_char(char seeked, char *inside)
{
	for (int i = 0; inside[i]; i++) {
		if (inside[i] == seeked)
			return (0);
	}
	return (1);
}
