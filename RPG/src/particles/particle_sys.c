/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** particle_sys.c created: 01/05/18
*/

#include <rpg.h>

static llist_t *particle_sys_list = NULL;

static void add_sys_to_list(particle_sys_t *sys)
{
	if (!particle_sys_list) {
		particle_sys_list = malloc(sizeof(llist_t));
		particle_sys_list->first = node_create(sys->sys_name, sys);
		particle_sys_list->size = 1;
		return;
	}
	add_to_llist(sys->sys_name, sys, particle_sys_list);
}

static void particle_sys_init(particle_sys_t *sys)
{
	static int id = 0;

	sys->sys_id = id;
	id++;
	sys->spawn_density = 3;
	sys->spawned_particles_nbr = 0;
	sys->sprite_arr[sys->particle_nbr] = NULL;
	sys->condition = default_particle_cond;
	sys->force = V2F(1, 0);
	sys->gravity = false;
	sys->activated = true;
	add_sys_to_list(sys);
}

particle_sys_t *create_particle_sys(sfIntRect spawn, char *tex_name,
				int particle_nbr, game_t *game)
{
	particle_sys_t *ret = malloc(sizeof(*ret));
	texture_t *tex = hm_get(TEXTURES_LIB, tex_name);

	if (!ret || !tex)
		return (NULL);
	ret->texture = tex->texture;
	ret->spawn_zone = spawn;
	ret->particle_nbr = particle_nbr;
	ret->sprite_arr = malloc(sizeof(sfSprite *) * (particle_nbr + 1));
	if (!ret->sprite_arr)
		return (NULL);
	for (int i = 0; i < ret->particle_nbr; i++) {
		ret->sprite_arr[i] = sfSprite_create();
		if (!ret->sprite_arr[i])
			return (NULL);
		sfSprite_setTexture(ret->sprite_arr[i], ret->texture, sfFalse);
	}
	ret->sys_name = tex_name;
	particle_sys_init(ret);
	return (ret);
}

void display_particles(window_t *window, game_t *game)
{
	node_t *act_node;
	particle_sys_t *act_sys;

	if (my_strcmp(CURRENT_BUCKET->key, "GAME") != 0)
		return;
	if (!particle_sys_list)
		return;
	act_node = particle_sys_list->first;
	for (; act_node; act_node = act_node->next) {
		act_sys = act_node->value;
		init_particle_position(act_sys);
		update_particle_sys(act_sys, game);
		display_particle_sys(window, act_sys);
	}
	rain(game, game->window);
}

void remove_particle_sys_by_id(int id)
{
	int idx = 0;
	node_t *act_node;
	node_t *last_node = NULL;
	particle_sys_t *act_sys;

	if (!particle_sys_list)
		return;
	act_node = particle_sys_list->first;
	for (; act_node; act_node = act_node->next) {
		act_sys = act_node->value;
		if (act_sys->sys_id == id)
			break;
		last_node = act_node;
		idx++;
	}
	if (!act_node)
		return;
	remove_end(last_node, act_node, particle_sys_list);
}