/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:26:26 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 13:43:48 by tda-roch         ###   ########.fr       */
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

void	place_enemy_to_free_spot(t_game_data *g, t_bonus *b, size_t	spot)
{
	t_point	p;
	char	c;
	size_t	current_spot;

	ft_bzero(&p, sizeof(p));
	current_spot = 0;
	while (p.y < g->height)
	{
		c = g->ber[p.y][p.x];
		if (!((c != '0') || (p.x == g->player.x && p.y == g->player.y) || \
				enemy_in_point(b, p)))
		{
			if (current_spot == spot)
				return (add_enemy_to_coordinates(g, b, p.x, p.y));
			current_spot++;
		}
		next_point(&p, g->width);
	}
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

void	place_random_enemy(t_game_data *g)
{
	t_bonus		*b;
	size_t		spots;
	size_t		spot;

	b = (t_bonus *)g->bonus;
	spots = count_enemy_free_spots(g, b);
	if (spots == 0)
		return (warning_too_many_enemies());
	spot = get_random_int(spots, 0);
	place_enemy_to_free_spot(g, b, spot);
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

size_t	count_enemy_free_spots(t_game_data *g, t_bonus *b)
{
	t_point	p;
	char	c;
	size_t	enemy_spots;

	ft_bzero(&p, sizeof(p));
	enemy_spots = 0;
	while (p.y < g->height)
	{
		c = g->ber[p.y][p.x];
		if (!((c != '0') || (p.x == g->player.x && p.y == g->player.y) || \
				enemy_in_point(b, p)))
			enemy_spots++;
		next_point(&p, g->width);
	}
	return (enemy_spots);
}

