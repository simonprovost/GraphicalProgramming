/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void set_string_font_win(sfFont *font, fw_t_t *t)
{
	sfText_setString(t->text, "Play again ?");
	sfText_setString(t->info, "Boy Emoji --> Play gain !");
	sfText_setString(t->info_2, "Girl Emoji --> Exit Game !");
	sfText_setString(t->count_kill, "Ammunition used :");
	sfText_setString(t->my_time, "Game time (s) :");
	sfText_setFont(t->time_since_begin, font);
	sfText_setFont(t->count_kill, font);
	sfText_setFont(t->my_time, font);
	sfText_setFont(t->stock_result, font);
	sfText_setFont(t->text, font);
	sfText_setFont(t->info, font);
	sfText_setFont(t->info_2, font);
	sfText_setCharacterSize(t->text, 40);
	sfText_setCharacterSize(t->count_kill, 20);
	sfText_setCharacterSize(t->stock_result, 20);
	sfText_setCharacterSize(t->time_since_begin, 19);
	sfText_setCharacterSize(t->my_time, 19);
	sfText_setCharacterSize(t->info, 20);
	sfText_setCharacterSize(t->info_2, 19);
}
