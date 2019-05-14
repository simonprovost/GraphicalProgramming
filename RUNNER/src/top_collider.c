/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

char *map(public_class_t *all)
{
	char *final = NULL;
	char *map_1 = "map_1";
	char *map_2 = "map_2";
	char *map_3 = "map_3";
	char *map_4 = "map_4";

	all->var->level == 1 ? final = map_1 : 0;
	all->var->level == 2 ? final = map_2 : 0;
	all->var->level == 3 ? final = map_3 : 0;
	all->var->level == 4 ? final = map_4 : 0;
	return (final);
}
void collider_level(public_class_t *all)
{
	if (all->my_pers[0]->my_pos.x >= 1062) {
		all->var->level += 1;
		all->var->speed_parralax += 1;
		all->my_pers[0]->my_pos.x = 8;
		all->player->speed_reactor_up += 2;
		all->player->speed_reactor_down += 2;
		all->var->check_mission = 0;
		create_player(all);
		init_rect(all);
		all->var->map = map_read(map(all));
		all->var->size = my_strlen(all->var->map);
		manage_map(all);
		fill_enemy(all);
	}
}