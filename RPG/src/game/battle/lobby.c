/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_battle
*/

#include "rpg.h"

int battle_events(window_t *window, game_t *game)
{
	if (window->event.type == sfEvtClosed)
		sfRenderWindow_close(window->window);
	if (window->event.type == sfEvtMouseButtonReleased)
		CLICK_RELEASED = sfTrue;
	return (select_ennemy(window, game));
}

int check_step_to_battle(game_t *game)
{
	if (AREA_ENCOUNTER == sfFalse)
		return (0);
	if (STEP_TO_BATTLE <= 0) {
		STEP_TO_BATTLE = (rand() % 20 + 11) * 2;
		return (start_battle(game));
	}
	return (0);
}

int display_special(window_t *window, game_t *game)
{
	int my_errno = 0;

	if (SPECIAL_HIT) {
		my_errno = display_special_hit_player(window, game, NULL);
		if (my_errno != 0)
			return (my_errno);
		my_errno = display_special_hit_enemy(window, game, NULL);
	} else
		my_errno = wait_for_enemy_attack(window, game, 0);
	if (my_errno != 0)
		return (my_errno);
	return (0);
}

int battle_lobby(window_t *window, game_t *game)
{
	int my_errno = 0;

	my_errno = check_run_away(game);
	if (my_errno != 0)
		return (my_errno);
	if (manage_hit_enemy(game, 0, 0) != 0
	|| manage_life(game) != 0
	|| display_characters(window, game) != 0)
		return (84);
	my_errno = display_special(window, game);
	if (my_errno)
		return (my_errno);
	if (!SPECIAL_HIT && window->clocker.seconds >= 3) {
		if (game->battle.win)
			return (battle_end_screen(game, "WIN"));
		else if (game->battle.lose)
			return (battle_end_screen(game, "LOSE"));
	}
	return (0);
}