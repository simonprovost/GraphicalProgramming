/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "rpg.h"

int get_monster(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	enemy_data_t *monster = create_enemy_data(type[1]);

	if (!monster)
		return (84);
	*current_list = MONSTERS_LIB;
	if (check_already_existing_monster(*current_list, type[1]) != 0)
		return (84);
	hm_add(*current_list, type[1], monster);
	CURRENT_BUCKET = hm_get_bucket(*current_list, type[1]);
	(void)infos;
	return (0);
}

int get_enemy_data_texture(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	enemy_data_t *monster;

	if (check_undefined_monster(CURRENT_BUCKET, type[0]) != 0)
		return (84);
	monster = CURRENT_BUCKET->value;
	if (!monster)
		return (84);
	monster->texture = my_strdup(type[1]);
	if (!monster->texture)
		return (84);
	(void)infos;
	(void)current_list;
	return (0);
}

int get_monster_zone(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	enemy_data_t *monster;

	if (check_undefined_monster(CURRENT_BUCKET, type[0]) != 0)
		return (84);
	monster = CURRENT_BUCKET->value;
	if (!monster)
		return (84);
	if (check_undefined_zone(type[1], game) != 0)
		return (84);
	monster->zone = my_strdup(type[1]);
	(void)infos;
	(void)current_list;
	return (0);
}

int get_monster_stats(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	enemy_data_t *monster;
	char **hp = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **armor = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **damage = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_monster(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	monster = CURRENT_BUCKET->value;
	if (!hp || !armor || !damage || !monster)
		return (84);
	monster->stats = (item_stat_t){my_getnbr(hp[1]), my_getnbr(armor[1]),
					0, my_getnbr(damage[1])};
	my_destroy_tab(hp);
	my_destroy_tab(armor);
	my_destroy_tab(damage);
	(void)type;
	(void)current_list;
	return (0);
}
