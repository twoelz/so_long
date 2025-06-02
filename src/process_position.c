/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:48:26 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/02 02:26:19 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_position(t_game_data *g)
{
	ft_printf("%d moves\n", g->moves);
	if (g->ber[g->player.y][g->player.x] == 'C')
		process_collect(g);
	if (g->print_ber)
		print_updated_ber(g);
	if (g->ber[g->player.y][g->player.x] == 'E' && g->item.collect > 0)
		ft_putendl(EXIT_CLOSED_MSG);
	if (g->ber[g->player.y][g->player.x] == 'E' && g->item.collect <= 0)
		exit_game_reached(g);
}

void	process_collect(t_game_data *g)
{
	size_t	i;

	g->ber[g->player.y][g->player.x] = '0';
	g->item.collect--;
	i = find_collect_instance(g);
	if (IS_BONUS)
	{
		mlx_set_instance_depth(&g->tile.collect[i]->instances[0], \
				Z_REMOVE);
		g->bonus.remove_collect = true;
		g->bonus.remove_collect_time[i] = mlx_get_time();
	}
	else
		g->tile.collect[i]->instances[0].enabled = false;
	g->collected = true;
	if (g->item.collect <= 0)
	{
		g->tile.exit_closed->enabled = false;
		g->tile.exit_open->enabled = true;
	}
}

size_t	find_collect_instance(t_game_data *g)
{
	size_t	i;

	i = 0;
	while (g->tile.collect[i]->instances[0].x != g->player.x * g->tilesiz \
		|| g->tile.collect[i]->instances[0].y != g->player.y * g->tilesiz)
		i++;
	return (i);
}
