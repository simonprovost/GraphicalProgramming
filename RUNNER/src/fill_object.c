/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void fill_object(game_object_t **my_object)
{
	my_object[0] = create_object("ressources/background.png",
				     (sfVector2f){0,0}, RECT_PARR);
	my_object[1] = create_object("ressources/sky.png",
				     (sfVector2f){-10, -460}, RECT_PARR);
	my_object[2] = create_object("ressources/moutain.png",
				     (sfVector2f){-10, -450}, RECT_PARR);
	my_object[3] = create_object("ressources/run.png",
				     (sfVector2f){-10, -170}, RECT_PARR);
	my_object[4] = create_object("ressources/tree.png",
				     (sfVector2f){-10, -295}, RECT_PARR);
}