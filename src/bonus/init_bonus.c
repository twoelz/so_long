/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:34:27 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 02:57:47 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_bonus(t_game_data *g)
{
	g->bonus.remove_collect = ft_calloc(g->item.total_collect + 1,
			sizeof(bool));
	if (!g->bonus.remove_collect)
		return (set_error_code(g, E_ALLOC));
	g->bonus.remove_collect_time = ft_calloc(g->item.total_collect + 1,
			sizeof(double));
	g->bonus.collect_point = ft_calloc(g->item.total_collect + 1,
			sizeof(t_point));
	if (!g->bonus.remove_collect_time)
		return (set_error_code(g, E_ALLOC));
	g->bonus.remove_exit = false;
	return (E_SUCCESS);
}

void	record_item_positions(t_game_data *g)
{
	size_t	i;

	i = 0;
	while (i < g->item.total_collect)
	{
		g->bonus.collect_point[i].x = g->tile.collect[i]->instances[0].x;
		g->bonus.collect_point[i].y = g->tile.collect[i]->instances[0].y;
		i++;
	}
	g->bonus.exit_point.x = g->tile.exit_open->instances[0].x;
	g->bonus.exit_point.y = g->tile.exit_open->instances[0].y;
}
