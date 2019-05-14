/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_item(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_data_t *item = create_item_data(type[1]);

	if (!item)
		return (84);
	*current_list = ITEMS_LIB;
	if (check_already_existing_item(*current_list, type[1]) != 0)
		return (84);
	hm_add(*current_list, type[1], item);
	CURRENT_BUCKET = hm_get_bucket(*current_list, type[1]);
	(void)infos;
	return (0);
}

int get_item_texture(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_data_t *item;

	if (check_undefined_item(CURRENT_BUCKET, type[0]) != 0)
		return (84);
	item = CURRENT_BUCKET->value;
	if (!item)
		return (84);
	item->texture = my_strdup(type[1]);
	if (!item->texture)
		return (84);
	(void)infos;
	(void)current_list;
	return (0);
}

int is_item_for_quest(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_data_t *item;
	sfBool quest;

	if (check_undefined_item(CURRENT_BUCKET, type[0]) != 0)
		return (84);
	item = CURRENT_BUCKET->value;
	if (!item)
		return (84);
	quest = my_getnbr(type[1]);
	if (check_invalid_quest(quest) != 0)
		return (84);
	item->quest = quest;
	(void)infos;
	(void)current_list;
	return (0);
}

int is_item_consumable(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_data_t *item;
	sfBool consumable;

	if (check_undefined_item(CURRENT_BUCKET, type[0]) != 0)
		return (84);
	item = CURRENT_BUCKET->value;
	if (!item)
		return (84);
	consumable = my_getnbr(type[1]);
	if (check_invalid_consumable(consumable) != 0)
		return (84);
	item->consumable = consumable;
	(void)infos;
	(void)current_list;
	return (0);
}

int get_item_stats(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	item_data_t *item;
	char **hp = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **armor = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **special = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);
	char **damage = my_str_to_word_array(infos[4], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined_item(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	item = CURRENT_BUCKET->value;
	if (!hp || !armor || !special || !damage || !item)
		return (84);
	item->stats = (item_stat_t){my_getnbr(hp[1]), my_getnbr(armor[1]),
		my_getnbr(special[1]), my_getnbr(damage[1])};
	my_destroy_tab(hp);
	my_destroy_tab(armor);
	my_destroy_tab(special);
	my_destroy_tab(damage);
	(void)type;
	(void)current_list;
	return (0);
}
