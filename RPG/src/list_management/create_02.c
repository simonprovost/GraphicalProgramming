/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

item_data_t *create_item_data(char *name)
{
	item_data_t *new = malloc(sizeof(item_data_t));

	if (!new)
		return (NULL);
	new->name = my_strdup(name);
	new->texture = NULL;
	new->quest = 0;
	new->consumable = 0;
	new->stats = (item_stat_t){0, 0, 0, 0};
	return (new);
}

texture_t *create_texture(void)
{
	texture_t *new = malloc(sizeof(texture_t));

	if (!new)
		return (NULL);
	new->priority = 0;
	new->texture = 0;
	new->animated = 0;
	new->rect = INTRECT(0, 0, 0, 0);
	new->rect_start = V2I(0, 0);
	new->rect_max = V2I(0, 0);
	new->rect_offset = V2I(0, 0);
	return (new);
}

enemy_data_t *create_enemy_data(char *name)
{
	enemy_data_t *new = malloc(sizeof(enemy_data_t));

	if (!new)
		return (NULL);
	new->name = my_strdup(name);
	new->zone = NULL;
	new->texture = NULL;
	new->stats = (item_stat_t){0, 0, 0, 0};
	return (new);
}

enemy_t *create_enemy(char *name, game_t *game)
{
	enemy_data_t *data = hm_get(MONSTERS_LIB, name);
	enemy_t *new = malloc(sizeof(enemy_t));

	if (!data || !new) {
		my_printf("WARNING: YOU ASKED FOR '%s' MONSTER BUT IT ", name);
		my_printf("DOESN'T EXIST !\n");
		return (NULL);
	}
	new->name = my_strdup(data->name);
	new->zone = my_strdup(data->zone);
	new->monster = create_obj(&(obj_data_t){name, data->texture,
					0, V2F(0, 0)}, game);
	if (!new->name || !new->zone || !new->monster) {
		return (NULL);
	}
	new->stats = data->stats;
	return (new);
}

npc_t *create_npc(char *name, char *texture)
{
	npc_t *new = malloc(sizeof(npc_t));

	if (!new)
		return (NULL);
	new->name = my_strdup(name);
	my_replace_char(new->name, '_', ' ');
	for (int i = my_strlen(new->name) - 1; new->name[i] == ' '; i--)
		new->name[i] = 0;
	new->texture = my_strdup(texture);
	new->zone = V2I(-1, -1);
	new->area = V2I(-1, -1);
	new->tile = V2I(-1, -1);
	new->line_01 = NULL;
	new->line_02 = NULL;
	new->line_03 = NULL;
	new->action = NULL;
	return (new);
}
