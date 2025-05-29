/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_images_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:01:22 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/29 15:31:24 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_game_tiles(t_game_data *g)
{
	t_point	p;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		add_game_tile(g, p.x, p.y);
		next_point(&p, g->width);
	}
	z_position_tiles(g);
	disable_invisible_tiles(g);
}

void	z_position_tiles(t_game_data *g)
{
	size_t	i;

	i = 0;
	while (i < g->tile.space->count)
		mlx_set_instance_depth(&g->tile.space->instances[i++], Z_SPACE);
	i = 0;
	while (i < g->tile.wall->count)
		mlx_set_instance_depth(&g->tile.wall->instances[i++], Z_WALL);
	i = 0;
	while (i < g->tile.collectible->count)
		mlx_set_instance_depth(&g->tile.collectible->instances[i++], \
				Z_COLLECTIBLE);
	mlx_set_instance_depth(&g->tile.exit_closed->instances[0], Z_EXIT);
	mlx_set_instance_depth(&g->tile.exit_open->instances[0], Z_EXIT);
	mlx_set_instance_depth(&g->tile.player_right->instances[0], Z_PLAYER);
	mlx_set_instance_depth(&g->tile.player_left->instances[0], Z_PLAYER);
	mlx_set_instance_depth(&g->tile.player_up_right->instances[0], Z_PLAYER);
	mlx_set_instance_depth(&g->tile.player_up_left->instances[0], Z_PLAYER);
	mlx_set_instance_depth(&g->tile.player_down_right->instances[0], Z_PLAYER);
	mlx_set_instance_depth(&g->tile.player_down_left->instances[0], Z_PLAYER);
}

void	disable_invisible_tiles(t_game_data *g)
{
	g->tile.exit_open->enabled = false;
	g->tile.player_left->enabled = false;
	g->tile.player_up_left->enabled = false;
	g->tile.player_up_right->enabled = false;
	g->tile.player_down_left->enabled = false;
	g->tile.player_down_right->enabled = false;
}

void	add_game_tile(t_game_data *g, int x, int y)
{
	char		c;

	c = g->ber[y][x];
	if (g->player.x == x && g->player.y == y)
		c = 'P';
	if (found_in_str(c, "EC0P"))
		tile_win(g, g->tile.space, x * g->tilesiz, y * g->tilesiz);
	if (c == '1')
		tile_win(g, g->tile.wall, x * g->tilesiz, y * g->tilesiz);
	else if (c == 'E')
	{
		tile_win(g, g->tile.exit_closed, x * g->tilesiz, y * g->tilesiz);
		tile_win(g, g->tile.exit_open, x * g->tilesiz, y * g->tilesiz);
	}
	else if (c == 'C')
		tile_win(g, g->tile.collectible, x * g->tilesiz, y * g->tilesiz);
	else if (c == 'P')
	{
		tile_win(g, g->tile.player_left, x * g->tilesiz, y * g->tilesiz);
		tile_win(g, g->tile.player_right, x * g->tilesiz, y * g->tilesiz);
		tile_win(g, g->tile.player_up_right, x * g->tilesiz, y * g->tilesiz);
		tile_win(g, g->tile.player_up_left, x * g->tilesiz, y * g->tilesiz);
		tile_win(g, g->tile.player_down_right, x * g->tilesiz, y * g->tilesiz);
		tile_win(g, g->tile.player_down_left, x * g->tilesiz, y * g->tilesiz);
	}
}

void	tile_win(t_game_data *g, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(g->mlx, image, x, y) < 0)
		exit_mlx_error(g, false);
}
