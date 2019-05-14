/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int check_invalid_key_word(char *last_word_used, char **type, char **infos,
	int error_no)
{
	if (error_no != 0)
		return (84);
	if (last_word_used == NULL) {
		my_printf("WARNING: '%s' ISN'T A VALID KEYWORD !\n",
		type[0]);
		return (84);
	}
	my_destroy_tab(type);
	my_destroy_tab(infos);
	return (0);
}

int check_invalid_file(int fd, char *filename)
{
	if (fd == -1) {
		my_printf("WARNING: CAN'T FIND '%s' FILE !\n", filename);
		return (84);
	}
	return (0);
}

int check_invalid_zone_coords(char *name, my_w_t *window)
{
	if (ZONE_COOR_X < 0 || ZONE_COOR_X >= ZONE_TAB_X
		|| ZONE_COOR_Y < 0 || ZONE_COOR_Y >= ZONE_TAB_Y) {
		my_printf("WARNING: INVALID ZONE '%s' COORDS", name);
		my_printf(". HAVE TO BE 0 < X < %d AND 0 < Y < %d !\n",
		ZONE_TAB_X, ZONE_TAB_Y);
		return (84);
	}
	return (0);
}

int check_invalid_zone_file(char *asked_zone, char *actual_zone,
	char *filepath)
{
	if (my_fastcmp(asked_zone, actual_zone) != 0) {
		my_printf("WARNING: YOU PUT THE ZONE '%s' IN THE FILE '%s'",
		asked_zone, filepath);
		my_printf(" WHICH IS DEDICATED TO THE INITIALISATION OF THE ");
		my_printf("ZONE '%s' !\n", actual_zone);
		return (84);
	}
	return (0);
}
