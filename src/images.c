/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:08:22 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 07:20:38 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game_images(t_game_data *g)
{
	png_to_image(g, &g->tile.space, TILE_SPACE);
	png_to_image(g, &g->tile.collectible, TILE_COLLECTIBLE);
	png_to_image(g, &g->tile.exit_closed, TILE_EXIT_CLOSED);
	png_to_image(g, &g->tile.exit_open, TILE_EXIT_OPEN);
	png_to_image(g, &g->tile.player, TILE_PLAYER);
	png_to_image(g, &g->tile.wall, TILE_WALL);
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

void	add_game_tiles(t_game_data *g)
{
	t_point	p;
	size_t 	i;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		add_game_tile(g, p.x, p.y);
		next_point(&p, g->width);
	}
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
	mlx_set_instance_depth(&g->tile.player->instances[0], Z_PLAYER);
}

void	add_game_tile(t_game_data *g, int x, int y)
{
	char		c;

	c = g->ber[y][x];
	if (g->player.x == x && g->player.y == y)
		c = 'P';
	if (found_in_str(c, "EC0P"))
		try_image_to_window(g, g->tile.space, x * TILE, y * TILE);
	if (c == '1')
		try_image_to_window(g, g->tile.wall, x * TILE, y * TILE);
	else if (c == 'E')
		try_image_to_window(g, g->tile.exit_closed, x * TILE, y * TILE);
	else if (c == 'C')
		try_image_to_window(g, g->tile.collectible, x * TILE, y * TILE);
	else if (c == 'P')
		try_image_to_window(g, g->tile.player, x * TILE, y * TILE);
}

void	try_image_to_window(t_game_data *g, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(g->mlx, image, x, y) < 0)
		exit_mlx_error(g);
}
