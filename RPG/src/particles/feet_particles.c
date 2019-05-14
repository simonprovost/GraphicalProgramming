/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** feet_particles.c created: 01/05/18
*/

#include <rpg.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio.h>

bool feet_particles_cond(sfSprite *particle, game_t *game)
{
	sfVector2f pos = sfSprite_getPosition(particle);
	sfIntRect spawner = game->particles->feet_deject->spawn_zone;

	if (pos.x > spawner.left + 40)
		return (true);
	if (pos.x < spawner.left - 40)
		return (true);
	if (pos.y < spawner.top - 40)
		return (true);
	if (pos.y > spawner.top + 40)
		return (true);
	return (false);
}

particle_sys_t *init_foot_particles(game_t *game)
{
	sfIntRect spawn = (sfIntRect) {.top = 0, .left = 0,
		.height = 10, .width = 10};
	particle_sys_t *sys = create_particle_sys(spawn,
						"GROUND_DROP", 25, game);

	sys->spawn_density = 1;
	sys->force = V2F(1, 0);
	sys->condition = feet_particles_cond;
	return (sys);
}

void reset_feet_particles(game_t *game)
{
	particle_sys_t *sys = PARTICLES->feet_deject;
	sfSprite **sprites;
	sfVector2f pos;

	if (!sys)
		return;
	sprites = sys->sprite_arr;
	if (!sprites)
		return;
	for (int i = 0; i < sys->particle_nbr; i++) {
		pos = get_particles_spawn_pos(sys);
		sfSprite_setPosition(sys->sprite_arr[i], pos);
	}
}

void update_feet_particles(game_t *game)
{
	particle_sys_t *sys = game->particles->feet_deject;
	sfVector2f pos;

	if (my_strcmp(CURRENT_BUCKET->key, "GAME") != 0)
		return;
	pos = sfRectangleShape_getPosition(PLAYER_CHARACTER->obj);
	sys->spawn_zone.left = (int) pos.x + 20;
	sys->spawn_zone.top = (int) pos.y + 80;
	if (PLAYER_CHARACTER->obj_rect.rect_start.y == 300)
		sys->force = V2F(get_rnd(-1, 1), 1);
	else if (PLAYER_CHARACTER->obj_rect.rect_start.y == 200)
		sys->force = V2F(1, get_rnd(-1, 1));
	else if (PLAYER_CHARACTER->obj_rect.rect_start.y == 100)
		sys->force = V2F(1, get_rnd(-1, 1));
	sys->activated = (bool) PLAYER_CHARACTER->obj_rect.animated;
	if (PLAYER_CHARACTER->obj_rect.rect_start.y == 0)
		sys->activated = false;
}