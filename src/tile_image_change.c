/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_image_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:21:46 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/26 22:25:56 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_image_up(t_game_data *g)
{
	g->tile.player->instances[0].y -= TILE;
}

void	move_player_image_down(t_game_data *g)
{
	g->tile.player->instances[0].y += TILE;
}

void	move_player_image_left(t_game_data *g)
{
	g->tile.player->instances[0].x -= TILE;
}

void	move_player_image_right(t_game_data *g)
{
	g->tile.player->instances[0].x += TILE;
}
