/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void draw_object_enemy(public_class_t *all)
{
	int j = 0;

	for (; j < 5; j++)
		sfRenderWindow_drawSprite(all->csfml_object->window,
					  all->my_object[j]->my_sprite, NULL);
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->my_pers[0]->my_sprite, NULL);
	for (; all->var->enemy_begin < all->var->number_of_enemy ;
	       all->var->enemy_begin += 1)
		sfRenderWindow_drawSprite(all->csfml_object->window,
					  all->enemy[all->var->enemy_begin]->
						  my_sprite,
					  NULL);
}

void draw_sprite(public_class_t *all)
{
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->csfml_object->blood_obstacle, NULL);
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->csfml_object->mission, NULL);
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->var->show_level, NULL);
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->player->life_sprite, NULL);
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->var->line, NULL);
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->var->line_right, NULL);
	sfRenderWindow_drawSprite(all->csfml_object->window,
				  all->var->pause_game, NULL);
}

void draw_text(public_class_t *all)
{
	sfRenderWindow_drawText(all->csfml_object->window,
				all->var->count_metter, NULL);
	sfRenderWindow_drawText(all->csfml_object->window,
				all->var->level_show, NULL);
	sfRenderWindow_drawText(all->csfml_object->window,
				all->player->life_player, NULL);
	sfRenderWindow_drawText(all->csfml_object->window,
				all->csfml_object->time_since_begin, NULL);
	sfRenderWindow_drawText(all->csfml_object->window,
				all->csfml_object->show_second, NULL);
}
