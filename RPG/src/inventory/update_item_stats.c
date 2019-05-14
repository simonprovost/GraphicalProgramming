/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

int update_health_item(slot_t *slot, game_t *game)
{
	scene_t *stats_scene = hm_get(game->scenes, "STATS");
	bucket_t *bucket_texts = NULL;

	if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	|| !slot->item)
		return (84);

	if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "HEALTH_ITEM")))
		return (84);
	sfText_setString(bucket_texts->value, my_strcat(
		"Health: ", int_to_str(slot->item->stats.health)));
	return (0);
}

int update_armor_item(slot_t *slot, game_t *game)
{
		scene_t *stats_scene = hm_get(game->scenes, "STATS");
	bucket_t *bucket_texts = NULL;

	if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	|| !slot->item)
		return (84);

	if (!(bucket_texts = hm_get_bucket(stats_scene->texts, "ARMOR_ITEM")))
		return (84);
	sfText_setString(bucket_texts->value, my_strcat(
		"Armor: ", int_to_str(slot->item->stats.armor)));
	return (0);
}

int update_special_item(slot_t *slot, game_t *game)
{
		scene_t *stats_scene = hm_get(game->scenes, "STATS");
	bucket_t *bucket_texts = NULL;

	if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	|| !slot->item)
		return (84);

	if (!(bucket_texts = hm_get_bucket(stats_scene->texts,
	"SPECIAL_ITEM")))
		return (84);
	sfText_setString(bucket_texts->value
	, my_strcat(my_strcat(PLAYER_SPECIALITY_NAME, ": "),
	int_to_str(slot->item->stats.special)));
	return (0);
}

int update_damages_item(slot_t *slot, game_t *game)
{
	scene_t *stats_scene = hm_get(game->scenes, "STATS");
	bucket_t *bucket_texts = NULL;

	if (!stats_scene || !stats_scene->objs || !stats_scene->texts
	|| !slot->item)
		return (84);

	if (!(bucket_texts = hm_get_bucket(stats_scene->texts,
	"DAMAGES_ITEM")))
		return (84);
	sfText_setString(bucket_texts->value, my_strcat(
		"Damages: ", int_to_str(slot->item->stats.damages)));
	return (0);
}
