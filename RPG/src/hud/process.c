/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

sfVector2f vec2u_to_vec2f(sfVector2u vecu)
{
	sfVector2f vecf;

	vecf.x = (float)vecu.x;
	vecf.y = (float)vecu.y;
	return (vecf);
}

int click_button(obj_t *button, sfVector2i clickPosition, sfMouseButton mb)
{
	return (clickPosition.x <
	sfRectangleShape_getPosition(button->obj).x +
	sfRectangleShape_getSize(button->obj).x &&
	clickPosition.x > sfRectangleShape_getPosition(button->obj).x &&
	clickPosition.y < sfRectangleShape_getPosition(button->obj).y +
	sfRectangleShape_getSize(button->obj).y &&
	clickPosition.y > sfRectangleShape_getPosition(button->obj).y
	&& sfMouse_isButtonPressed(mb));

}

int button_fly_over(obj_t *button, sfVector2i clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button->obj).x +
	sfRectangleShape_getSize(button->obj).x &&
	clickPosition.x > sfRectangleShape_getPosition(button->obj).x &&
	clickPosition.y < sfRectangleShape_getPosition(button->obj).y +
	sfRectangleShape_getSize(button->obj).y &&
	clickPosition.y > sfRectangleShape_getPosition(button->obj).y);
}

int process_button_over(bucket_t *button_bucket, window_t *window, game_t *game)
{
	obj_t *button = button_bucket->value;

	if (button->button != sfTrue)
		return (0);
	if (button_fly_over(button, MOUSE_POS) == 1 &&
	click_button((button), MOUSE_POS, sfMouseLeft) == 0) {
		sfRectangleShape_setFillColor(button->obj, OVER_COLOR);
	} else if (button_fly_over(button, MOUSE_POS) == 1 &&
	click_button((button), MOUSE_POS, sfMouseLeft) == 1
	&& CLICK_RELEASED == sfTrue) {
		CLICK_RELEASED = sfFalse;
		make_sound("SELECT_SOUND", game);
		return (button->callback ? button->callback(window, game) : 84);
	} else if (!game->movement.is_moving
	&& sfRectangleShape_getFillColor(button->obj).a == 255)
		sfRectangleShape_setFillColor(button->obj, REGULAR_COLOR);
	return (0);
}

int manage_buttons(managed_scene_t *scene, window_t *window, game_t *game)
{
	if (!scene || !window || !game)
		return (84);
	return (read_hashmap(window, game, scene->scene->objs,
		&process_button_over));
}
