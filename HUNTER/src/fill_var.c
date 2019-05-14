/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void fill_small_var(b_t *var)
{
	var->offset = 0;
	var->max_value = 330;
	var->a = 0.0;
	var->b = 0.0;
	var->seconds = 0;
	var->seconds_s_z = 0;
	var->check_duck = 0;
	var->stock_ball = 5;
	var->click = 0;
	var->variant = 0.1;
	var->check_begin = 0;

}
void fill_var(b_t *var)
{
	fill_small_var(var);
	var->font = sfFont_createFromFile("resources/my_font.ttf");
	var->ammmount_ball = sfText_create();
	var->duck = sfMusic_createFromFile("resources/duck_sample.ogg");
	var->wings = sfMusic_createFromFile("resources/wings.ogg");
	var->music = sfMusic_createFromFile("resources/duck_backg.ogg");
	var->finish = sfMusic_createFromFile("resources/game_over.ogg");
	var->gun = sfMusic_createFromFile("resources/gun.ogg");
	sfText_setString(var->ammmount_ball, "0");
	sfText_setFont(var->ammmount_ball, var->font);
	sfText_setPosition(var->ammmount_ball, (sfVector2f){50, 555});
	sfText_setCharacterSize(var->ammmount_ball, 30);
	var->nb_click = sfText_create();
	sfText_setString(var->nb_click, "0");
	sfText_setFont(var->nb_click, var->font);
	sfText_setPosition(var->nb_click, (sfVector2f){690, 550});
}
