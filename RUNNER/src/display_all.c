/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void check_life_player(public_class_t *all)
{
	if (all->player->life == 4)
		sfSprite_setTextureRect(all->player->life_sprite, RECT_LIFE);
	else if (all->player->life == 2)
		sfSprite_setTextureRect(all->player->life_sprite, RECT_LIFE_TW);
}

void set_string(public_class_t *all)
{
	char metter[20];
	char level[20];
	char life[20];
	char time_calcul[20];

	my_itoa((int) all->my_pers[0]->my_pos.x, metter);
	sfText_setString(all->var->count_metter, metter);
	my_itoa(all->var->level, level);
	sfText_setString(all->var->level_show, level);
	my_itoa(all->player->life, life);
	sfText_setString(all->player->life_player, life);
	my_itoa((int) all->csfml_object->seconds_s_z, time_calcul);
	sfText_setString(all->csfml_object->time_since_begin, time_calcul);
}

void draw_display(public_class_t *all)
{
	int tmp = all->var->enemy_begin;

	check_life_player(all);
	set_string(all);
	draw_object_enemy(all);
	all->var->enemy_begin = tmp;
	if (all->var->check_notify == 1)
		notify_obstacles(all);
	notify_mission(all);
	draw_sprite(all);
	draw_text(all);
	sfRenderWindow_display(all->csfml_object->window);
}