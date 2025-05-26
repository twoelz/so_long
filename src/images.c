/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:08:22 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/26 15:07:41 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_all_game_images(t_game_data *g)
{
	png_to_image(g, &g->tile.player, TILE_PLAYER);
	png_to_image(g, &g->tile.wall, TILE_WALL);
	png_to_image(g, &g->tile.space, TILE_SPACE);
	png_to_image(g, &g->tile.collectible, TILE_COLLECTIBLE);
	png_to_image(g, &g->tile.exit_closed, TILE_EXIT_CLOSED);
	png_to_image(g, &g->tile.exit_open, TILE_EXIT_OPEN);
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
