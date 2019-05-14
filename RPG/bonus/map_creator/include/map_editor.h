/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** My world header
*/

#ifndef MAP_EDITOR
#define MAP_EDITOR

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Event.h>
#include "../../../include/my.h"
#include "rpg.h"

typedef sfVector2f v2f;
typedef sfVector2i v2i;
typedef struct texture_list_s texture_list_t;

typedef struct texture_list_s {
	char *name;
	sfRectangleShape *rec;
	sfTexture *texture;
	sfVector2f pos;
	texture_list_t *next;
} texture_list_t;

typedef struct ressources_s {
	sfRenderWindow *window;
	sfTexture *selected;
	char *selected_texture_name;
	int mode;
	my_w_t *rsces;
} ressources_t;

my_w_t init_ressource_window(sfRenderWindow *);
void on_event(ressources_t *, texture_list_t *, sfEvent, sfClock *);
v2i area_selector(void);
int seek_zone(my_w_t *, char *);
texture_list_t *read_hashmap_texture(hashmap_t *);
void draw_texture_list(texture_list_t *list, sfRenderWindow *);
void time_animation(obj_t *obj, float seconds, my_w_t *window);
int display_map(my_w_t *window);
int check_invalid_tile_display(tile_list_t *tile, int x, int y, my_w_t *window);
void add_texture_to_list(texture_list_t *list, texture_t *texture);
void add_big_texture_to_list(texture_list_t *list, texture_t *texture);
void left_click_event(ressources_t *rsces, texture_list_t *list);
void right_click_event(ressources_t *rsces, texture_list_t *list);
int button_is_clicked(sfRectangleShape *rec, v2i clickPosition);
void check_click_for_block(ressources_t *rsces, my_w_t *window, int i, int j);
void save_map(my_w_t *window);
void write_areas(my_w_t *window, int fd);

#endif /* MAP_EDITOR */
