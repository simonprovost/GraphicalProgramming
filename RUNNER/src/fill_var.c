/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void fill_var_one(b_t *var)
{
	var->seconds = 0;
	var->width_image = 0;
	var->heigh_image = 0;
	var->offset_player = 0;
	var->speed_parralax = 1;
	var->number_of_enemy = 0;
	var->enemy_begin = 0;
	var->notify = 0;
	var->check_notify = 0;
	var->level = 0;
	var->font = sfFont_createFromFile("ressources/Relaway.ttf");
	var->count_metter = sfText_create();
	sfText_setFont(var->count_metter, var->font);
	sfText_setString(var->count_metter, "NULL");
	sfText_setCharacterSize(var->count_metter, 90);
	sfText_setPosition(var->count_metter, (sfVector2f){500, 670});
	var->tmp = 0;
}

void fill_var_two(b_t *var)
{
	char *path = "ressources/level_texture.png";

	var->level_show = sfText_create();
	sfText_setFont(var->level_show, var->font);
	sfText_setString(var->level_show, "NULL");
	sfText_setCharacterSize(var->level_show, 45);
	sfText_setPosition(var->level_show, (sfVector2f){109, 680});
	var->show_level = sfSprite_create();
	var->level_texture = sfTexture_createFromFile(path,
						      NULL);
	sfSprite_setTexture(var->show_level, var->level_texture, sfTrue);
	sfSprite_setPosition(var->show_level, (sfVector2f){20, 620});
	sfSprite_setScale(var->show_level, (sfVector2f){0.4, 0.4});
}

void fill_var_three(b_t *var)
{
	var->line = sfSprite_create();
	var->line_texture = sfTexture_createFromFile("ressources/line.png",
						     NULL);
	sfSprite_setTexture(var->line, var->line_texture, sfTrue);
	sfSprite_setPosition(var->line, (sfVector2f){300, 630});
	sfSprite_setScale(var->line, (sfVector2f){0.2, 0.2});
	var->line_right = sfSprite_create();
	sfSprite_setTexture(var->line_right, var->line_texture, sfTrue);
	sfSprite_setPosition(var->line_right, (sfVector2f){840, 635});
	sfSprite_setScale(var->line_right, (sfVector2f){0.2, 0.2});
}

void fill_var(b_t *var)
{
	char *path = "ressources/pause_pause.png";

	fill_var_one(var);
	fill_var_two(var);
	fill_var_three(var);
	var->pause_game = sfSprite_create();
	var->pause_texture = sfTexture_createFromFile("ressources/pause.png",
						      NULL);
	var->pause_in_game = sfTexture_createFromFile(path,
						      NULL);
	sfSprite_setTexture(var->pause_game, var->pause_texture, sfTrue);
	sfSprite_setPosition(var->pause_game, (sfVector2f){1100, 20});
	sfSprite_setScale(var->pause_game, (sfVector2f){0.2, 0.2});
	var->move_enemy = 10;
}