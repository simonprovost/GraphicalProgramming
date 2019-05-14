/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** player animation handling
*/

#include <rpg.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio.h>

void set_next_rect_b(game_t *game)
{
	int mult = game->movement.anim_mult;

	PLAYER.character->obj_rect.rect.left +=
		(mult * PLAYER.character->obj_rect.rect_offset.x);
	PLAYER.character->obj_rect.rect.top +=
		(mult * PLAYER.character->obj_rect.rect_offset.y);
}

void set_next_rect(game_t *game)
{
	int act_x;
	int act_y;
	int mult = game->movement.anim_mult;

	set_next_rect_b(game);
	act_y = PLAYER.character->obj_rect.rect.top;
	act_x = PLAYER.character->obj_rect.rect.left;
	if (act_x >= PLAYER.character->obj_rect.rect_max.x ||
	act_y > PLAYER.character->obj_rect.rect_max.y ||
	act_x <= PLAYER.character->obj_rect.rect_start.x ||
	act_y < PLAYER.character->obj_rect.rect_start.y) {
		game->movement.anim_mult = -1 * mult;
	}
	sfRectangleShape_setTextureRect(
		game->player.character->obj,
		game->player.character->obj_rect.rect);
}

void set_anim_side(game_t *game)
{
	PLAYER.character->obj_rect.rect.top =
		PLAYER.character->obj_rect.rect_start.y;
	sfRectangleShape_setTextureRect(
		game->player.character->obj,
		game->player.character->obj_rect.rect);
}

void set_waiting_player_rect(game_t *game)
{
	reset_feet_particles(game);
	PLAYER.character->obj_rect.rect.top =
		PLAYER.character->obj_rect.rect_start.y;
	PLAYER.character->obj_rect.rect.left = 50;
	sfRectangleShape_setTextureRect(
		game->player.character->obj,
		game->player.character->obj_rect.rect);
}

int anim_player(game_t *game)
{
	update_moving_state(game);
	if (!(game->player.character) ||
	!game->player.character->obj_rect.animated)
		return (0);
	get_time(&game->movement.timer);
	if (game->movement.timer.seconds > 0.1) {
		if (AREA_ENCOUNTER == sfTrue)
			STEP_TO_BATTLE--;
		make_sound("FOOTSTEP_SOUND", game);
		sfClock_restart(game->movement.timer.clock);
		set_next_rect(game);
	}
	return (0);
}