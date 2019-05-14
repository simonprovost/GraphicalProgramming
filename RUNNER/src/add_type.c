/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void add_type(game_object_t **my_object)
{
	my_object[0]->type = BACKGROUND;
	my_object[1]->type = MIDDLE;
	my_object[2]->type = FRONT;
	my_object[3]->type = RUN;
	my_object[4]->type = TREE;
}
