/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** .h
*/

#ifndef MY_H_H
#define MY_H_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

typedef struct t_s {
	sfTexture *duck;
	sfTexture *sight;
	sfTexture *my_background;
	sfTexture *duck_dead;
} t_t;

typedef struct b_s {
	int offset;
	int max_value;
	float a;
	float b;
	float variant;
	float seconds;
	float seconds_s_z;
	int check_duck;
	int stock_ball;
	int click;
	sfFont *font;
	sfText *ammmount_ball;
	sfText *nb_click;
	int check_begin;
	sfMusic *duck;
	sfMusic *wings;
	sfMusic *music;
	sfMusic *gun;
	sfMusic *finish;
	t_t t;
} b_t;

typedef struct s_s {
	sfSprite *background;
	sfSprite *duck_sprite;
	sfSprite *sight_gun;
} s_t;

typedef struct v_s {
	sfVector2f pos_duck;
	sfVector2f pos_sight;
	sfVector2f tmp;
	sfVector2f my_pos_background;
} v_t;

typedef struct d_s {
	sfVideoMode mode;
	sfRenderWindow* window;
	sfEvent event;
	sfVector2i pos_mouse;
	sfMouseButtonEvent mouse;
	sfIntRect rect;
	sfClock *clock;
	sfClock *clock_since_zero;
	sfTime time;
	sfTime time_since_zero;
} d_t;

typedef struct begin_sprite_s {
	sfSprite *sprite_top_arrow;
	sfSprite *sprite_bottom_arrow;
	sfSprite *background;
	sfMusic *bip;
} b_s_t;

typedef struct begin_texture_s {
	sfTexture *arrow_top;
	sfTexture *arrow_b;
	sfTexture *my_backg;
} b_tt_t;

typedef struct begin_text_s {
	sfText *text;
	sfText *option_normal;
	sfText *option_survival;
} b_t_t;

typedef struct f_t_s {
	sfText *text;
	sfText *time_since_begin;
	sfText *my_time;
	sfText *stock_result;
	sfText *count_kill;
	sfText *info;
	sfText *remains;
	sfText *remains_count;
	sfText *info_2;
	float a;
} f_t_t ;

typedef struct f_tt_s {
	sfTexture *texture_yes;
	sfTexture *texture_no;
	sfTexture *my_background;
} f_tt_t;

typedef struct f_s_s {
	sfSprite *background;
	sfSprite *sprite_yes;
	sfSprite *sprite_no;
} f_s_t;

typedef struct fw_t_s {
	sfText *text;
	sfText *time_since_begin;
	sfText *my_time;
	sfText *stock_result;
	sfText *count_kill;
	sfText *info;
	sfText *info_2;
	float a;
} fw_t_t;

typedef struct fw_tt_s {
	sfTexture *texture_yes;
	sfTexture *texture_no;
	sfTexture *my_background;
} fw_tt_t;

typedef struct fw_s_s {
	sfSprite *sprite_yes;
	sfSprite *sprite_no;
	sfSprite *background;
} fw_s_t;

void fill_var(b_t *);
void fill_sprite(s_t *);
void fill_vector(v_t *);
void fill_divers(d_t *);
void fill_sprite_texture(s_t *, b_t *);
void show_new_window(d_t *, s_t *);
void draw_display(d_t *, s_t *, b_t *);
void new_position_duck(v_t *, b_t *, float, s_t *);
void position_cible(d_t *, v_t *, s_t *);
void poll_event(d_t *, v_t *, b_t *);
int manage_mouse_click(sfRenderWindow *, v_t *);
void time_clock(d_t *, b_t *, int);
void move_rect(sfIntRect *, b_t *);
void check_my_amazing_duck(b_t *, d_t *, s_t *, v_t *);
void check_if_win(b_t *var, d_t *);
double my_rand(double, double);
char* my_itoa(int, char *b);
float menu(sfRenderWindow *, b_t *, int);
int main(int, char *argv[]);
int menu_begin(sfRenderWindow *);
void display_window_begin(sfRenderWindow *, int, b_t_t *, b_s_t *);
void init_begin(b_s_t *, b_t_t *, b_tt_t *);
void init_sprite(b_s_t *);
void init_texture(b_tt_t *);
void init_begin_text(b_t_t *);
void fill_object(b_t_t *, sfFont *);
void set_string_font(f_t_t *, sfFont *);
void init_text_over(sfFont *, f_t_t *);
void draw_next(sfRenderWindow *, f_s_t *, f_t_t *);
void show_yes_or_no(sfRenderWindow *, f_s_t *, f_t_t *);
void display_window_finish_over(sfRenderWindow *, f_t_t *, f_s_t *, b_t *);
void fill_text(f_t_t *);
void fill_texture(f_tt_t *);
void fill_sprite_menu(f_s_t *);
void fill_all_elem_menu(f_s_t *, f_tt_t *);
void fill_elem_menu(f_t_t *, f_tt_t *, f_s_t *);
void show_yes_or_no_win(sfRenderWindow *, fw_s_t *, fw_t_t *);
void draw_next_win(sfRenderWindow *, fw_s_t *, fw_t_t *);
void display_window_finish_w(sfRenderWindow *, b_t *, fw_s_t *, fw_t_t *);
void set_string_font_win(sfFont *, fw_t_t *);
void init_text_win(sfFont *, fw_t_t *, fw_s_t *, fw_tt_t *);
void fill_text_win(fw_t_t *);
void fill_texture_win(fw_tt_t *);
void fill_sprite_win(fw_s_t *);
void fill_win_elem(fw_t_t *, fw_tt_t *, fw_s_t *);
void normal_game(b_t *, s_t *, v_t *, d_t *);
void clock_time_beginning(d_t *, b_t *);
void survival_game(b_t *, s_t *, v_t *, d_t *);
void func_run_or_dont_touch_surv(b_t *, s_t *, d_t *, v_t *);
void duck_pos_sprite_texture_surv(s_t *, v_t *, b_t *);
void check_my_amazing_duck_surv(b_t *, d_t *, s_t *, v_t *);
void check_if_win_surv(b_t *, d_t *, int);
void usage_func(char **, int);
#endif
