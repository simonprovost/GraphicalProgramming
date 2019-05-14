#include <my_runner.h>
#include <SFML/Graphics/Rect.h>

/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

void begin_if_walk(float *n, float *m, public_class_t *all)
{
	*m = all->my_pers[0]->my_pos.x;
	*n = all->my_pers[0]->my_pos.y;
	if (all->my_pers[0]->my_texture != NULL)
		sfTexture_destroy(all->my_pers[0]->my_texture);
	all->my_pers[0]->my_texture = sfTexture_createFromFile(
		"ressources/player_joyride.png", NULL);
}

void player_walk(public_class_t *all, int check)
{
	float m = 0.0;
	float n = 0.0;

	if (all->my_pers[0]->my_pos.y < 460 && check == 1) {
		all->my_pers[0]->my_pos.y += 4;
		if (all->my_pers[0]->my_pos.y > 458 && check == 1)
			sfMusic_play(all->player->stop_fly);
	} else if (all->my_pers[0]->my_pos.y >= 460 && check == 1){
		begin_if_walk(&n, &m, all);
		sfSprite_setTexture(all->my_pers[0]->my_sprite,
				    all->my_pers[0]->my_texture, sfTrue);
		sfSprite_setPosition(all->my_pers[0]->my_sprite,
				     (sfVector2f){m, n - 110});
		sfSprite_setTextureRect(all->my_pers[0]->my_sprite,
					(sfIntRect){0, 0, (170), 400});
		time_clock(all->csfml_object, all->var, 100000.0);
		sfSprite_setTextureRect(all->my_pers[0]->my_sprite,
					all->csfml_object->rect_player);
		all->my_pers[0]->my_pos.x += 1;
	}
}