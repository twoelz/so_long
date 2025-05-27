/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:08:22 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 05:43:25 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game_images(t_game_data *g)
{
	png_to_image(g, &g->tile.player, TILE_PLAYER);
	png_to_image(g, &g->tile.wall, TILE_WALL);
	png_to_image(g, &g->tile.space, TILE_SPACE);
	png_to_image(g, &g->tile.collectible, TILE_COLLECTIBLE);
	png_to_image(g, &g->tile.exit_closed, TILE_EXIT_CLOSED);
	png_to_image(g, &g->tile.exit_open, TILE_EXIT_OPEN);
	// mlx_set_instance_depth(g->tile.player->instances, Z_PLAYER);
	// mlx_set_instance_depth(g->tile.wall->instances, Z_WALL);
	// mlx_set_instance_depth(g->tile.space->instances, Z_SPACE);
	// mlx_set_instance_depth(g->tile.collectible->instances, Z_COLLECTIBLE);
	// mlx_set_instance_depth(g->tile.exit_closed->instances, Z_EXIT);
	// mlx_set_instance_depth(g->tile.exit_open->instances, Z_EXIT);
}

void	add_game_tiles(t_game_data *g)
{
	t_point	p;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		add_game_tile(g, p.x, p.y);
		next_point(&p, g->width);
	}
}

void	add_game_tile(t_game_data *g, int x, int y)
{
	char		c;

	c = g->ber[y][x];
	if (g->player.x == x && g->player.y == y)
		c = 'P';
	// ft_printf("adding image of type %c\n", c);
	if (found_in_str(c, "EC0P"))
	{
		if (mlx_image_to_window(g->mlx, g->tile.space, x * TILE, y * TILE) < 0)
			exit_mlx_error(g);
	}
	if (c == '1')
	{
		if (mlx_image_to_window(g->mlx, g->tile.wall, x * TILE, y * TILE) < 0)
			exit_mlx_error(g);
	}
	else if (c == 'E')
	{
		if (mlx_image_to_window(g->mlx, g->tile.exit_closed, \
				x * TILE, y * TILE) < 0)
			exit_mlx_error(g);
	}
	else if (c == 'P')
	{
		if (mlx_image_to_window(g->mlx, g->tile.player, \
				x * TILE, y * TILE) < 0)
			exit_mlx_error(g);
	}
}

void	png_to_image(t_game_data *g, mlx_image_t **image, char *png_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(png_path);
	if (!texture)
		exit_mlx_error(g);
	*image = mlx_texture_to_image(g->mlx, texture);
	if (!image)
		exit_mlx_error(g);
	mlx_delete_texture(texture);
}
