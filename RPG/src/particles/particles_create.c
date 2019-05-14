/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** particles_create.c created: 30/04/18
*/

#include <rpg.h>
#include <SFML/Audio.h>

bool default_particle_cond(sfSprite *sprite, game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(sprite);

	(void) game;
	if (get_rnd(1, 100) == 50)
		return (true);
	if (pos.y > 600 || pos.x > 800 || pos.x < 0)
		return (true);
	return (false);
}

void display_particle_sys(window_t *window, particle_sys_t *sys)
{
	if (!sys->sprite_arr || !sys->activated)
		return;
	for (int i = 0; i < sys->spawned_particles_nbr; i++) {
		sfRenderWindow_drawSprite(window->window, sys->sprite_arr[i]
			, NULL);
	}
}

void set_init_particle_pos(particle_sys_t *sys, sfSprite *sprite)
{
	sfSprite_setPosition(sprite, get_particles_spawn_pos(sys));
}

void update_particle_sys(particle_sys_t *sys, game_t *game)
{
	if (!sys->sprite_arr || !sys->activated)
		return;
	for (int i = 0; i < sys->spawned_particles_nbr; i++) {
		sfSprite_move(sys->sprite_arr[i], sys->force);
		if (sys->gravity)
			sfSprite_move(sys->sprite_arr[i], V2F(0, 2));
		if (sys->condition(sys->sprite_arr[i], game))
			set_init_particle_pos(sys, sys->sprite_arr[i]);
	}
}