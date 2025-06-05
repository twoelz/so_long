/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:56:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/05 09:44:09 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_loop_bonus(void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	if (g->bonus.remove_collect)
		loop_remove_collect(g);
	if (g->bonus.remove_exit)
		adjust_remove_exit(g);
}

void	loop_remove_collect(t_game_data *g)
{
	size_t	i;
	bool	removed;

	i = 0;
	removed = true;
	while (i < g->item.total_collect)
	{
		if (g->tile.collect[i]->instances[0].z == Z_REMOVE)
		{
			removed = false;
			adjust_remove_collect(g, i);
		}
		i++;
	}
	if (removed)
		g->bonus.remove_collect = false;
}

void	adjust_remove_exit(t_game_data *g)
{
	int		size;
	double	elapsed;

	elapsed = mlx_get_time() - g->game_over_time;
	size = g->tilesiz;
	if (elapsed >= 1.2)
	{
		g->bonus.remove_exit = false;
		g->tile.exit_open->instances[0].enabled = false;
		return ;
	}
	else
	{
		size = (1.3 - (elapsed * 1.5)) * size;
		if (size < 3)
			size = 3;
	}
	mlx_delete_image(g->mlx, g->tile.exit_open);
	png_to_image(g, &g->tile.exit_open, TILE_EXIT_OPEN);
	mlx_resize_image(g->tile.exit_open, size, size);
	tile_win(g, g->tile.exit_open,
		g->bonus.exit_point.x + (g->tilesiz - size) / 2, \
		g->bonus.exit_point.y + (g->tilesiz - size) / 2);
}

void	adjust_remove_collect(t_game_data *g, size_t i)
{
	int		size;
	double	elapsed;

	elapsed = mlx_get_time() - g->bonus.remove_collect_time[i];
	size = g->tilesiz;
	if (elapsed >= 0.66)
	{
		g->tile.collect[i]->instances[0].enabled = false;
		mlx_set_instance_depth(&g->tile.collect[i]->instances[0], \
			Z_COLLECTIBLE);
		return ;
	}
	else
	{
		size = (1.0 - (elapsed * 1.5)) * size;
		if (size < 3)
			size = 3;
	}
	mlx_delete_image(g->mlx, g->tile.collect[i]);
	png_to_image(g, &g->tile.collect[i], TILE_COLLECTIBLE);
	mlx_resize_image(g->tile.collect[i], size, size);
	tile_win(g, g->tile.collect[i],
		g->bonus.collect_point[i].x + (g->tilesiz - size) / 2, \
		g->bonus.collect_point[i].y + (g->tilesiz - size) / 2);
	mlx_set_instance_depth(&g->tile.collect[i]->instances[0], Z_REMOVE);
}
