/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

int main_menu(window_t *window, game_t *game)
{
	static sfBool updated = sfFalse;

	if (!window || !game)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, HOME);
	if (check_unexisting_scene(CURRENT_BUCKET, HOME) != 0)
		return (84);
	if (clean_displayed_scenes_and_add_back(game, HOME) != 0)
		return (84);
	if (PLAYER_NAME && updated == sfFalse) {
		updated = sfTrue;
		if (update_button("NEW_GAME", "CONTINUE",
		CURRENT_BUCKET->value, game) != 0)
			return (84);
	}
	(void)window;
	return (1);
}
