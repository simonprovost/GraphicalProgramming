/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void set_string_font(f_t_t *t, sfFont *font)
{
	sfText_setString(t->text, "Play again ?");
	sfText_setString(t->info, "Boy Emoji --> Play gain !");
	sfText_setString(t->info_2, "Girl Emoji --> Exit Game !");
	sfText_setString(t->count_kill, "Ammunition used :");
	sfText_setString(t->my_time, "Game time (s) :");
	sfText_setString(t->remains, "duck(s) remains : ");
	sfText_setFont(t->remains, font);
	sfText_setFont(t->remains_count, font);
	sfText_setFont(t->time_since_begin, font);
	sfText_setFont(t->count_kill, font);
	sfText_setFont(t->my_time, font);
	sfText_setFont(t->stock_result, font);
	sfText_setFont(t->text, font);
	sfText_setFont(t->info, font);
	sfText_setFont(t->info_2, font);
}
