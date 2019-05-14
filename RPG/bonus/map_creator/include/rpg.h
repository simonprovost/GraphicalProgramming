/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPG_H_
#define RPG_H_
#include "hashify.h"

#define END_OF_FILE "### END OF FILE ###"

#define INIT_INDICATOR "-"
#define TEXT_SEPARATOR_CHAR '_'
#define KEYWORD_SEPARATOR_CHAR '='
#define DATASET_SEPARATOR_CHAR ' '
#define STARTING_SCENE_NAME "MENU_PRINCIPAL"
#define MAP_SCENE_NAME "GAME"
#define GAME_TITLE "Lands Of Valoran"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_BITS_PER_PIXEL 32
#define WINDOW_PIXELS_UNIT 50
#define PRIORITY_MAX 4
#define CLOCK_SPEED_MENU 0.01
#define CLOCK_SPEED_GAME 0.1

#define ZONE_TAB_X 4
#define ZONE_TAB_Y 4
#define AREA_TAB_X 3
#define AREA_TAB_Y 3
#define TILE_TAB_X 16
#define TILE_TAB_Y 12

#define INVENTORY_SIZE_Y 7
#define INVENTORY_SIZE_X 5

#define REGULAR_COLOR ((sfColor){255, 255, 255, 255})
#define OVER_COLOR ((sfColor){120, 210, 210, 255})
#define V2F(x, y) (sfVector2f) {(float) x, (float) y}
#define V2I(x, y) (sfVector2i) {(int) x, (int) y}

#define NEW_GAME "NEW_GAME"
#define RESUME_GAME "RESUME"
#define OPTION_GAME "OPTION_GAME"
#define CREDITS_GAME "CREDITS"
#define SAVE_GAME "SAVE"
#define RE_LOAD "RELOAD"
#define QUIT_GAME "QUIT"
#define QUETES_GAME "QUETE"
#define PAUSE_GAME "PAUSE"
#define CARAC_GAME "STATS"
#define EXIT_GAME "EXIT"
#define INVENTORY_GAME "INVENTORY"
#define LOAD_GAME "LOAD"
#define MAP_GAME "MAP"
#define HOME "MENU_PRINCIPAL"

typedef struct obj_data_s obj_data_t;
typedef struct text_data_s text_data_t;

typedef struct obj_s obj_t;

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
	char *name;
	int priority;
	int (*callback)();
	sfRectangleShape *obj;
	sfBool button;
	rect_t obj_rect;
} obj_t;

typedef struct texture_s
{
	int priority;
	char *name;
	sfTexture *texture;
	sfBool animated;
	sfIntRect rect;
	sfVector2i rect_start;
	sfVector2i rect_max;
	sfVector2i rect_offset;
} texture_t;

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


typedef enum
{
	BACKGROUNDS = 0,
	PNJS = 1,
	MONSTERS = 2,
	ITEMS = 3,
	BUTTONS = 4,
} objs_type_t;

typedef struct scene_s {
	hashmap_t *objs;
	hashmap_t *texts;
	sfBool play_music;
	sfMusic *music;
	int priority;
} scene_t;

typedef struct display_list_s display_list_t;

typedef struct display_list_s
{
	scene_t *scene;
	char *scene_name;
	display_list_t *next;
} display_list_t;


typedef enum
{
	MAGE = 0,
	HUNTER = 1,
	WARRIOR = 2,
} player_character_t;

typedef struct characteristic_s
{
	int vitality;
	int armor;
	char *speciality_name;
	int speciality;
} characteristic_t;

typedef struct inventory_s
{
	int golds;
	obj_t inventory_items[INVENTORY_SIZE_Y][INVENTORY_SIZE_X];
} inventory_t;

typedef struct player_s
{
	char *name;
	player_character_t character;
	characteristic_t characteristics;
} player_t;


typedef struct ctime_s
{
	sfClock *clock;
	sfTime timer;
	float seconds;
} ctime_t;

