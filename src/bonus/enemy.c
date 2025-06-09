/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:26:26 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 13:15:58 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_move_permutations(int arr[24][4])
{
	const char	*perm_string;
	int			i;
	int			j;

	perm_string = "213010320321321031022031120301232301312030120132"
		"102313200231231030211230210303122013021332011302";
	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = perm_string[i * 4 + j] - '0';
			j++;
		}
		i++;
	}
}

/*
using coordinates:
	0 = right
	1 = left
	2 = top
	3 = down
*/
void	fill_move_coordinates(t_point arr[4])
{
	arr[0].x = 1;
	arr[0].y = 0;
	arr[1].x = -1;
	arr[1].y = 0;
	arr[2].x = 0;
	arr[2].y = -1;
	arr[3].x = 0;
	arr[3].y = 1;
}

int	get_random_int(int max_value, int offset)
{
	unsigned int	seed;
	int				result;

	seed = (unsigned int)(mlx_get_time() * 1000.0);
	result = ((seed * KNUTH) + offset) % max_value;
	return (result);
}

void	game_lost(t_game_data *g, t_bonus *b)
{
	b->loose_overlay->enabled = true;
	game_over(g);
	ft_putstr(CLEAR_TERMINAL_SEQUENCE);
	ft_putstr(CLEAR_TERMINAL_SEQUENCE);
	ft_putendl(YOU_LOOSE_MSG);
	ft_putendl(GAME_OVER_MSG);
	ft_putendl(AUTO_CLOSE_MSG);
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

void	move_enemy(t_game_data *g, t_bonus *b, size_t enemy_i)
{
	size_t	i;
	int		random_int;
	t_point	place;

	random_int = get_random_int(24, b->enemy[enemy_i].x + \
		b->enemy[enemy_i].y + enemy_i);
	i = 0;
	while (i < 4)
	{
		place.x = b->enemy[enemy_i].x + \
			b->move_coord[b->move_perm[random_int][i]].x;
		place.y = b->enemy[enemy_i].y + \
			b->move_coord[b->move_perm[random_int][i]].y;
		{
			if (place.x >= 0 && place.x < g->width && place.y >= 0 && place.y < g->height && \
				!found_in_str(g->ber[place.y][place.x], "1EC") && \
				(!enemy_in_point(b, place)))
			{
				move_enemy_to_place(g, b, enemy_i, place);
				return ;
			}
		}
		i++;
	}
}

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

