/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void next_pause_game(public_class_t *all, int *game_paused)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		*game_paused = 0;
		sfSprite_setTexture(all->var->pause_game,
				    all->var->pause_texture,
				    sfTrue);
		sfSprite_setPosition(all->var->pause_game, (
			sfVector2f){1100, 20});
		sfSprite_setScale(all->var->pause_game, (
			sfVector2f){0.2, 0.2});
	} else {
		sfSprite_setPosition(all->var->pause_game,
				     (sfVector2f){550, 300});
		sfSprite_setScale(all->var->pause_game,
				  (sfVector2f){0.6, 0.6});
		sfSprite_setTexture(all->var->pause_game,
				    all->var->pause_in_game, sfTrue);
		draw_display(all);
		sfRenderWindow_waitEvent(all->csfml_object->window,
					 &all->csfml_object->event);
	}
}

void pause_game(public_class_t *all)
{
	int game_paused = 0;

	if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
		game_paused = 1;
		while (game_paused == 1)
			next_pause_game(all, &game_paused);
	}
}

void manage_player(public_class_t *all)
{
	int check = 1;

	player_glide(all, check);
	player_fly_up(all, check);
	player_fly_down(all, check);
	player_walk(all, check);
	pause_game(all);
}