typedef struct my_window_s
{
	int error_no;
	int framerate_game;
	sfVector2i mouse_pos;
	sfEvent event;
	sfRenderWindow *window;
	ctime_t clocker;
	map_t map;
	bucket_t *current;
	hashmap_t *scenes;
	hashmap_t *audio_lib;
	hashmap_t *fonts_lib;
	hashmap_t *textures_lib;
	display_list_t *displayed_scenes;
} my_w_t;

typedef struct key_word_s key_word_t;

typedef struct get_infos_s
{
	char *filepath;
	char *indicator;
	const key_word_t *keys;
	void (*savior)(my_w_t *);
} get_infos_t;

typedef struct key_word_s
{
	char *key_word;
	int nb_sub_keywords;
	int (*fptr)(char **, char **, hashmap_t **, my_w_t *);
	char **args;
} key_word_t;

typedef struct text_infos_s
{
	char **name;
	char **text;
	char **font;
	char **charac_size;
	char **x;
	char **y;
} text_infos_t;

typedef struct obj_infos_s
{
	char **name;
	char **type;
	char **button;
	char **x;
	char **y;
} obj_infos_t;


typedef struct obj_data_s
{
	char *name;
	char *texture;
	sfBool button;
	sfVector2f position;
} obj_data_t;

typedef struct text_data_s
{
	char *name;
	char *text;
	sfFont *font;
	int charac_size;
	sfVector2f position;
} text_data_t;


typedef struct myfunc_s {
	char *balise;
	int (*instruction)();
} myfunc_t;


#define ZONE_COOR_X window->map.zone_coord.x
#define ZONE_COOR_Y window->map.zone_coord.y
#define AREA_COOR_X window->map.area_coord.x
#define AREA_COOR_Y window->map.area_coord.y
#define TILE_COOR_X window->map.tile_coord.x
#define TILE_COOR_Y window->map.tile_coord.y

#define ZONE window->map.zones[ZONE_COOR_Y][ZONE_COOR_X]
#define AREA window->map.areas[AREA_COOR_Y][AREA_COOR_X]
#define TILE AREA.tiles[TILE_COOR_Y][TILE_COOR_X]

#define ZONE_NAME ZONE.name
#define ZONE_FILEPATH ZONE.filepath
#define AREA_NAME AREA.name
#define AREA_ENCOUTER AREA.encounter
#define TILE_LIST TILE.displayed_tiles
#define TILE_BLOCK TILE.block

#define MOUSE_POS window->mouse_pos




my_w_t init_window(void);
int init_scenes(my_w_t *window);
int init_audio_lib(my_w_t *window);
int init_textures_lib(my_w_t *window);
int init_fonts_lib(my_w_t *window);
int init_map(my_w_t *window);
int init_zone(my_w_t *window);
int init_scene_lists(char **infos, my_w_t *window);
int init_buttons(my_w_t *window);
int init_a_text(char **infos, my_w_t *window, hashmap_t *current_list);
int init_an_obj(char **infos, my_w_t *window, hashmap_t *current_list);

int load_my_zone(my_w_t *window);


void list_savior(my_w_t *window);
void map_savior(my_w_t *window);


int analyse_my_project_config_file(my_w_t *window, get_infos_t *infos);
int init_from_pcf(char **infos, my_w_t *window, const key_word_t *keys);


