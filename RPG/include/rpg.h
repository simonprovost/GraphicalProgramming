/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPG_H_
#define RPG_H_
#include "hashify.h"
#include "llist.h"

///////////////////////////////// INIT DEFINES //////////////////////////////

/// METTRE UN GNL QUI MARCHE POUR SUPPRIMER CA :
#define END_OF_FILE "### END OF FILE ###"

#define INIT_CHAR "-" /// String to put in the begining of the line
			///to indicate that lines below are init informations.
#define TEXT_SEPARATOR_CHAR '_' /// Char used to link words in text string
			///init. Get replaced with spaces.
#define KEYWORD_SEPARATOR_CHAR '=' /// Char used to separate KEYWORD and data.
#define DATASET_SEPARATOR_CHAR ' ' /// Char used to separate KEYWORDS from
			///each other or datas from each other.
#define STARTING_SCENE_NAME "MAIN_MENU" /// Name of the starting scene in a
			///string. Will be displayed at the begining of the game
#define MAP_SCENE_NAME "GAME" /// Name of the scene required to display the map
#define GAME_TITLE "Lands Of Valoran"

//////////////////////////////// WINDOW DEFINES //////////////////////////////

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_BITS_PER_PIXEL 32
#define WINDOW_PIXELS_UNIT 50
#define PRIORITY_MAX 4
#define CLOCK_SPEED_MENU 0.01
#define CLOCK_SPEED_GAME 0.1

///////////////////////////////// MAPS DEFINES //////////////////////////////

#define ZONE_TAB_X 5
#define ZONE_TAB_Y 5
#define AREA_TAB_X 3
#define AREA_TAB_Y 3
#define TILE_TAB_X 16
#define TILE_TAB_Y 12

//////////////////////////////// PLAYER DEFINES /////////////////////////////

#define INVENTORY_SIZE_Y 5
#define INVENTORY_SIZE_X 5

///////////////////////////////// GAME DEFINES //////////////////////////////

#define REGULAR_COLOR ((sfColor){255, 255, 255, 255})
#define OVER_COLOR ((sfColor){120, 210, 210, 255})
#define OVER_ITEM_COLOR ((sfColor){255, 100, 100, 255})
#define TRANSPARENCY_COLOR ((sfColor){255, 255, 255, 50})

#define INTRECT(x, y, width, height) (sfIntRect) {x, y, width, height}
#define V2F(x, y) (sfVector2f) {(float) x, (float) y}
#define V2I(x, y) (sfVector2i) {(int) x, (int) y}
#define V2U(x, y) (sfVector2u) {(unsigned int) x, (unsigned int) y}
#define MIN(X, Y) X >= Y ? Y : X
#define MAX(X, Y) X >= Y ? X : Y

//HUD
#define NEW_GAME "NEW_GAME"
#define RESUME_GAME "RESUME"
#define OPTION_GAME "OPTION_GAME"
#define CREDITS_GAME "CREDITS"
#define SAVE_GAME "SAVE"
#define QUIT_GAME "QUIT"
#define QUESTS_GAME "QUESTS"
#define PAUSE_GAME "PAUSE"
#define STATS_GAME "STATS"
#define EXIT_GAME "EXIT"
#define INVENTORY_GAME "INVENTORY"
#define LOAD_GAME "LOAD"
#define MAP_GAME "MAP"
#define HOME "MAIN_MENU"
#define CONTROL_KEY "CONTROL_KEY"
#define S_LOAD "LOADING"
#define VERSION_GAME "V1.0"

//NOTIF MANAGEMENT

#define NOTIF_NULL_ARGS (!game || !notif_output)
#define BATTLE_GAME_NULL_DATA (!battle_game || !battle_game->objs\
|| !battle_game->texts)
#define IS_APRESSED (1 != 1)
#define IS_A_BATTLE (my_strcmp(CURRENT_BUCKET->key, "BATTLE") != 0)

////////////////////////////////// OBJECTS //////////////////////////////

typedef struct obj_data_s obj_data_t;
typedef struct text_data_s text_data_t;

typedef struct obj_s obj_t;

typedef struct particles_s particles_t;

typedef struct rect_s
{
	sfBool animated;
	sfIntRect rect;
	sfVector2i rect_start;
	sfVector2i rect_max;
	sfVector2i rect_offset;
} rect_t;

typedef struct obj_s
{
	int priority;
	int (*callback)();
	sfRectangleShape *obj;
	sfBool button;
	rect_t obj_rect;
} obj_t;

typedef struct texture_s
{
	int priority;
	sfTexture *texture;
	sfBool animated;
	sfIntRect rect;
	sfVector2i rect_start;
	sfVector2i rect_max;
	sfVector2i rect_offset;
} texture_t, texture_data_t;

typedef struct npc_s
{
	char *name;
	char *texture;
	sfVector2i zone;
	sfVector2i area;
	sfVector2i tile;
	char *line_01;
	char *line_02;
	char *line_03;
	char *action;
} npc_t;

/////////////////////////////////// MAPPING /////////////////////////////////

typedef struct vector_pack_s
{
	sfVector2i zone;
	sfVector2i area;
	sfVector2i tile;
} vector_pack_t;

typedef struct tile_list_s tile_list_t;

typedef struct tile_list_s
{
	obj_t *tile;
	tile_list_t *next;
} tile_list_t;

typedef struct tile_s
{
	sfBool block;
	tile_list_t *displayed_tiles;
} tile_t;

typedef struct area_s
{
	char *name;
	sfBool encounter;
	tile_t tiles[TILE_TAB_Y][TILE_TAB_X];
} area_t;

typedef struct zone_s
{
	char *name;
	char *filepath;
} zone_t;

