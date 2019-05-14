/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void init_text_over(sfFont *font, f_t_t *t)
{
	set_string_font(t, font);
	sfText_setCharacterSize(t->text, 40);
	sfText_setCharacterSize(t->remains, 19);
	sfText_setCharacterSize(t->remains_count, 19);
	sfText_setCharacterSize(t->count_kill, 20);
	sfText_setCharacterSize(t->stock_result, 20);
	sfText_setCharacterSize(t->time_since_begin, 19);
	sfText_setCharacterSize(t->my_time, 19);
	sfText_setCharacterSize(t->info, 20);
	sfText_setCharacterSize(t->info_2, 19);
	sfText_setPosition(t->text, (sfVector2f){280, 40});
	sfText_setPosition(t->info, (sfVector2f){500, 170});
	sfText_setPosition(t->info_2, (sfVector2f){500, 200});
	sfText_setPosition(t->count_kill, (sfVector2f){5, 130});
	sfText_setPosition(t->stock_result, (sfVector2f){230, 130});
	sfText_setPosition(t->my_time, (sfVector2f){10, 160});
	sfText_setPosition(t->time_since_begin, (sfVector2f){175, 160});
	sfText_setPosition(t->remains, (sfVector2f){10, 190});
	sfText_setPosition(t->remains_count, (sfVector2f){230, 190});
}
