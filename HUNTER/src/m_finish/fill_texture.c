/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void fill_texture(f_tt_t *tt)
{
	tt->texture_yes = sfTexture_createFromFile("resources/yes.png", NULL);
	tt->texture_no = sfTexture_createFromFile("resources/no.png", NULL);
	tt->my_background = sfTexture_createFromFile("resources/gbg.png", NULL);
}
