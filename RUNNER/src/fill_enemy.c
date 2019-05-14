/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void fill_enemy(public_class_t *all)
{
	sfVector2f my_pos;
	my_pos.x = 0;
	my_pos.y = 0;

	all->enemy = malloc(sizeof(my_obstacle_t *) *
			    all->var->number_of_enemy);
	for (int i = 0; i < all->var->number_of_enemy; i++) {
		if (i != 0)
			my_pos.x = all->var->stock_enemy[i][0] * 10;
		else
			my_pos.x = all->var->stock_enemy[i][0] * 10;
		if (i != 0)
			my_pos.y = (all->var->stock_enemy[i][1] * 100);
		else
			my_pos.y = (all->var->stock_enemy[i][1] * 100);
		all->enemy[i] = create_enemy("ressources/obstacle_1.png.png",
					     my_pos,
					     (sfIntRect) {0, 0, 877, 720},
					     (sfVector2f) {0.85, 0.45});
	}
}
