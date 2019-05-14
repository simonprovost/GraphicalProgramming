/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void fill_texture_win(fw_tt_t *tt)
{
	char *assets = "resources/background_win.png";

	tt->my_background = sfTexture_createFromFile(assets, NULL);
	tt->texture_yes = sfTexture_createFromFile("resources/yes.png", NULL);
	tt->texture_no = sfTexture_createFromFile("resources/no.png", NULL);

}