typedef struct map_s
{
	sfVector2i zone_coord;
	sfVector2i area_coord;
	sfVector2i tile_coord;
	zone_t zones[ZONE_TAB_Y][ZONE_TAB_X];
	area_t areas[AREA_TAB_Y][AREA_TAB_X];
} map_t;

//////////////////////////////////////// SCENES ////////////////////////////

typedef struct action_s
{
	char *balise;
	int (*fptr)();
} action_t;

typedef struct manager_s
{
	char *balise;
	int (*fptr)();
	int (*event)();
} manager_t;

typedef enum
{
	BACKGROUNDS = 0,
	PNJS = 1,
	MONSTERS = 2,
	ITEMS = 3,
	BUTTONS = 4,
} objs_type_t;

typedef struct music_s
{
	sfMusic *music;
	sfBool loop;
	sfBool play_music;
} music_t;

typedef struct scene_s
{
	hashmap_t *objs;
	hashmap_t *texts;
	int priority;
	music_t music;
} scene_t;

typedef struct managed_scene_s managed_scene_t;

typedef struct managed_scene_s
{
	scene_t *scene;
	char *name;
	managed_scene_t *next;
} managed_scene_t;

/////////////////////////////// INVENTORY ///////////////////////////////////

typedef struct item_stat_s
{
	int health;
	int armor;
	int special;
	int damages;
} item_stat_t;

typedef struct item_s
{
	char *name;
	obj_t *obj;
	sfBool quest;
	sfBool consumable;
	item_stat_t stats;
} item_t;

typedef struct item_data_s
{
	char *name;
	char *texture;
	sfBool quest;
	sfBool consumable;
	item_stat_t stats;
} item_data_t;

typedef struct slot_s
{
	item_t *item;
	obj_t *slot;
	sfVector2f pos;
} slot_t;

typedef struct inventory_s
{
	int golds;
	item_t *selected;
	slot_t weapon;
	slot_t helmet;
	slot_t chest;
	slot_t gauntlets;
	slot_t pants;
	slot_t items[INVENTORY_SIZE_Y][INVENTORY_SIZE_X];
} inventory_t;

/////////////////////////////////// BATTLE ////////////////////////////////

typedef struct enemy_s {
	char *name;
	char *zone;
	item_stat_t stats;
	obj_t *monster;
} enemy_t;

typedef struct enemy_data_s
{
	char *name;
	char *zone;
	char *texture;
	item_stat_t stats;
} enemy_data_t;

typedef struct battle_s {
	int step_to_battle;
	bool special_hit;
	bool last_enemy_turn;
	bool enemy_turn;
	bool player_turn;
	bool win;
	bool lose;
	bool run_away;
	bool used_special;
	int selected_enemy;
	int nbr_enemies;
	enemy_t *enemy[3];
} battle_t;

/////////////////////////////////// PLAYER ////////////////////////////////

typedef struct stat_s
{
	int health;
	int max_health;
	int armor;
	int damages;
	int xp;
	int xp_max;
	int level;
	char *speciality_name;
	int speciality;
} stat_t;

typedef struct player_s
{
	char *name;
	obj_t *character;
	stat_t stats;
} player_t;

typedef enum direction_e {
	UP,
	DOWN,
	LEFT,
	RIGHT
} direction_t;

/////////////////////////////// CONTROLS ///////////////////////////////////

typedef struct key_control_s
{
	sfKeyCode up;
	sfKeyCode down;
	sfKeyCode right;
	sfKeyCode left;
	sfKeyCode arrow_up;
	sfKeyCode arrow_down;
	sfKeyCode arrow_right;
	sfKeyCode arrow_left;
} key_control_t;

/////////////////////////////////// WINDOW ////////////////////////////////

typedef struct ctime_s
{
	sfClock *clock;
	sfTime timer;
	float seconds;
} ctime_t;

typedef struct movement_s
{
	sfVector2i target_tile;
	ctime_t timer;
	int anim_mult;
	bool is_moving;
} movement_t;

typedef struct tool_s
{
	int framerate;
	sfVector2i mouse_pos;
	obj_t *mouse_skin;
	sfVector2f mouse_skin_offset;
	sfBool click_released;
} tool_t;

typedef struct lib_s
{
	hashmap_t *audio;
	hashmap_t *fonts;
	hashmap_t *textures;
	hashmap_t *items;
	hashmap_t *monsters;
	hashmap_t *npcs;
} lib_t;

typedef struct window_s window_t;

typedef struct game_s
{
	map_t map;
	tool_t tools;
	lib_t libraries;
	player_t player;
	battle_t battle;
	movement_t movement;
	inventory_t inventory;
	key_control_t key_player;
	bucket_t *current;
	hashmap_t *scenes;
	managed_scene_t *displayed_scenes;
	particles_t *particles;
	window_t *window;
	bool loading;
} game_t;

typedef struct window_s
{
	sfEvent event;
	sfRenderWindow *window;
	ctime_t clocker;
} window_t;

typedef struct particle_sys_s
{
	char *sys_name;
	sfIntRect spawn_zone;
	int particle_nbr;
	sfVector2f force;
	bool gravity;
	sfTexture *texture;
	bool (*condition)(sfSprite *, game_t *);
	sfSprite **sprite_arr;
	int spawn_density;
	int spawned_particles_nbr;
	int sys_id;
	bool activated;
} particle_sys_t;

typedef struct particles_s
{
	particle_sys_t *rain;
	sfSprite *rain_background;
	particle_sys_t *feet_deject;
	sfSprite *night_color;
} particles_t;

#include "rpginit.h"
#include "rpgdef.h"
#include "rpgfunc.h"
#include "math.h"

#endif /* RPG_H_ */
