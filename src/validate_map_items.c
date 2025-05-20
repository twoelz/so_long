/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:56:46 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 22:52:05 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_items(t_game_data *g)
{
	count_map_items(g);
	if (check_missing_items(g))
		return (g->error_code);
	if (check_excessive_items(g))
		return (g->error_code);
	return (g->error_code);
}

void	count_map_items(t_game_data *g)
{
	t_point	p;
	char	item;

	ft_bzero(&p, sizeof(p));
	ft_bzero(&g->items, sizeof(t_map_items));
	while (p.y < g->height)
	{
		item = g->ber[p.y][p.x];
		if (item == '0')
			g->items.spaces++;
		if (item == 'C')
			g->items.collectibles++;
		if (item == 'P')
			g->items.players++;
		if (item == 'E')
			g->items.exits++;
		next_point(&p, g->width);
	}
}

int	check_missing_items(t_game_data *g)
{
	t_map_items	*items;

	items = &g->items;
	if (!items->collectibles)
		return (set_error_code(g, E_NO_COLLECT));
	if (!items->exits)
		return (set_error_code(g, E_NO_EXIT));
	if (!items->players)
		return (set_error_code(g, E_NO_START));
	return (g->error_code);
}

int	check_excessive_items(t_game_data *g)
{
	t_map_items	*items;

	items = &g->items;
	if (items->exits > 1)
		return (set_error_code(g, E_MULTI_EXIT));
	if (items->players > 1)
		return (set_error_code(g, E_MULTI_START));
	return (g->error_code);
}
