/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_images_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:08:22 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/29 15:31:44 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_game_images(t_game_data *g)
{
	g->tile.initialized = true;
	png_to_image(g, &g->tile.space, TILE_SPACE);
	png_to_image(g, &g->tile.collectible, TILE_COLLECTIBLE);
	png_to_image(g, &g->tile.exit_closed, TILE_EXIT_CLOSED);
	png_to_image(g, &g->tile.exit_open, TILE_EXIT_OPEN);
	png_to_image(g, &g->tile.wall, TILE_WALL);
	png_to_image(g, &g->tile.player_right, TILE_PLAYER_RIGHT);
	png_to_image(g, &g->tile.player_left, TILE_PLAYER_LEFT);
	png_to_image(g, &g->tile.player_up_right, TILE_PLAYER_UP_RIGHT);
	png_to_image(g, &g->tile.player_up_left, TILE_PLAYER_UP_LEFT);
	png_to_image(g, &g->tile.player_down_right, TILE_PLAYER_DOWN_RIGHT);
	png_to_image(g, &g->tile.player_down_left, TILE_PLAYER_DOWN_LEFT);
}

void	png_to_image(t_game_data *g, mlx_image_t **image, char *png_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(png_path);
	if (!texture)
		exit_mlx_error(g, false);
	*image = mlx_texture_to_image(g->mlx, texture);
	if (!image)
		exit_mlx_error(g, false);
	mlx_delete_texture(texture);
	if (TILESIZ != g->tilesiz)
		mlx_resize_image(*image, g->tilesiz, g->tilesiz);
}
