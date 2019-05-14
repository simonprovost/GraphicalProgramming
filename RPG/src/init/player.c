/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_stats_scene(char **desc, obj_data_t *data, game_t *game)
{
	scene_t *scene = hm_get(SCENES, STATS_GAME);
	obj_data_t special_data = {"SPECIAL_CHARAC", desc[2], sfFalse,
							(sfVector2f){316, 215}};
	sfText *name = hm_get(scene->texts, "CHARAC");
	sfText *lore = hm_get(scene->texts, "CHARAC_DESC");

	if (!scene || !name || !lore)
		return (84);
	if (add_obj_to_list(data, scene->objs, game) != 0)
		return (84);
	if (add_obj_to_list(&special_data, scene->objs, game) != 0)
		return (84);
	sfText_setString(name, desc[0]);
	sfText_setString(lore, desc[1]);
	update_stats(scene, game);
	return (0);
}

int select_varyan(window_t *window, game_t *game)
{
	obj_data_t charac_data = {"VARYAN", "WARRIOR_01", sfFalse,
	(sfVector2f){304, 55}};
	char *desc[3] = {"Varyan", "The Warrior", "STRENGHT_ICON"};

	PLAYER_NAME = "Varyan";
	PLAYER_CHARACTER = create_obj(&charac_data, game);
	GOLDS = 50;
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_STATS = (stat_t){200, 200, 10, 15, 0, 100, 1, "Strenght", 35};
	if (add_new_to_slot("COMMON_SWORD_00", &WEAPON_POS, &WEAPON, game) != 0)
		return (84);
	if (init_stats_scene(desc, &charac_data, game) != 0)
		return (84);
	place_player(game);
	if (load_my_zone(game) != 0)
		return (84);
	return (launch_game(window, game));
}

int select_jaina(window_t *window, game_t *game)
{
	obj_data_t charac_data = {"JAINA", "MAGE_01", sfFalse,
	(sfVector2f){304, 55}};
	char *desc[3] = {"Jaina", "The Mage", "WISDOM_ICON"};

	PLAYER_NAME = "Jaina";
	PLAYER_CHARACTER = create_obj(&charac_data, game);
	GOLDS = 50;
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_STATS = (stat_t){130, 130, 4, 20, 0, 100, 1, "Wisdom", 45};
	if (add_new_to_slot("COMMON_WAND_00", &WEAPON_POS, &WEAPON, game) != 0)
		return (84);
	if (init_stats_scene(desc, &charac_data, game) != 0)
		return (84);
	place_player(game);
	if (load_my_zone(game) != 0)
		return (84);
	return (launch_game(window, game));
}

int select_avelus(window_t *window, game_t *game)
{
	obj_data_t charac_data = {"AVELUS", "HUNTER_01", sfFalse,
	(sfVector2f){304, 55}};
	char *desc[3] = {"Avelus", "The Hunter", "AGILITY_ICON"};

	PLAYER_NAME = "Avelus";
	PLAYER_CHARACTER = create_obj(&charac_data, game);
	GOLDS = 50;
	if (!PLAYER_CHARACTER)
		return (84);
	PLAYER_STATS = (stat_t){150, 150, 5, 10, 0, 100, 1, "Agility", 50};
	if (add_new_to_slot("COMMON_BOW_00", &WEAPON_POS, &WEAPON, game) != 0)
		return (84);
	if (init_stats_scene(desc, &charac_data, game) != 0)
		return (84);
	place_player(game);
	if (load_my_zone(game) != 0)
		return (84);
	return (launch_game(window, game));
}

void init_player(game_t *game)
{
	PLAYER_NAME = NULL;
	PLAYER_CHARACTER = NULL;
	PLAYER_HEALTH = 0;
	PLAYER_MAX_HP = 0;
	PLAYER_ARMOR = 0;
	PLAYER_LEVEL = 0;
	PLAYER_SPECIALITY = 0;
	PLAYER_SPECIALITY_NAME = NULL;
}