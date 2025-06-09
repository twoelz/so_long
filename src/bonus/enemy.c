/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:26:26 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 13:50:35 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	player_hit_enemy(t_game_data *g, t_bonus *b)
{
	size_t	enemy_i;
	int		x;
	int		y;

	enemy_i = 0;
	x = g->player.x;
	y = g->player.y;
	while (enemy_i < b->total_enemies)
	{
		if (b->enemy[enemy_i].x == x && b->enemy[enemy_i].y == y)
			return (true);
		enemy_i++;
	}
	return (false);
}

void	remove_enemy(t_game_data *g)
{
	t_bonus		*b;

	b = (t_bonus *)g->bonus;
	if (!b->total_enemies)
		return ;
	b->total_enemies--;
	mlx_set_instance_depth(&b->enemy_sprite->instances[b->total_enemies],
		Z_HIDDEN);
	b->enemy_sprite->instances[b->total_enemies].enabled = false;
	b->enemy[b->total_enemies].x = PREVIOUSLY_PLACED_ENEMY;
	b->enemy[b->total_enemies].y = PREVIOUSLY_PLACED_ENEMY;
}

bool	enemy_in_point(t_bonus *b, t_point p)
{
	size_t	i;

	i = 0;
	while (i < b->total_enemies)
	{
		if (p.x == b->enemy[i].x && p.y == b->enemy[i].y)
			return (true);
		i++;
	}
	return (false);
}


