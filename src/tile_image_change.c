/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_image_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:21:46 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 15:06:33 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_image_up(t_game_data *g)
{
	g->tile.player_left->instances[0].y -= g->tilesiz;
	g->tile.player_right->instances[0].y -= g->tilesiz;
	g->tile.player_up_right->instances[0].y -= g->tilesiz;
	g->tile.player_up_left->instances[0].y -= g->tilesiz;
	g->tile.player_down_right->instances[0].y -= g->tilesiz;
	g->tile.player_down_left->instances[0].y -= g->tilesiz;
	disable_player_images(g);
	if (g->looking_left)
		g->tile.player_up_left->enabled = true;
	else
		g->tile.player_up_right->enabled = true;
}

void	move_player_image_down(t_game_data *g)
{
	g->tile.player_left->instances[0].y += g->tilesiz;
	g->tile.player_right->instances[0].y += g->tilesiz;
	g->tile.player_up_right->instances[0].y += g->tilesiz;
	g->tile.player_up_left->instances[0].y += g->tilesiz;
	g->tile.player_down_right->instances[0].y += g->tilesiz;
	g->tile.player_down_left->instances[0].y += g->tilesiz;
	disable_player_images(g);
	if (g->looking_left)
		g->tile.player_down_left->enabled = true;
	else
		g->tile.player_down_right->enabled = true;
}

void	move_player_image_left(t_game_data *g)
{
	g->tile.player_left->instances[0].x -= g->tilesiz;
	g->tile.player_right->instances[0].x -= g->tilesiz;
	g->tile.player_up_right->instances[0].x -= g->tilesiz;
	g->tile.player_up_left->instances[0].x -= g->tilesiz;
	g->tile.player_down_right->instances[0].x -= g->tilesiz;
	g->tile.player_down_left->instances[0].x -= g->tilesiz;
	disable_player_images(g);
	g->looking_left = true;
	g->tile.player_left->enabled = true;
}

void	move_player_image_right(t_game_data *g)
{
	g->tile.player_left->instances[0].x += g->tilesiz;
	g->tile.player_right->instances[0].x += g->tilesiz;
	g->tile.player_up_right->instances[0].x += g->tilesiz;
	g->tile.player_up_left->instances[0].x += g->tilesiz;
	g->tile.player_down_right->instances[0].x += g->tilesiz;
	g->tile.player_down_left->instances[0].x += g->tilesiz;
	disable_player_images(g);
	g->looking_left = false;
	g->tile.player_right->enabled = true;
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

void	disable_player_images(t_game_data *g)
{
	g->tile.player_left->enabled = false;
	g->tile.player_right->enabled = false;
	g->tile.player_up_right->enabled = false;
	g->tile.player_up_left->enabled = false;
	g->tile.player_down_right->enabled = false;
	g->tile.player_down_left->enabled = false;
}
