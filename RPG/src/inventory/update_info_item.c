/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

char *clean_item_name(char *item_name)
{
	char *str = my_strdup(item_name);
	int len = my_strlen(item_name);

	if (!str)
		return (NULL);
	for (int i = 0; i != len; i++) {
		if (str[i] == '_')
			str[i] = ' ';
		if (CHAR_IS_NUM(str[i]))
			str[i] = 0;
	}
	return (str);
}

int update_name_item(slot_t *slot, game_t *game)
{
	scene_t *stats_scene = hm_get(game->scenes, STATS_GAME);
	bucket_t *bucket_texts = NULL;
	char *tmp = NULL;

	if (!stats_scene || !stats_scene->texts || !slot || !slot->item
	|| !slot->item->name)
		return (84);
	if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "NAME_ITEM")))
		return (84);
	tmp = clean_item_name(slot->item->name);
	sfText_setString(bucket_texts->value, my_strcat(
		"Item: ", tmp));
	free(tmp);
	return (0);
}

int update_quest_item(slot_t *slot, game_t *game)
{
	scene_t *stats_scene = hm_get(game->scenes, "STATS");
	bucket_t *bucket_texts = NULL;

	if (!stats_scene || !stats_scene->texts || !slot || !slot->item)
		return (84);
	if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "QUEST_ITEM")))
		return (84);
	sfText_setString(bucket_texts->value,
	slot->item->quest == false ? "" : "Yes Quest object");
	return (0);
}

int update_consumable_item(slot_t *slot, game_t *game)
{
	scene_t *stats_scene = hm_get(game->scenes, "STATS");
	bucket_t *bucket_texts = NULL;

	if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	|| !slot->item)
		return (84);
	if (!(bucket_texts = hm_get_bucket(stats_scene->texts,
	"CONSUMBALE_ITEM")))
		return (84);
	sfText_setString(bucket_texts->value,
	slot->item->consumable == false ? "" :
	"Yes consumable object");
	return (0);
}

int update_item_info(slot_t *slot, game_t *game)
{
	if (update_name_item(slot, game) != 0
	|| update_quest_item(slot, game) != 0
	|| update_consumable_item(slot, game) != 0
	|| update_health_item(slot, game) != 0
	|| update_armor_item(slot, game) != 0
	|| update_special_item(slot, game) != 0
	|| update_damages_item(slot, game) != 0)
		return (84);
	return (0);
}