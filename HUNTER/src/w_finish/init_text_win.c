/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void init_text_win(sfFont *font, fw_t_t *t, fw_s_t *s, fw_tt_t *tt)
{
	set_string_font_win(font, t);
	sfText_setPosition(t->text, (sfVector2f){280, 40});
	sfText_setPosition(t->info, (sfVector2f){500, 170});
	sfText_setPosition(t->info_2, (sfVector2f){500, 200});
	sfText_setPosition(t->count_kill, (sfVector2f){5, 130});
	sfText_setPosition(t->stock_result, (sfVector2f){230, 130});
	sfText_setPosition(t->my_time, (sfVector2f){10, 160});
	sfText_setPosition(t->time_since_begin, (sfVector2f){175, 160});
	sfSprite_setTexture(s->sprite_yes, tt->texture_yes, sfTrue);
	sfSprite_setTexture(s->sprite_no, tt->texture_no, sfTrue);
	sfSprite_setScale(s->sprite_no, (sfVector2f){0.5, 0.5});
	sfSprite_setScale(s->sprite_yes, (sfVector2f){0.5, 0.5});
	sfSprite_setPosition(s->sprite_no, (sfVector2f){500, 300});
	sfSprite_setPosition(s->sprite_yes, (sfVector2f){500, 300});
	sfSprite_setTexture(s->background, tt->my_background, sfTrue);
	sfSprite_setScale(s->background, (sfVector2f){0.42, 0.56});
}
