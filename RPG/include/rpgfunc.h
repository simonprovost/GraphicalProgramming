/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPGFUNC_H_
#define RPGFUNC_H_
#include "rpg.h"

///////////////////////////////////// FUNCTIONS ///////////////////////////////

/////////////////////////// ERROR HANDLINGS START FUNCTIONS

int error_handling_args(int ac, char **av, char **env);

/////////////////////////// INTRO

int start_intro(window_t *window);

/////////////////////////// INIT FUNCTIONS

int init_window(window_t *window);
int init_game(game_t *game, window_t *window);
int init_timer(ctime_t *clocker);
void init_player(game_t *game);
int init_scenes(game_t *game);
int init_audio_lib(game_t *game);
int init_textures_lib(game_t *game);
int init_fonts_lib(game_t *game);
int init_items_lib(game_t *game);
int init_map(game_t *game);
void init_zone(game_t *game);
int init_inventory(game_t *game);
int init_scene_lists(char **infos, game_t *game);
int init_buttons(game_t *game);
int init_a_text(char **infos, game_t *game, hashmap_t *current_list);
int init_an_obj(char **infos, game_t *game, hashmap_t *current_list);
int init_monsters_lib(game_t *game);
int init_npcs_lib(game_t *game);
int init_libs(game_t *game);
void place_player(game_t *game);

/// Change ZONE_COOR_X and ZONE_COOR_Y and call load_my_zone to fulfill
///AREA maps with asked zone.
int load_my_zone(game_t *game);

///Unload and free the current zone (ZONE_COOR_X/Y)
void unload_my_zone(game_t *game);

/////////////////////////// SAVIOR TRICK FUNCTIONS

void list_savior(game_t *game);
void map_savior(game_t *game);

/////////////////////////// INIT FROM PROG CONFIG FILE

int analyse_pcf(game_t *game, get_infos_t *infos);
int init_from_pcf(char **infos, game_t *game, const key_word_t *keys);

/////////////////////////// KEY WORDS FUNCTIONS

