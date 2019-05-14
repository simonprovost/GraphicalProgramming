/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void usage_func(char **argv, int argc)
{
	if (argv[1] != NULL && argc != 999) {
		if (argv[1][0] == '-' && argv[1][1] == 'h') {
			my_printf("Usage : EPI_DUCK.\n");
			my_printf("---------------------------------------\n");
			my_printf("You need to enter ./my_hunter -->");
			my_printf(" and choice your level.. Good LUCK.\n");
			my_printf("---------------------------------------\n");
			exit (0);
		} else {
			my_printf("---------------EPI_DUCK_ERROR----------\n");
			my_printf("# add -h or nothing to play the game #\n");
			my_printf("---------------EPI_DUCK_ERROR----------\n");
			exit (84);
		}
	}
}
