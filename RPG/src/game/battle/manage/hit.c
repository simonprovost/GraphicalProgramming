/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

int re_init_at_initial(sfText *hit, int enemy)
{
	if (!my_strcmp(sfText_getString(hit), "")
	|| sfText_getPosition(hit).y <= -10) {
		sfText_setCharacterSize(hit, 40);
		sfText_setColor(hit, (sfColor){200, 0, 0, 255});
		sfText_setPosition(hit,
		V2F(605 + (25 * (enemy - 1)), 205 + (50 * (enemy - 1))));
		if (enemy < 0)
			sfText_setPosition(hit, V2F(105, 225));
		sfText_setString(hit, "");
		sfText_setRotation(hit, 0);
		return (1);
	}
	return (0);
}

int update_text_hit(sfText *hit, int check_hit, int enemy, int damages)
{
	if (sfText_getPosition(hit).y > -50 && (enemy != 0 || check_hit == 1)) {
		sfText_setString(hit, int_to_str(damages));
		sfText_setColor(hit, (sfColor){200, 0, 0, 255});
		sfText_move(hit, (sfVector2f){0, -5});
		sfText_rotate(hit, -0.5);
		return (1);
	}
	return (0);
}

int manage_hit_enemy(game_t *game, int enemy, int damages)
{
	scene_t *battle_game = hm_get(SCENES, "BATTLE");
	sfText *hit = NULL;
	static int check_hit;
	static int damages_save = 0;

	if (!battle_game || !game || !battle_game->texts)
		return (84);
	hit = hm_get(battle_game->texts, "HIT");
	if (!hit)
		return (84);
	if (re_init_at_initial(hit, enemy) == 1) {
		check_hit = 0;
		if (!enemy)
			return (0);
	}
	if (!check_hit)
		damages_save = damages;
	if (update_text_hit(hit, check_hit, enemy, damages_save) == 1)
		check_hit = 1;
	return (0);
}