int get_scene(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_list(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_index(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_obj(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_text(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_music(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int getudio(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_font(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_texture(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_texture_filepath(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int is_texture_animated(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_rect_values(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_rect_max_values(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_rect_max_offset(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_rect_start_values(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_map(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_zone(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_area(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_tile(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_tile_texture(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_priority(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_item(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_item_texture(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int is_item_for_quest(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int is_item_consumable(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_item_stats(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_monster(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_enemy_data_texture(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_monster_zone(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_monster_stats(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc_zone(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc_area(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc_tile(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc_line_01(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc_line_02(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc_line_03(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_npc_action(char **infos, char **type,
				hashmap_t **current_list, game_t *game);

/////////////////////////// INIT WARNING : UNEXISTING

int check_unexisting_font(sfFont *font, char *font_name);
int check_unexisting_texture(texture_t *texture, char *texture_name);
int check_unexisting_music(sfMusic *music, char *music_name);
int check_unexisting_zone(char *zone_name);
int check_unexisting_scene(bucket_t *scene, char *asked_scene);
int check_unexisting_text(bucket_t *text, char *asked_text, char *scene_name);
int check_unexisting_obj(bucket_t *obj, char *asked_obj, char *scene_name);
int check_unexisting_button(int (*callback)(), char *button_name);
int check_unexisting_item(item_t *item, char *name);

/////////////////////////// INIT WARNING : INVALID

int check_invalid_obj_init(obj_infos_t *obj);
int check_invalid_key_word(char *last_word_used, char **type,
				char **infos, int my_errno);
int check_invalid_text_init(text_infos_t *text);
int check_invalid_index(int index);
int check_invalid_file(FILE *file, char *filename);
int check_invalid_window_init(int my_errno);
int check_invalid_animated(sfBool animated);
int check_invalid_zone_coords(char *name, game_t *game);
int check_invalid_area_coords(char *name, game_t *game);
int check_invalid_tile_coords(char *name, game_t *game);
int check_invalid_priority(int priority, char *texture_name);
int check_invalid_consumable(sfBool consumable);
int check_invalid_quest(sfBool quest);

/////////////////////////// INIT WARNING : ALREADY_EXISTING
int check_already_existing(hashmap_t *hashmap, char *data_name, char *pcf_name);
int check_already_existing_obj(char *obj_name, hashmap_t *current_list);
int check_already_existing_text(char *text_name, hashmap_t *current_list);
int check_already_existing_texture(hashmap_t *hashmap, char *texture_name);
int check_already_existing_audio(sfMusic *audio, char *audio_name);
int check_already_existing_font(sfFont *font, char *font_name);
int check_already_existing_scene(bucket_t *scene, char *scene_name);
int check_already_existing_music(sfMusic *music, char *music_name);
int check_already_existing_zone_name(char *name, game_t *game);
int check_already_existing_zone_coords(char *name, game_t *game);
int check_already_existing_area_name(char *name, game_t *game);
int check_already_existing_area_coords(char *name, game_t *game);
int check_already_existing_tile_coords(game_t *game);
int check_already_existing_item(hashmap_t *hashmap, char *item_name);
int check_already_existing_monster(hashmap_t *hashmap, char *monster_name);

/////////////////////////// INIT WARNING : MISSING

int check_missing_args_for_key_word(const key_word_t *keys,
				int index, char **args, int j);
int check_missing_sub_keyword(char *keyword, int nb_keyword,
				char **subwords_tab);
int check_missing_or_invalid_sub_keyword(const key_word_t *keys,
				int index, char **subwords_tab);

/////////////////////////// INIT WARNING : UNDEFINED

int check_undefined(bucket_t *data, char *data_name, char *data_type);
int check_undefined_scene(bucket_t *scene, char *asked_list);
int check_undefined_list(hashmap_t *current_list, char *obj);
int check_undefined_texture(bucket_t *texture, char *data);
int check_undefined_area(game_t *game);
int check_undefined_tile(game_t *game);
int check_undefined_item(bucket_t *item, char *data);
int check_undefined_zone(char *zone_name, game_t *game);
int check_undefined_monster(bucket_t *monster, char *data);

/////////////////////////// IN GAME WARNING

int check_scene_not_created(bucket_t *scene, char *file, int line, char *);
int check_invalid_tile_display(tile_list_t *tile, int x,
				int y, game_t *game);
int check_invalid_map_display(game_t *game);

/////////////////////////// LIST CREATING

///Pass an obj_data and window and return a placed object ready to use.
///return NULL on fail
obj_t *create_obj(obj_data_t *data, game_t *game);

///Pass a scene name and the scene itself return a struct used to display a
///linked list of scenes. return NULL on fail
managed_scene_t *create_display(char *name, scene_t *scene);

///Pass a texture name and window and return a tile_list used to display a
///linked list of tiles. return NULL on fail
tile_list_t *create_tile(char *texture_name, game_t *game);
item_t *create_item(char *name, game_t *game);
item_data_t *create_item_data(char *name);
texture_t *create_texture(void);
enemy_data_t *create_enemy_data(char *name);
enemy_t *create_enemy(char *name, game_t *game);
npc_t *create_npc(char *name, char *texture);

//////////////////////////// LIST ADDING

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_obj_to_list(obj_data_t *data, hashmap_t *list, game_t *game);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_text_to_list(text_data_t *text, hashmap_t *current_list);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_scene_to_display_list(bucket_t *scene, game_t *game);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_tile_to_list(char *texture, game_t *game);

/////////////////////////// LIST READ

///Send window every bucket in a passed hasmap to a passed function pointer.
///Return 0/84 depending on pointer return
int read_hashmap(window_t *window, game_t *game, hashmap_t *hashmap,
				int (*fptr)());

/////////////////////////// LIST GET

///Pass a scene name and the window and return the display node containing
///the asked scene. Return NULL if nothing founded.
managed_scene_t *get_scene_from_displayed(char *asked, game_t *game);

/////////////////////////// LIST REMOVING

///Clean all displayed scenes.
void clean_displayed_scenes(game_t *game);

///Clean all displayed scenes and if the scene name passed is found, let
///it in the list. If not, create and add it. return 0/84
int clean_displayed_scenes_and_add_back(game_t *game, char *scene_name);

///Clean all displayed tiles.
void clean_displayed_tiles(tile_list_t *displayed);

///Clean only the scene with the name passed.
void clean_displayed_scene_name(game_t *game, char *name_scenes);

/////////////////////////// MANAGE BUTTONS

int manage_buttons(managed_scene_t *scene, window_t *window, game_t *game);
int button_display_hide_scene(char *scene_name, void (*update)(),
				game_t *game, char *old_scene);
int update_button(char *seek, char *replacement, scene_t *scene,
				game_t *game);

/////////////////////////// BUTTONS FUNCTIONS

int start_game(window_t *window, game_t *game);
int option(window_t *window, game_t *game);
int how_to_play(window_t *window, game_t *game);
int credits(window_t *window, game_t *game);
int exit_game(window_t *window, game_t *game);
int stats(window_t *window, game_t *game);
int credits(window_t *window, game_t *game);
int inventory(window_t *window, game_t *game);
int load(window_t *window, game_t *game);
int map(window_t *window, game_t *game);
int new_game(window_t *window, game_t *game);
int pause_game(window_t *window, game_t *game);
int quetes(window_t *window, game_t *game);
int quit(window_t *window, game_t *game);
int reload(window_t *window, game_t *game);
int resume(window_t *window, game_t *game);
int save(window_t *window, game_t *game);
int main_menu(window_t *window, game_t *game);
int manage_song(window_t *window, game_t *game);
int frame_rate_more(window_t *window, game_t *game);
int frame_rate_less(window_t *window, game_t *game);
int select_varyan(window_t *window, game_t *game);
int select_jaina(window_t *window, game_t *game);
int select_avelus(window_t *window, game_t *game);
int control_key(window_t *window, game_t *game);
int key_french(window_t *window, game_t *game);
int key_english(window_t *window, game_t *game);
int no_save(window_t *window, game_t *game);
int yes_save(window_t *window, game_t *game);
int launch_game(window_t *window, game_t *game);
int slot(window_t *window, game_t *game);
int helmet_slot(window_t *window, game_t *game);
int chest_slot(window_t *window, game_t *game);
int gauntlets_slot(window_t *window, game_t *game);
int pants_slot(window_t *window, game_t *game);
int weapon_slot(window_t *window, game_t *game);
int end_screen_cross(window_t *window, game_t *game);
int lvl_up_cross(window_t *window, game_t *game);
int nothing(window_t *window, game_t *game);

/////////////////////////// HUD FONCTIONS

int set_hud_opacity(bucket_t *bucket, game_t *game);
int manage_hud_opacity(game_t *game);
int manage_life(game_t *game);
int change_area_hud(game_t *game);
int manage_hit_enemy(game_t *game, int enemy, int damages);
int manage_notif_right(game_t *game, char *);
int manage_notif_left(game_t *game, char *);
void move_and_update(sfRectangleShape *notif, sfText *notif_text,
char *notif_output, int offset);
int button_fly_over(obj_t *button, sfVector2i clickPosition);
int click_button(obj_t *button, sfVector2i clickPosition,
sfMouseButton mb);
int buttonisclicked(obj_t *button, sfVector2i clickPosition);
void init_at_default(sfRectangleShape *notif, sfText *notif_text,
int *check_hit, int *offset);

/////////////////////////// GAME FUNCTIONS

int start_game(window_t *window, game_t *game);
int manage_loading_scene(game_t *game, window_t *window, char *new_scene);
int manage_text(game_t *game, window_t *window, scene_t *s_load);

///Pass window, fulfill the timer struct in it.
void get_time(ctime_t *clocker);

///Main game function. return 0/84
int process_engine(window_t *window, game_t *game);

int game_lobby(window_t *window, game_t *game);
int battle_lobby(window_t *window, game_t *game);
int start_scene_music(scene_t *scene);
int make_sound(char *sound_name, game_t *game);
int set_npc(bucket_t *npc_bucket, game_t *game);

///Update the 3 stats strings in a given scene with there actual values
///in Window.
void update_stats(scene_t *scene, game_t *game);

/////////////////////////// DISPLAY FUNCTIONS

///Read the linked list of displayed scenes and display there obj and text.
///If the first one is GAME, display map. return (0/84)
int display_scene(managed_scene_t *scene, window_t *window, game_t *game);

///Display passed obj and animate it.
int display_obj(obj_t *obj, window_t *window);

///Read the passed hashmap and if the obj priority match the actual priority,
///send the object to display_obj.
int display_objs(hashmap_t *objs, window_t *window);

///Display a passed text via a bucket (call with read_hashmap)
int display_texts(bucket_t *text_bucket, window_t *window);

///Animate a given objetc every given seconds.
void time_animation(obj_t *obj, float seconds, window_t *window);

///Read and display the map (in function of AREA_COOR_X/Y) in function of
///their priorities
int display_map(window_t *window, game_t *game);

/////////////////////////// INPUT

int analyse_events(window_t *window, game_t *game);
int battle_events(window_t *window, game_t *game);
int game_events(window_t *window, game_t *game);

/////////////////////////// DESTROY FUNCTIONS

void destroy_and_free(window_t *window, game_t *game);
void obj_destroy(obj_t *obj);
void scenes_destroy(scene_t *scene);
void texture_destroy(texture_t *texture);
void item_destroy(item_t *item);
void destroy_managed_scene(managed_scene_t *managed);
void npc_destroy(npc_t *npc);
void monster_destroy(enemy_data_t *monster);
void destroy_libs(game_t *game);
void clocks_destroy(game_t *game, window_t *window);
void map_destroy(game_t *game);

/////////////////////////// PLAYER FUNCTIONS

bool set_player_position(sfVector2i pos_tile, sfVector2i pos_aera,
				sfVector2i pos_zone, game_t *game);
bool move_player_zone(direction_t dir, game_t *game);
bool move_player_area(direction_t dir, game_t *game);
bool move_player(direction_t dir, game_t *game);
int anim_player(game_t *game);
void set_anim_side(game_t *game);
void init_movements(game_t *game);
void smooth_move_player(game_t *game);
void set_initial_player_pos(game_t *game);
void set_waiting_player_rect(game_t *game);
bool is_pressing_controls(game_t *game);
void update_moving_state(game_t *game);
bool is_player_moving(game_t *game);

/////////////////////////// NPCS

int process_npc_dialogue(game_t *game);
int update_random_pnj_dialogue(char *name, game_t *game);
int update_nothing_here(game_t *game);
bucket_t **get_dialogue_hud_texts(game_t *game);
int update_pnj_dialogue(npc_t *npc, game_t *game);
int update_no_place_dialogue(game_t *game);
int update_no_place_dialogue(game_t *game);
int process_npc_action(game_t *game);
int check_action_around(bucket_t *npc_bucket, game_t *game);
int compare_coords(npc_t *npc, game_t *game, int (*fptr)());

///////////////////// ACTIONS

int teleport(char **data_tp, game_t *game);
int heal(char **data_heal, game_t *game);
int give_xp_01(char **data_xp, game_t *game);

/////////////////////////// BATTLE

int check_step_to_battle(game_t *game);
char *found_icon(game_t *game);
void init_battle(game_t *game);
int get_enemy(game_t *game, int nbr);
int start_battle(game_t *game);
int update_element_in_battle(game_t *game);
int display_characters(window_t *window, game_t *game);
int manage_life_in_battle(game_t *game);
int attack(window_t *window, game_t *game);
int change_selected_enemy(game_t *game, int offset);
int select_ennemy(window_t *window, game_t *game);
int first_enemy_available(game_t *game);
void change_arrow_position(game_t *game);
int player_attack(window_t *window, game_t *game);
int enemy_attack(window_t *window, game_t *game);
int display_special_hit_player(window_t *window, game_t *game, char *scene);
int display_special_hit_enemy(window_t *window, game_t *game, char *scene);
int wait_for_enemy_attack(window_t *window, game_t *game, bool wait);
int enemy_turn(window_t *window, game_t *game);
int check_last_enemy(game_t *game, int i);
int first_enemy_available(game_t *game);
int reset_enemy_turn(window_t *window, game_t *game);
int reset_player_turn(window_t *window, game_t *game);
int run_away(window_t *window, game_t *game);
char *compute_loot(game_t *game);
char *get_item_rarity(char *item);
char *get_item_type(char *item);
int battle_end_screen(game_t *game, char *result);
int check_run_away(game_t *game);
int manage_versus_animation(game_t *game);
int use_special(window_t *window, game_t *game);
void clean_battle_scenes(game_t *game);
void lose_tp(game_t *game);
int stop_battle_music(game_t *game);
int init_end_screen(game_t *game, scene_t *scene);
void init_character(game_t *game);
int set_battle(game_t *game);
int set_background(game_t *game, scene_t *scene);
int init_boss_battle(char **data, game_t *game);
void win_tp(game_t *game);

////////////////////////////////// XP

int add_xp_to_player(game_t *game, int xp);

/////////////////////////////////// INVENTORY

int items_foreach(game_t *game, window_t *window, int (*fptr)());
int slots_foreach(game_t *game, int (*fptr)());
int add_new_to_slot(char *name, sfVector2f *pos, slot_t *slot, game_t *game);

int inventory_lobby(window_t *window, game_t *game);

int manage_inventory_buttons(game_t *game);
int click_slot(slot_t *slot, game_t *game);
int display_item_stats(slot_t *slot, game_t *game);
int update_item_info(slot_t *slot, game_t *game);
int update_damages_item(slot_t *slot, game_t *game);
int update_special_item(slot_t *slot, game_t *game);
int update_armor_item(slot_t *slot, game_t *game);
int update_health_item(slot_t *slot, game_t *game);
int add_item(item_t *item, game_t *game);
void update_item_stats(sfBool add, slot_t *slot, game_t *game);

//////////////////////////////// MOUSE

int replace_mouse_skin(obj_t *obj, sfVector2f *offset, game_t *game);
int reset_mouse_skin(game_t *game);
int display_mouse(game_t *game, window_t *window);

/////////////////////////// PARTICLES

particle_sys_t *create_particle_sys(sfIntRect spawn, char *tex_name,
				int particle_nbr, game_t *game);
sfVector2f get_particles_spawn_pos(particle_sys_t *sys);
void init_particle_position(particle_sys_t *sys);
bool default_particle_cond(sfSprite *sprite, game_t *game);
void display_particle_sys(window_t *window, particle_sys_t *sys);
void update_particle_sys(particle_sys_t *sys, game_t *game);
void display_particles(window_t *window, game_t *game);
void free_particle_sys(particle_sys_t *sys);
void remove_particle_sys_by_id(int id);
void remove_particle_sys(particle_sys_t *sys);
particle_sys_t *create_rain_sys(game_t *game);
void remove_end(node_t *last_node, node_t *act_node,
		llist_t *particle_sys_list);
void update_feet_particles(game_t *game);
void rain(game_t *game, window_t *window);
int init_particles(game_t *game);
void init_rain(game_t *game);
int get_rnd(int min, int max);
void check_rain(game_t *game);
particle_sys_t *init_foot_particles(game_t *game);
void reset_feet_particles(game_t *game);
int init_day_night_cycle(game_t *game);
void update_day_night_cycle(game_t *game);

/////////////////////////// QUESTS

int quests(char **action, game_t *game);
int quest_1(game_t *game);
int quest_2(game_t *game);
int quest_3(game_t *game);
int update_quest_scene(char *quest_name, char *instruction, game_t *game);

////////////////////////// SAVE

int save_game(game_t *game);
int load_save(int fd_player, int fd_npc, game_t *game);

/////////////////////////// END

#endif /* RPGFUNC_H_ */