/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:38:27 by tda-roch          #+#    #+#             */
/*   Updated: 2026/01/16 18:44:08 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_all_enemies(t_game_data *g)
{
	size_t		enemy_i;
	t_bonus		*b;

	b = (t_bonus *)g->bonus;
	enemy_i = 0;
	while (enemy_i < b->total_enemies)
	{
		move_enemy(g, b, enemy_i);
		enemy_i++;
	}
}

void	move_enemy(t_game_data *g, t_bonus *b, size_t enemy_i)
{
	size_t	i;
	int		random_int;
	t_point	place;

	random_int = get_random_int(24, b->enemy[enemy_i].x
			+ b->enemy[enemy_i].y + enemy_i);
	i = 0;
	while (i < 4)
	{
		place.x = b->enemy[enemy_i].x
			+ b->move_coord[b->move_perm[random_int][i]].x;
		place.y = b->enemy[enemy_i].y
			+ b->move_coord[b->move_perm[random_int][i]].y;
		{
			if (place.x >= 0 && place.x < g->width
				&& place.y >= 0 && place.y < g->height
				&& !found_in_str(g->ber[place.y][place.x], "1EC")
				&& (!enemy_in_point(b, place)))
			{
				move_enemy_to_place(g, b, enemy_i, place);
				return ;
			}
		}
		i++;
	}
}

void	move_enemy_to_place(t_game_data *g, t_bonus *b,
			size_t enemy_i, t_point place)
{
	b->enemy[enemy_i].x = place.x;
	b->enemy[enemy_i].y = place.y;
	b->enemy_sprite->instances[enemy_i].x = place.x * g->tilesiz;
	b->enemy_sprite->instances[enemy_i].y = place.y * g->tilesiz;
	if (place.x == g->player.x && place.y == g->player.y)
		game_lost(g, b);
}
