/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPGDEF_H_
#define RPGDEF_H_
#include "rpg.h"

/////////////////////////////////// MAIN /////////////////////////////////

#define SCENES game->scenes
#define CURRENT_BUCKET game->current
#define MANAGED_SCENES game->displayed_scenes

//////////////////////////////////// MOVEMENT ///////////////////////////

#define MOVEMENT game->movement

#define TARGET_TILE MOVEMENT.target_tile

/////////////////////////////////// KEY /////////////////////////////////

#define KEY_PLAYER game->key_player

#define KEY_UP KEY_PLAYER.up
#define KEY_DOWN KEY_PLAYER.down
#define KEY_LEFT KEY_PLAYER.left
#define KEY_RIGHT KEY_PLAYER.right

#define ARROW_KEY_UP KEY_PLAYER.arrow_up
#define ARROW_KEY_DOWN KEY_PLAYER.arrow_down
#define ARROW_KEY_LEFT KEY_PLAYER.arrow_left
#define ARROW_KEY_RIGHT KEY_PLAYER.arrow_right

////////////////////////////////////// TOOLS ////////////////////////////

#define TOOLS game->tools
#define FRAMERATE TOOLS.framerate
#define CLICK_RELEASED TOOLS.click_released
#define MOUSE_SKIN TOOLS.mouse_skin
#define MOUSE_SKIN_OFFSET TOOLS.mouse_skin_offset

#define LIBS game->libraries
#define AUDIO_LIB LIBS.audio
#define FONTS_LIB LIBS.fonts
#define TEXTURES_LIB LIBS.textures
#define ITEMS_LIB LIBS.items
#define MONSTERS_LIB LIBS.monsters
#define NPCS_LIB LIBS.npcs

////////////////////////////////// INVENTORY ///////////////////////////////

#define INVENTORY game->inventory
#define GOLDS INVENTORY.golds
#define ITEMS INVENTORY.items
#define WEAPON INVENTORY.weapon
#define HELMET INVENTORY.helmet
#define CHEST INVENTORY.chest
#define GAUNTLETS INVENTORY.gauntlets
#define PANTS INVENTORY.pants

#define ITEM_SELECTED INVENTORY.selected
#define HELMET_POS (sfVector2f){634, 84}
#define CHEST_POS (sfVector2f){634, 129}
#define PANTS_POS (sfVector2f){634, 172}
#define GAUNTLETS_POS (sfVector2f){589, 128}
#define WEAPON_POS (sfVector2f){678, 128}
#define SLOT_POS(x, y) (sfVector2f){563 + 36 * x , 290 + y * 36}

///////////////////////////////// MAP ///////////////////////////////////////

#define MAP game->map

#define ZONE_COOR_X MAP.zone_coord.x
#define ZONE_COOR_Y MAP.zone_coord.y
#define AREA_COOR_X MAP.area_coord.x
#define AREA_COOR_Y MAP.area_coord.y
#define TILE_COOR_X MAP.tile_coord.x
#define TILE_COOR_Y MAP.tile_coord.y

#define ZONE MAP.zones[ZONE_COOR_Y][ZONE_COOR_X]
#define AREA MAP.areas[AREA_COOR_Y][AREA_COOR_X]
#define TILE AREA.tiles[TILE_COOR_Y][TILE_COOR_X]

#define ZONE_NAME ZONE.name
#define ZONE_FILEPATH ZONE.filepath
#define AREA_NAME AREA.name
#define AREA_ENCOUNTER AREA.encounter
#define TILE_LIST TILE.displayed_tiles
#define TILE_BLOCK TILE.block

#define MOUSE_POS game->tools.mouse_pos

////////////////////////////////////// PLAYER //////////////////////////

#define PLAYER game->player
#define PLAYER_NAME PLAYER.name
#define PLAYER_CHARACTER PLAYER.character
#define PLAYER_STATS PLAYER.stats

#define PLAYER_LEVEL PLAYER_STATS.level
#define PLAYER_HEALTH PLAYER_STATS.health
#define PLAYER_MAX_HP PLAYER_STATS.max_health
#define PLAYER_ARMOR PLAYER_STATS.armor
#define PLAYER_SPECIALITY PLAYER_STATS.speciality
#define PLAYER_DAMAGES PLAYER_STATS.damages
#define PLAYER_XP PLAYER_STATS.xp
#define PLAYER_MAX_XP PLAYER_STATS.xp_max
#define PLAYER_SPECIALITY_NAME PLAYER_STATS.speciality_name

////////////////////////////////// BATTLE //////////////////////////////

#define ENEMY game->battle.enemy
#define SELECTED_ENEMY game->battle.enemy[game->battle.selected_enemy]
#define ENEMY_ARMOR SELECTED_ENEMY->stats.armor
#define ENEMY_DAMAGES SELECTED_ENEMY->stats.damages
#define ENEMY_HEALTH SELECTED_ENEMY->stats.health

#define STEP_TO_BATTLE game->battle.step_to_battle
#define SPECIAL_HIT game->battle.special_hit
#define ENEMY_TURN game->battle.enemy_turn
#define PLAYER_TURN game->battle.player_turn
#define LAST_ENEMY_TURN game->battle.last_enemy_turn
#define NBR_ENEMIES game->battle.nbr_enemies
#define PLAYER_POS V2F(TARGET_TILE.x * 50, TARGET_TILE.y * 50)
#define XP_WON int_to_str(compute_xp_won(game))
#define GOLD_WON int_to_str(compute_gold_won(game))

//////////////////////////////// PARTICLES ///////////////////////////

#define PARTICLES game->particles

////////////////////////////////// USED //////////////////////////////

#define MIN(X, Y) X >= Y ? Y : X
#define MAX(X, Y) X >= Y ? X : Y

#endif /* RPGDEF_H_ */