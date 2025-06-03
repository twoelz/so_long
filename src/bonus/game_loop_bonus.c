/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:56:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 03:34:41 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	adjust_remove_exit(t_game_data *g)
{
	int		size;
	double	elapsed;

	elapsed = mlx_get_time() - g->game_over_time;
	size = g->tilesiz;
	if (elapsed >= 0.5)
	{
		g->bonus.remove_exit = false;
		g->tile.exit_open->instances[0].enabled = false;
		return ;
	}
	else
	{
		size = (0.5 - elapsed) * size;
		if (size < 9)
			size = 9;
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
	if (elapsed >= 0.5)
	{
		g->tile.collect[i]->instances[0].enabled = false;
		mlx_set_instance_depth(&g->tile.collect[i]->instances[0], \
			Z_COLLECTIBLE);
		return ;
	}
	else
	{
		size = (0.5 - elapsed) * size;
		if (size < 9)
			size = 9;
	}
	mlx_delete_image(g->mlx, g->tile.collect[i]);
	png_to_image(g, &g->tile.collect[i], TILE_COLLECTIBLE);
	mlx_resize_image(g->tile.collect[i], size, size);
	tile_win(g, g->tile.collect[i],
		g->bonus.collect_point[i].x + (g->tilesiz - size) / 2, \
		g->bonus.collect_point[i].y + (g->tilesiz - size) / 2);
	mlx_set_instance_depth(&g->tile.collect[i]->instances[0], Z_REMOVE);
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

void	game_loop_bonus(void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	if (g->bonus.remove_collect)
		loop_remove_collect(g);
	if (g->bonus.remove_exit)
		adjust_remove_exit(g);
}

