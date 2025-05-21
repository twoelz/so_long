/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:56:46 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/21 04:16:15 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_reacheable(t_game_data *g, char **ber, int x, int y)
{
	if (x < 0 || y < 0 || x >= g->width || y >= g->height)
		return ;
	if (ber[y][x] == '1')
		return ;
	ber[y][x] = '1';
	fill_reacheable(g, ber, x + 1, y);
	fill_reacheable(g, ber, x - 1, y);
	fill_reacheable(g, ber, x, y + 1);
	fill_reacheable(g, ber, x, y - 1);
}

void	set_player_coordinates(t_game_data *g)
{
	t_point	p;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		if (g->ber[p.y][p.x] == 'P')
		{
			g->player.x = p.x;
			g->player.y = p.y;
			return ;
		}
		next_point(&p, g->width);
	}
}

int	check_reachable_items(t_game_data *g)
{
	t_map_items	items;
	char		**ber;

	load_ber(g, &ber);
	print_ber(g, &ber);
	fill_reacheable(g, ber, g->player.x, g->player.y);
	count_map_items(g, &items, &ber);
	safe_free_2d_char(&ber);
	if (items.collectibles)
		return (set_error_code(g, E_NO_REACH_COLLECT));
	if (items.exits)
		return (set_error_code(g, E_NO_REACH_EXIT));
	return (g->error_code);
}

int	validate_map_items(t_game_data *g)
{
	count_map_items(g, &g->items, &g->ber);
	if (check_number_of_items(g))
		return (g->error_code);
	set_player_coordinates(g);
	print_player_coordinates(g);
	if (check_reachable_items(g))
		return (g->error_code);
	return (g->error_code);
}

void	count_map_items(t_game_data *g, t_map_items *items, char ***ber)
{
	t_point	p;
	char	item;

	ft_bzero(&p, sizeof(p));
	ft_bzero(items, sizeof(t_map_items));
	while (p.y < g->height)
	{
		item = (*ber)[p.y][p.x];
		if (item == '0')
			items->spaces++;
		if (item == 'C')
			items->collectibles++;
		if (item == 'E')
			items->exits++;
		if (item == 'P')
			items->players++;
		next_point(&p, g->width);
	}
}

int	check_number_of_items(t_game_data *g)
{
	t_map_items	*items;

	items = &g->items;
	if (!items->collectibles)
		return (set_error_code(g, E_NO_COLLECT));
	if (!items->exits)
		return (set_error_code(g, E_NO_EXIT));
	if (!items->players)
		return (set_error_code(g, E_NO_START));
	if (items->exits > 1)
		return (set_error_code(g, E_MULTI_EXIT));
	if (items->players > 1)
		return (set_error_code(g, E_MULTI_START));
	return (g->error_code);
}
