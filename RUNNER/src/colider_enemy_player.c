/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

sfBool  collider_player_enemy(public_class_t *all, int i)
{
	sfVector2f get_pos_player = sfSprite_getPosition(
		all->my_pers[0]->my_sprite);
	sfVector2f get_pos_enemy = sfSprite_getPosition(
		all->enemy[i]->my_sprite);
	if ((get_pos_player.x + 120 <= get_pos_enemy.x - 5)
	    && (get_pos_player.x + 120 >= get_pos_enemy.x - 100) &&
	    (get_pos_player.y <= get_pos_enemy.y + 50) &&
	    (get_pos_player.y >= get_pos_enemy.y - 190)) {
		all->var->notify = 1;
		all->player->life -= 1;
		sfMusic_play(all->player->obstacle);
		return (sfTrue);
	} else
		return (sfFalse);
}

void move_enemy(public_class_t *all)
{
	for (int i = 0; i < all->var->number_of_enemy; i++) {
		if (all->enemy[i]->pos.x != 0) {
			all->enemy[i]->pos.x -= all->var->move_enemy;
		} else
			all->enemy[i]->pos.x -= 5;
		sfSprite_setPosition(all->enemy[i]->my_sprite,
				     all->enemy[i]->pos);
	}
}

void check_if_win(public_class_t *all)
{
	if (all->var->level == 4)
		exit (0);
}

void check_if_loose(public_class_t *all)
{
	if (all->player->life <= 0)
		exit (0);
}