/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:45:41 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 14:46:36 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_game_tile_bonus(t_game_data *g, int x, int y, char c)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;
	if (found_in_str(c, NON_WALL_CHARS))
		add_space_to_coordinates(g, b, x, y);
	if (found_in_str(c, ENEMY_CHARS))
	{
		add_enemy_to_coordinates(g, b, x, y);
		g->ber[y][x] = '0';
	}
}

void	add_space_to_coordinates(t_game_data *g, t_bonus *b, int x, int y)
{
	tile_win(g, b->space_1, x * g->tilesiz, y * g->tilesiz);
	tile_win(g, b->space_2, x * g->tilesiz, y * g->tilesiz);
	tile_win(g, b->space_3, x * g->tilesiz, y * g->tilesiz);
}

void	load_game_images_bonus(t_game_data *g)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;
	png_to_tile(g, &b->space_1, TILE_SPACE_1);
	png_to_tile(g, &b->space_2, TILE_SPACE_2);
	png_to_tile(g, &b->space_3, TILE_SPACE_3);
	png_to_tile(g, &b->enemy_sprite, TILE_ENEMY);
	png_to_image(g, &b->win_overlay, OVERLAY_WIN);
	png_to_image(g, &b->loose_overlay, OVERLAY_LOOSE);
	add_win_loose_overlays(g, b);
}

void	z_position_tiles_bonus(t_game_data *g)
{
	t_bonus	*b;
	size_t	i;

	b = (t_bonus *)g->bonus;
	i = 0;
	while (i < b->space_1->count)
		mlx_set_instance_depth(&b->space_1->instances[i++], Z_SPACE);
	i = 0;
	while (i < b->space_2->count)
		mlx_set_instance_depth(&b->space_2->instances[i++], Z_SPACE);
	i = 0;
	while (i < b->space_3->count)
		mlx_set_instance_depth(&b->space_3->instances[i++], Z_SPACE);
	i = 0;
	while (i < b->enemy_sprite->count)
		mlx_set_instance_depth(&b->enemy_sprite->instances[i++], Z_ENEMY);
	if (b->text_image && b->text_image->count > 0)
		mlx_set_instance_depth(&b->text_image->instances[0], Z_MESSAGES);
	b->space_1->enabled = false;
	b->space_2->enabled = false;
	b->space_3->enabled = false;
}
