/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** free_system.c created: 01/05/18
*/

#include <rpg.h>

void free_particle_sys(particle_sys_t *sys)
{
	for (int i = 0; i < sys->particle_nbr; i++) {
		sfSprite_destroy(sys->sprite_arr[i]);
	}
	free(sys->sprite_arr);
	sys->sprite_arr = NULL;
}

void remove_particle_sys(particle_sys_t *sys)
{
	remove_particle_sys_by_id(sys->sys_id);
}

void remove_end(node_t *last_node, node_t *act_node,
		llist_t *particle_sys_list)
{
	if (last_node)
		last_node->next = act_node->next;
	else
		particle_sys_list->first = act_node->next;
	free_particle_sys(act_node->value);
}