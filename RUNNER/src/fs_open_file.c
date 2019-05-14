/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

int fs_open_file(char const *filepath)
{
	int fd = open(filepath, O_RDONLY);

	if (fd == -1)
		exit (84);
	return (fd);
}