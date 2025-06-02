/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:56:46 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/02 00:46:08 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_items(t_game_data *g)
{
	count_map_items(g, &g->item, &g->ber);
	if (check_number_of_items(g))
		return (g->error_code);
	set_player_coordinates(g);
	if (check_reachable_items(g))
		return (g->error_code);
	g->ber[g->player.y][g->player.x] = '0';
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
		if (item == 'E')
			items->exits++;
		if (item == 'P')
			items->players++;
		if (item == 'C')
		{
			items->collect++;
			items->total_collect++;
		}

		next_point(&p, g->width);
	}
}

int	check_number_of_items(t_game_data *g)
{
	t_map_items	*items;

	items = &g->item;
	if (!items->collect)
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

int	check_reachable_items(t_game_data *g)
{
	t_map_items	items;
	char		**ber;

	load_ber(g, &ber);
	fill_reachable(g, ber, g->player.x, g->player.y);
	count_map_items(g, &items, &ber);
	safe_free_2d_char(&ber);
	if (items.collect)
		return (set_error_code(g, E_NO_REACH_COLLECT));
	if (items.exits)
		return (set_error_code(g, E_NO_REACH_EXIT));
	return (g->error_code);
}
