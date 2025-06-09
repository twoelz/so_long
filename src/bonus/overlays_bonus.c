/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlays_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:51:51 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 14:52:23 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_win_loose_overlays(t_game_data *g, t_bonus *b)
{
	int		width;
	int		height;

	width = g->width * g->tilesiz;
	height = g->height * g->tilesiz;
	add_resized_overlay(g, b->win_overlay, width, height);
	add_resized_overlay(g, b->loose_overlay, width, height);
}

void	add_resized_overlay(t_game_data *g, mlx_image_t *overlay,
			int width, int height)
{
	double	proportion;

	proportion = fmin((double)width / (double)overlay->width,
			(double)height / (double)overlay->height);
	mlx_resize_image(overlay,
		overlay->width * proportion,
		overlay->height * proportion);
	tile_win(g, overlay, (width - overlay->width) / 2,
		(height - overlay->height) / 2);
	mlx_set_instance_depth(&overlay->instances[0], Z_OVERLAY);
	overlay->enabled = false;
}
