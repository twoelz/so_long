/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:48:33 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 14:18:46 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_enemy_to_coordinates(t_game_data *g, t_bonus *b, int x, int y)
{
	if (b->total_enemies + 1 >= 500)
		return (warning_too_many_enemies());
	if (b->enemy[b->total_enemies].x != PREVIOUSLY_PLACED_ENEMY)
		tile_win(g, b->enemy_sprite, x * g->tilesiz, y * g->tilesiz);
	b->enemy[b->total_enemies].x = x;
	b->enemy[b->total_enemies].y = y;
	b->enemy_sprite->instances[b->total_enemies].enabled = true;
	mlx_set_instance_depth(&b->enemy_sprite->instances[b->total_enemies],
		Z_ENEMY);
	b->total_enemies++;
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