int get_a_scene(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_list(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_an_index(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_an_obj(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_text(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_music(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_an_audio(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_font(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_texture(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_texture_filepath(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_an_animated(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_rect_values(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_rect_max_values(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_rect_max_offset(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_rect_start_values(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_map(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_zone(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_an_area(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_tile(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_tile_texture(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);
int get_a_priority(char **infos, char **type,
				hashmap_t **current_list, my_w_t *window);

int check_unexisting_font(sfFont *font, char *font_name);
int check_unexisting_texture(texture_t *texture, char *texture_name);
int check_unexisting_music(sfMusic *music, char *music_name);
int check_unexisting_zone(char *zone_name);
int check_unexisting_scene(bucket_t *scene, char *asked_scene);


int check_invalid_obj_init(obj_infos_t *obj);
int check_invalid_key_word(char *last_word_used, char **type,
				char **infos, int error_no);
int check_invalid_text_init(text_infos_t *text);
int check_invalid_index(int index);
int check_invalid_file(int fd, char *filename);
int check_invalid_window_init(int error_no);
int check_invalid_animated(sfBool animated);
int check_invalid_zone_coords(char *name, my_w_t *window);
int check_invalid_area_coords(char *name, my_w_t *window);
int check_invalid_tile_coords(char *name, my_w_t *window);
int check_invalid_priority(int priority, char *texture_name);


int check_already_existing_obj(char *obj_name, hashmap_t *current_list);
int check_already_existing_text(char *text_name, hashmap_t *current_list);
int check_already_existing_texture(hashmap_t *hashmap, char *texture_name);
int check_already_existing_audio(sfMusic *audio, char *audio_name);
int check_already_existing_font(sfFont *font, char *font_name);
int check_already_existing_scene(bucket_t *scene, char *scene_name);
int check_already_existing_music(sfMusic *music, char *music_name);
int check_already_existing_zone_name(char *name, my_w_t *window);
int check_already_existing_zone_coords(char *name, my_w_t *window);
int check_already_existing_area_name(char *name, my_w_t *window);
int check_already_existing_area_coords(char *name, my_w_t *window);
int check_already_existing_tile_coords(my_w_t *window);


int check_missing_args_for_key_word(const key_word_t *keys,
				int index, char **args, int j);
int check_missing_sub_keyword(char *keyword, int nb_keyword,
				char **subwords_tab);
int check_missing_or_invalid_sub_keyword(const key_word_t *keys,
				int index, char **subwords_tab);


int check_undefined_scene(bucket_t *scene, char *asked_list);
int check_undefined_list(hashmap_t *current_list, char *obj);
int check_undefined_texture(bucket_t *texture, char *data);
int check_undefined_area(my_w_t *window);
int check_undefined_tile(my_w_t *window);


int check_scene_not_created(bucket_t *scene, char *file, int line, char *asked);
int check_invalid_tile_display(tile_list_t *tile, int x, int y, my_w_t *window);


obj_t *create_obj(obj_data_t *data, my_w_t *window);
display_list_t *create_a_display(char *name, scene_t *scene);
tile_list_t *create_a_tile(char *texture_name, my_w_t *window);


int add_obj_to_list(obj_data_t *data, hashmap_t *list, my_w_t *window);
int add_text_to_list(text_data_t *text, hashmap_t *current_list);
int add_scene_to_display_list(bucket_t *scene, my_w_t *window);
int add_tile_to_list(char *texture, my_w_t *window);


void clean_displayed_scenes(my_w_t *window);
int clean_displayed_scenes_and_add_back(my_w_t *window, char *scene_name);
void clean_displayed_tiles(my_w_t *window);

int manage_buttons(my_w_t *window);


int start_game(my_w_t *window);
int option(my_w_t *window);
int credits(my_w_t *window);
int exit_game(my_w_t *window);
int caracteristique(my_w_t *window);
int credits(my_w_t *window);
int inventory(my_w_t *window);
int load(my_w_t *window);
int map(my_w_t *window);
int new_game(my_w_t *window);
int pause_game(my_w_t *window);
int quetes(my_w_t *window);
int quit(my_w_t *window);
int re_load(my_w_t *window);
int resume(my_w_t *window);
int save(my_w_t *window);
int menu_principale(my_w_t *window);
int manage_song(my_w_t *window);
int frame_rate_more(my_w_t *window);
int frame_rate_less(my_w_t *window);
char *int_to_str(int nb);

void get_time(my_w_t *window);
int game_lobby(my_w_t *window);


int display_scenes(my_w_t *window);
int display_objs(hashmap_t *objs, my_w_t *window);
int display_texts(bucket_t *text_bucket, my_w_t *window);
void time_animation(obj_t *obj, float seconds, my_w_t *window);
int display_map(my_w_t *window);
int read_hashmap(my_w_t *window, hashmap_t *hashmap, int (*fptr)());


void analyse_events(my_w_t *window);


void destroy_and_free(my_w_t *window);
void obj_destroy(obj_t *obj);
void scenes_destroy(scene_t *scene);
void texture_destroy(texture_t *texture);


#endif /* RPG_H_ */
