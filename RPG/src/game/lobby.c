/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include <SFML/Window/Event.h>
#include "rpg.h"

int on_key_pressed(game_t *game)
{
	game->movement.is_moving = sfFalse;
	if (sfKeyboard_isKeyPressed(KEY_UP) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_UP) == sfTrue)
		move_player(UP, game);
	if (sfKeyboard_isKeyPressed(KEY_DOWN) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_DOWN) == sfTrue)
		move_player(DOWN, game);
	if (sfKeyboard_isKeyPressed(KEY_LEFT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_LEFT) == sfTrue)
		move_player(LEFT, game);
	if (sfKeyboard_isKeyPressed(KEY_RIGHT) == sfTrue
	|| sfKeyboard_isKeyPressed(ARROW_KEY_RIGHT) == sfTrue)
		move_player(RIGHT, game);
	return (0);
}

int process_action_key(game_t *game)
{
	static sfBool open = sfTrue;
	int my_errno = 0;

	if (open == sfTrue) {
		if (process_npc_dialogue(game) != 0)
			return (84);
		make_sound("DIALOGUE_SOUND", game);
		open = sfFalse;
	} else {
		open = sfTrue;
		my_errno = process_npc_action(game);
		if (my_errno != 0)
			return (my_errno);
	}
	if (button_display_hide_scene("DIALOGUE_HUD", NULL,
	game, "GAME") == 84)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "GAME");
	return (0);
}

int press_action_key(game_t *game)
{
	static sfBool pass = sfTrue;
	int my_errno = 0;

	if (pass == sfTrue) {
		pass = sfFalse;
		my_errno = process_action_key(game);
		if (my_errno != 0)
			return (my_errno);
	} else
		pass = sfTrue;
	return (0);
}

int game_events(window_t *window, game_t *game)
{
	int my_errno = 0;

	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->window);
	if (window->event.type == sfEvtMouseButtonReleased)
		CLICK_RELEASED = sfTrue;
	if (my_strcmp(CURRENT_BUCKET->key, "GAME") != 0)
		return (0);
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
		my_errno = press_action_key(game);
		if (my_errno != 0)
			return (my_errno);
	}
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		pause_game(window, game);
	return (0);
}

int game_lobby(window_t *window, game_t *game)
{
	int my_errno = check_step_to_battle(game);

	if (my_errno != 0)
		return (my_errno);
	if (my_strcmp(CURRENT_BUCKET->key, "GAME") == 0) {
		on_key_pressed(game);
		if (manage_hud_opacity(game) != 0)
			return (84);
	}
	update_feet_particles(game);
	display_particles(window, game);
	update_day_night_cycle(game);
	if (manage_life(game) != 0
	|| change_area_hud(game) != 0
	|| anim_player(game) != 0)
		return (84);
	smooth_move_player(game);
	return (0);
}