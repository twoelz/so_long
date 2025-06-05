/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:56:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/05 12:12:21 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_loop_bonus(void *param)
{
	t_game_data	*g;
	t_bonus		*b;

	g = (t_game_data *)param;
	b = (t_bonus *)g->bonus;
	b->mlx_time = mlx_get_time();
	if (b->remove_collect)
		loop_remove_collect(g, b);
	if (b->remove_exit)
		adjust_remove_exit(g, b);
	if (b->mlx_time - b->animate_space_time > SPACE_ANIMATION_SPEED)
		animate_space(g, b);
}

void	loop_remove_collect(t_game_data *g, t_bonus	*b)
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
			adjust_remove_collect(g, b, i);
		}
		i++;
	}
	if (removed)
		b->remove_collect = false;
}

void	adjust_remove_exit(t_game_data *g, t_bonus *b)
{
	int		size;
	double	elapsed;

	elapsed = b->mlx_time - g->game_over_time;
	size = g->tilesiz;
	if (elapsed >= 1.2)
	{
		b->remove_exit = false;
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
		b->exit_point.x + (g->tilesiz - size) / 2, \
		b->exit_point.y + (g->tilesiz - size) / 2);
}

void	adjust_remove_collect(t_game_data *g, t_bonus *b, size_t i)
{
	int		size;
	double	elapsed;

	elapsed = b->mlx_time - b->remove_collect_time[i];
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
		b->collect_point[i].x + (g->tilesiz - size) / 2, \
		b->collect_point[i].y + (g->tilesiz - size) / 2);
	mlx_set_instance_depth(&g->tile.collect[i]->instances[0], Z_REMOVE);
}

void	animate_space(t_game_data *g, t_bonus *b)
{
	b->animate_space_time = b->mlx_time;
	if (g->tile.space->enabled)
	{
		g->tile.space->enabled = false;
		b->space_1->enabled = true;
	}
	else if (b->space_1->enabled)
	{
		b->space_1->enabled = false;
		b->space_2->enabled = true;
	}
	else if (b->space_2->enabled)
	{
		b->space_2->enabled = false;
		b->space_3->enabled = true;
	}
	else if (b->space_3->enabled)
	{
		b->space_3->enabled = false;
		g->tile.space->enabled = true;
	}
}
