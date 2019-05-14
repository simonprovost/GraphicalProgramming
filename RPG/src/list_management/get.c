/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

managed_scene_t *get_scene_from_displayed(char *asked, game_t *game)
{
	managed_scene_t *tmp = MANAGED_SCENES;

	while (tmp && my_strcmp(tmp->name, asked) == 1)
		tmp = tmp->next;
	return (tmp);
}

void seek_zone_enemy_data(bucket_t *bucket, char *monsters[4], game_t *game)
{
	enemy_data_t *data = bucket->value;
	static int i = 0;

	if (my_strcmp(data->zone, ZONE_NAME) == 1)
		return;
	monsters[i] = data->name;
	i++;
	if (i > 2)
		i = 0;
}

void get_enemy_data(char *monsters[4], game_t *game)
{
	bucket_t *tmp;
	hashmap_t *hashmap = MONSTERS_LIB;

	for (unsigned int i = 0; i != hashmap->size; i++) {
		tmp = hashmap->data[i];
		while (tmp) {
			seek_zone_enemy_data(tmp, monsters, game);
			tmp = tmp->next;
		}
	}
}

int get_enemy(game_t *game, int nbr)
{
	char *monsters[4] = {NULL, NULL, NULL, NULL};

	get_enemy_data(monsters, game);
	ENEMY[0] = create_enemy(monsters[rand() % 3], game);
	if (!ENEMY[0])
		return (84);
	sfRectangleShape_setPosition(ENEMY[0]->monster->obj, V2F(600, 200));
	if (nbr == 2) {
		ENEMY[2] = create_enemy(monsters[rand() % 3], game);
		if (!ENEMY[2])
			return (84);
		sfRectangleShape_setPosition(ENEMY[2]->monster->obj,
		V2F(650, 300));
	}
	return (0);
}